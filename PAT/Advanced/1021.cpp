#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void getComponents(int root, vector<vector<int> > &adj, vector<bool> &visit) {
	if (visit[root] == true) {
		return ;
	}
	visit[root] = true;
	for (int i = 0; i < adj[root].size(); ++i) {
		getComponents(adj[root][i], adj, visit);
	}
	return ;
}

int getDepth(int root, vector<vector<int> >&adj, vector<bool> &visit, int dist[]) {
	if (visit[root]) {
		return 0;
	}
	visit[root] = true;
	int rdepth = 0;
	for (int i = 0; i < adj[root].size(); ++i) {
		if (!visit[adj[root][i]]) {
			dist[adj[root][i]] = dist[root] + 1;
		}
		int tmpDepth = getDepth(adj[root][i], adj, visit, dist);
		if (rdepth < tmpDepth)  {
			rdepth = tmpDepth;
		}
	}
	
	return rdepth+1;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int> >adj(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	int comp = 0;
	vector<bool> visit(n, false);
	for (int i = 0; i < n; ++i) {
		if (visit[i] == false) {
			++comp;
			getComponents(i, adj, visit);
		}
	}
	if (comp > 1) {
		cout << "Error: " << comp << " components" << endl;
	} else {
		int dist[n], maxDepth1, maxDepth2;
		dist[0] = 0;
		vector<int> roots;
		for (int i = 0; i < n; ++i) {
			visit[i] = false;
			dist[i] = 0;
		}
		maxDepth1 = getDepth(0, adj, visit, dist);
		
		/*puts("============ test ============");
		cout << maxDepth1 << endl;
		for (int i = 0; i < n; ++i) {
			cout << dist[i] << " ";
		}puts("");
		system("pause");*/
		for (int i = 0; i < n; ++i) {
			if (dist[i] == maxDepth1-1) {
				roots.push_back(i);
			}
		}
		for (int i = 0; i < n; ++i) {
			visit[i] = false;
			dist[i] = 0;
		}
		maxDepth2 = getDepth(roots[0], adj, visit, dist);
		
		/*puts("============ test ============");
		cout << maxDepth2 << endl;
		for (int i = 0; i < n; ++i) {
			cout << dist[i] << " ";
		}puts("");
		system("pause");*/
		
		if (maxDepth2 > maxDepth1) {
			roots.clear();
		}
		for (int i = 0; i < n; ++i) {
			if (dist[i] == maxDepth2-1 || dist[i] == 0) {
				roots.push_back(i);
			}
		}
		sort(roots.begin(), roots.end());
		cout << roots[0]+1 << endl;
		for (int i = 1; i < roots.size(); ++i) {
			if (roots[i] != roots[i-1]) {
				printf("%d\n", roots[i]+1);
			}
		}
		/********** TLE version ************
		int maxDepth = 0;
		vector <int> roots;
		for (int i = 0; i < n; ++i) {
			vector<bool> visit(n, false);
			int depth = getDepth(i, adj, visit);
			//cout << i << " " << depth << endl;
			if (depth > maxDepth) {
				roots.clear();
				roots.push_back(i);
				maxDepth = depth;
			} else if (depth == maxDepth) {
				roots.push_back(i);
			}
		}
		
		for (int i = 0; i < roots.size(); ++i) {
			printf("%d\n", roots[i]+1);
		}*/
	}
	return 0;
}
