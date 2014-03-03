#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

#define NUM 10003
#define MAX 100005
#define INF 0x3fffffff

struct Node {
	int ind;
	int dist;
	
	bool friend operator < (Node a, Node b) {
		return a.dist > b.dist;
	}
} nod[MAX*4];

void add(int adj[][NUM], int s, int t, int &ind) {
	nod[ind].ind = t;
	nod[ind].dist = 1;
	adj[s][adj[s][NUM-1]++] = ind++;

	nod[ind].ind = s;
	nod[ind].dist = 1;
	adj[t][adj[t][NUM-1]++] = ind++;
}

int adj[NUM][NUM];
int dist[NUM];
bool visit[NUM];

void Dijkstra(int adj[][NUM], int *dist, bool *visit, int src, int num) {
	for (int i = 0; i <= num; ++i) {
		visit[i] = false;
		dist[i] = INF;
	}

	priority_queue <Node> q;

	Node nod1;
	nod1.ind = src;
	nod1.dist = 0;
	dist[src] = 0;

	q.push(nod1);

	while (!q.empty()) {
		nod1 = q.top();
		q.pop();

		int cur = nod1.ind;
		if (visit[cur]) continue;

		visit[cur] = true;

		for (int i = 0; i < adj[cur][NUM-1]; ++i) {
			int next = nod[adj[cur][i]].ind;
			if (dist[next] > nod1.dist + nod[adj[cur][i]].dist) {
				dist[next] = nod1.dist + nod[adj[cur][i]].dist;

				Node nod2;
				nod2.ind = next;
				nod2.dist = dist[next];
				q.push(nod2);
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int ind = 0;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(adj, a, b, ind);
	}

	int k;
	scanf("%d", &k);
	bool isConnected = true;
	for (int i = 0; i < k; ++i) {
		int src, sum = 0;
		scanf("%d", &src);
		Dijkstra(adj, dist, visit, src, n);
		for (int j = 1; j <= n; ++j) {
			if (dist[j] == INF) {
				isConnected = false;
				break;
			} else {
				sum += dist[j];
			}
		}
		if (isConnected) {
			printf("Cc(%d)=%.2lf\n", src, 1.0*(n-1)/sum);
		} else {
			printf("Cc(%d)=0.00\n", src);
			break;
		}
	}
	if (!isConnected) {
		for (int i =0; i < k-1; ++i) {
			int src;
			scanf("%d", &src);
			printf("Cc(%d)=0.00\n", src);
		}
	}

	return 0;
}
