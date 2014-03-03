#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
#define MAX 505
#define INF 1000000000

struct Ed {
	int nodeind;
	int dist;
	//Ed * next;

	bool friend operator < (Ed a, Ed b) {
		return a.dist > b.dist;
	}
}ed[MAX*MAX];

struct Result {
	int pathNum;
	int personNum;
};

int adj[MAX][MAX];
int dist[MAX];
bool visit[MAX];
int person[MAX];
int personNum[MAX];
int pathNum[MAX];
int pre[MAX];

/*void addEd(Ed ** ed, int s, int t, int len) {
	if (ed[s] == NULL) {
		ed[s] = new Ed();
		ed[s]->nodeind = t;
		ed[s]->dist = len;
	} else {
		Ed * pre = ed[s];
		Ed * cur = ed[s]->next;
		while (cur) {
			pre = cur;
			cur = cur->next;
		}
		pre->next = new Ed();
		cur = pre->next;
		cur->nodeind = t;
		cur->dist = len;
		cur->next = NULL;
	}
}*/

void addEd(int adj[][MAX], int &ind, int s, int t, int dist) {
	ed[ind].nodeind = t;
	ed[ind].dist = dist;
	adj[s][adj[s][MAX-1]++] = ind++;

	ed[ind].nodeind = s;
	ed[ind].dist = dist;
	adj[t][adj[t][MAX-1]++] = ind++;
}

Result Dijkstra(int s, int d, int adj[][MAX], bool *visit, int * pre, int * person, int num) {
	for (int i = 0; i < num; ++i) {
		visit[i] = false;
		pre[i] = -1;
		pathNum[i] = 0;
		dist[i] = INF;
		personNum[i] = person[i];
	}

	priority_queue <Ed> q;
	Ed eTmp;
	eTmp.nodeind = s;
	eTmp.dist = 0;
	dist[s] = 0;
	pathNum[s] = 1;

	q.push(eTmp);

	while (!q.empty()) {
		eTmp = q.top();
		q.pop();

		if (eTmp.nodeind == d) break;

		int cur = eTmp.nodeind;
		if (visit[cur]) continue;

		visit[cur] = true;

		for (int i = 0; i < adj[cur][MAX-1]; ++i) {
			int next = ed[adj[cur][i]].nodeind;
			if (dist[next] > eTmp.dist + ed[adj[cur][i]].dist) {
				dist[next] = eTmp.dist + ed[adj[cur][i]].dist;
				Ed pNode;
				pNode.nodeind = next;
				pNode.dist = dist[next];
				pathNum[next] = pathNum[cur];
				pre[next] = cur;
				personNum[next] = person[next] + personNum[cur];

				q.push(pNode);
			} else if (dist[next] == eTmp.dist + ed[adj[cur][i]].dist) {
				pathNum[next] += pathNum[cur];
				if (personNum[next] < personNum[cur] + person[next]) {
					personNum[next] = personNum[cur] + person[next];
					pre[next] = cur;
				}
			}
		}

		/*for (Ed * adj = ed[cur]; adj != NULL; adj = adj->next) {
			if (dist[adj->nodeind] > eTmp.dist + adj->dist) {
				dist[adj->nodeind] = eTmp.dist+ adj->dist;
				Ed pNode;
				pNode.nodeind = adj->nodeind;
				pNode.dist = dist[adj->nodeind];
				pathNum[adj->nodeind] = pathNum[cur];
				pre[adj->nodeind] = cur;
				personNum[adj->nodeind] = person[adj->nodeind] + personNum[cur];

				q.push(pNode);
			} else if (dist[adj->nodeind] == eTmp.dist + adj->dist){
				pathNum[adj->nodeind] += pathNum[cur];
				if (personNum[adj->nodeind] < personNum[cur] + person[adj->nodeind]) {
					personNum[adj->nodeind] = personNum[cur] + person[adj->nodeind];
					pre[adj->nodeind] = cur;
				}
			}
		}*/
		/*puts("============================");
		for (int i = 0; i < num; ++i) {
			printf("%d ", dist[i]);
		}puts("");
		for (int i = 0; i < num; ++i) {
			printf("%d ", pathNum[i]);
		}puts("");
		for (int i = 0; i < num; ++i) {
			printf("%d ", personNum[i]);
		}puts("");
		puts("****************************");*/
	}

	Result res;
	res.pathNum = pathNum[d];
	res.personNum = personNum[d];

	return res;
}

void PrintPath(int * pre, int d, int s) {
	if (pre[d] == -1) {
		printf("%d", s);
		return ;
	}
	PrintPath(pre, pre[d], s);
	printf(" %d", d);
}

int main ()
{
	int n,m,s,d;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &person[i]);
		//ed[i] = NULL;
	}

	int ind = 0;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		addEd(adj, ind, a, b, c);
	}

	Result res = Dijkstra(s, d, adj, visit, pre, person, n);

	printf("%d %d\n", res.pathNum, res.personNum);

	PrintPath(pre, d, s);
	puts("");

	return 0;
}
