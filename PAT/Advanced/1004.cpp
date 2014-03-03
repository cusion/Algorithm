#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int str2num(char str[]) {
	return (str[0]-'0')*10 + str[1]-'0';
}


/*void bfs(vector<vector<int> > &adj, vector<int> &leafNodes) {
	int leafCount = 0;
	
	queue <int> q;
	q.push(1);
	int start = 0;
	int end = 1;
	int nextEnd = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (adj[cur].empty()) {
			++leafCount;
		} else {
			for (int i = 0; i < adj[cur].size(); ++i) {
				q.push(adj[cur][i]);
			}
			nextEnd += adj[cur].size();
		}
		++start;
		if (start == end) {
			leafNodes.push_back(leafCount);
			start = 0;
			end = nextEnd;
			leafCount = 0;
		}
	}
}*/

void dfs(vector<vector<int> > &adj, vector<int> &leafNodes, int cur, int level) {
	if (level >= leafNodes.size()) {
		leafNodes.push_back(0);
	}
	if (adj[cur].empty()) {
		++leafNodes[level];
		return ;
	}
	
	for (int i = 0; i < adj[cur].size(); ++i) {
		dfs(adj, leafNodes, adj[cur][i], level+1);
	}
}

int main() {
	char str[5];
	int n, m;
	cin >> n >> m;
	vector <int> leafNodes;
	vector<vector<int> > adj(n+1);
	
	int cnodes;
	for (int i = 0; i < m; ++i) {
		scanf("%s%d", str, &cnodes);
		int cur = str2num(str);
		for (int j = 0; j < cnodes; ++j) {
			scanf("%s", str);
			adj[cur].push_back(str2num(str));
		}
	}
	
	//bfs(adj, leafNodes);
	dfs(adj, leafNodes, 1, 0);
	
	cout << leafNodes[0];
	for (int i = 1; i < leafNodes.size(); ++i) {
		cout << " " << leafNodes[i];
	}puts("");
	return 0;
}
