#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3fffffff;

struct Node {
	int id;
	int dist;
	friend bool operator <(Node a, Node b) {
		return a.dist > b.dist;
	}
}nod1, nod2;

struct Ans {
	int pathnum;
	int personSum;
};

Ans dijkstra(vector <vector<Node> > &adj, int src, int dest, int personNum[]) {
	int num = adj.size();
	int dist[num];
	bool visit[num];
	int pathnum[num];
	int personSum[num];
	
	// initialization
	for (int i = 0; i < num; ++i) {
		dist[i] = INF;
		visit[i] = false;
		pathnum[i] = 0;
		personSum[i] = 0;
	}
	dist[src] = 0;
	pathnum[src] = 1;
	personSum[src] = personNum[src];
	nod1.dist = 0;
	nod1.id = src;
	priority_queue <Node> q;
	q.push(nod1);
	
	// update
	while (!q.empty()) {
		nod1 = q.top();
		q.pop();
		int cur = nod1.id;
		if (cur == dest) break;
		if (visit[cur]) continue;
		visit[cur] = true;
		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i].id;
			if (dist[next] > dist[cur] + adj[cur][i].dist) {
				dist[next] = dist[cur] + adj[cur][i].dist;
				pathnum[next] = pathnum[cur];
				personSum[next] = personSum[cur] + personNum[next];
				
				nod2.id = next;
				nod2.dist = dist[next];
				q.push(nod2);
			} else if (dist[next] == dist[cur] + adj[cur][i].dist) {
				pathnum[next] += pathnum[cur];
				if (personSum[next] < personSum[cur] + personNum[next]) {
					personSum[next] = personSum[cur] + personNum[next];
				}
			}
		}
	}
	
	Ans ret;
	ret.pathnum = pathnum[dest];
	ret.personSum = personSum[dest];
	
	return ret;
}

int main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	int personNum[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &personNum[i]);
	}
	vector <vector<Node> > adj(n);
	for (int i = 0; i < m; ++i) {
		int a, b, dist;
		scanf("%d%d%d", &a, &b, &dist);
		nod1.id = b;
		nod1.dist = dist;
		adj[a].push_back(nod1);
		
		nod2.id = a;
		nod2.dist = dist;
		adj[b].push_back(nod2);
	}
	
	Ans ret = dijkstra(adj, s, t, personNum);
	
	cout << ret.pathnum << " " << ret.personSum << endl;
	return 0;
}
