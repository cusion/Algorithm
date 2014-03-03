#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 505
#define INF 0x3fffffff
struct Node {
	int id;
	int dist;
	friend bool operator <(Node a, Node b) {
		return a.dist > b.dist;
	}
}nod1, nod2;

int dist[MAX];
int cost[MAX];
bool visit[MAX];
int adj[MAX][MAX];
int way[MAX][MAX];
int waycost[MAX][MAX];
int pre[MAX];

void dijkstra(int src, int dest, int num) {
	for(int i = 0; i < num; ++i) {
		visit[i] = false;
		dist[i] = INF;
		cost[i] = INF;
	}
	dist[src] = 0;
	pre[src] = -1;
	cost[src] = 0;
	nod1.id = src;
	nod1.dist = 0;
	priority_queue <Node> q;
	q.push(nod1);
	
	while (!q.empty()) {
		nod1 = q.top();
		q.pop();
		//if (nod1.id == dest) break;
		if (visit[nod1.id]) continue;
		visit[nod1.id] = true;
		for (int i = 0; i < adj[nod1.id][MAX-1]; ++i) {
			int next = adj[nod1.id][i];
			if (dist[next] > nod1.dist + way[nod1.id][next]) {
				dist[next] = nod1.dist + way[nod1.id][next];
				pre[next] = nod1.id;
				cost[next] = cost[nod1.id] + waycost[nod1.id][next];
				nod2.id = next;
				nod2.dist = dist[next];
				q.push(nod2);
			} else if (dist[next] == dist[nod1.id] + way[nod1.id][next]) {
				if (cost[next] > cost[nod1.id] + waycost[nod1.id][next]) {
					cost[next] = cost[nod1.id] + waycost[nod1.id][next];
					pre[next] = nod1.id;
				}
			}
		}
	}
}

void printWay(int id) {
	if (pre[id] == -1) {
		printf("%d ", id);
		return ;
	}
	printWay(pre[id]);
	printf("%d ", id);
}

int main() {
	int n,m,s,d;
	cin >> n >> m >> s >> d;
	for (int i = 0; i < m; ++i) {
		int a, b, d, c;
		scanf("%d%d%d%d", &a, &b, &d, &c);
		way[a][b] = way[b][a] = d;
		adj[a][adj[a][MAX-1]++] = b;
		adj[b][adj[b][MAX-1]++] = a;
		waycost[a][b] = waycost[b][a] = c;
	}
	dijkstra(s, d, n);
	printWay(d);
	cout << dist[d] << " " << cost[d] << endl;
	return 0;
}
