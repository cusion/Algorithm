#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3fffffff

struct Node {
	int time;
	int id;
	//int futureUse;
	//int need;
	Node(){}
	Node(int i, int t):time(t), id(i){
		//futureUse = 0;
		//need = 0;
	}
	
	friend bool operator <(Node a, Node b) {
		return a.time > b.time;
	}
	/*friend bool operator <(Node a, Node b) {
		if (a.time > b.time) {
			return true;
		} else if (a.time < b.time) {
			return false;
		} else {
			if (a.need > b.need) {
				return true;
			} else if (a.need < b.need) {
				return false;
			} else {
				if (a.futureUse > b.futureUse) {
					return true;
				} else if (a.futureUse < b.futureUse) {
					return false;
				} else {
					return a.id > b.id;
				}
			}
		}
	}*/
}nod1, nod2;

void dijkstra(vector <vector<Node> > &adj, int src, int Sp, int Cap, int remain[]) {
	bool visit[adj.size()];
	int pre[adj.size()];
	int need[adj.size()];
	int futureUse[adj.size()];
	int minTime[adj.size()];
	
	// initialization
	for (int i = 0; i < adj.size(); ++i) {
		visit[i] = false;
		pre[i] = -1;
		need[i] = Cap - remain[i];
		if (need[i] < 0) {
			need[i] = 0;
		}
		futureUse[i] = remain[i] - Cap;
		if (futureUse[i] < 0) {
			futureUse[i] = 0;
		}
		minTime[i] = INF;
	}
	
	need[src] = 0;
	futureUse[src] = 0;
	minTime[src] = 0;
	nod1.id = src;
	nod1.time = 0;
	//nod1.need = 0;
	//nod1.futureUse = 0;
	priority_queue<Node> q;
	q.push(nod1);
	
	while (!q.empty()) {
		nod1 = q.top();
		q.pop();
		int cur = nod1.id;
		//cout << "test " << cur << endl;
		if (cur == Sp) break;
		if (visit[cur]) {
			continue;
		}
		visit[cur] = true;
		
		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i].id;
			if (visit[next]) continue;
			if (minTime[next] > minTime[cur] + adj[cur][i].time) {
				minTime[next] = minTime[cur] + adj[cur][i].time;
				pre[next] = cur;
				
				if (remain[next] >= Cap) {
					need[next] = need[cur];
					futureUse[next] = futureUse[cur] + remain[next] - Cap;
				} else {
					if (remain[next] + futureUse[cur] < Cap) {
						need[next] = need[cur] + Cap - remain[next] - futureUse[cur];
						futureUse[next] = 0;
					} else {
						need[next] = need[cur];
						futureUse[next] = futureUse[cur] + remain[next] - Cap;
					}
				}
				
				nod2.id = next;
				nod2.time = minTime[next];
				//nod2.futureUse = futureUse[next];
				//nod2.need = need[next];
				q.push(nod2);
				
			} else if (minTime[next] == minTime[cur] + adj[cur][i].time) {
				int tmpNeed, tmpFut;
				if (remain[next] >= Cap) {
					tmpNeed = need[cur];
					tmpFut = futureUse[cur] + remain[next] - Cap;
				} else {
					if (remain[next] + futureUse[cur] < Cap) {
						tmpNeed = need[cur] + Cap - remain[next] - futureUse[cur];
						tmpFut = 0;
					} else {
						tmpNeed = need[cur];
						tmpFut = futureUse[cur] + remain[next] - Cap;
					}
				}
				
				if (tmpNeed < need[next] || (tmpNeed == need[next] && tmpFut < futureUse[next])) {
					need[next] = tmpNeed;
					futureUse[next] = tmpFut;
					pre[next] = cur;
				}
			}
		}
	}
	
	vector <int> path;
	int cur = Sp;
	while (cur != -1) {
		path.push_back(cur);
		cur = pre[cur];
	}
	cout << need[Sp] << " " << path[path.size()-1];
	for (int i = path.size()-2; i >= 0; --i) {
		printf("->%d", path[i]);
	}
	cout << " " << futureUse[Sp] << endl;
	
	return ;
}

bool comp(Node a, Node b) {
	return a.id < b.id;
}

int main() {
	int Cmax, n, Sp, m;
	cin >> Cmax >> n >> Sp >> m;
	int remain[n+1];
	vector<vector<Node> > adj(n+1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &remain[i+1]);
	}
	remain[0] = 0;
	for (int i = 0; i < m; ++i) {
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		adj[a].push_back(Node(b, t));
		adj[b].push_back(Node(a, t));
	}
	/*for (int i = 0; i < n; ++i) {
		sort(adj[i].begin(), adj[i].end(), comp);
	}*/
	/*for (int i = 0; i < adj.size(); ++i) {
		cout << i << " -> ";
		for (int j = 0; j < adj[i].size(); ++j) {
			cout << adj[i][j].id << " " << adj[i][j].time << " -> ";
		}puts("");
	}*/
	dijkstra(adj, 0, Sp, Cmax/2, remain);
	return 0;
}

