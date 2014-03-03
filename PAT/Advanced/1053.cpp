#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 104
int weight[MAX];

bool cmp(const int &a, const int &b) {
	return weight[a] > weight[b];
}

void dfs(vector<vector<int> > &adj, vector<int> &path, int target, int &sum, int nodeId) {
	if (adj[nodeId].empty()) {
		if (sum + weight[nodeId] == target) {
			for (int i = 0; i < path.size(); ++i) {
				printf("%d ", weight[path[i]]);
			}
			printf("%d\n", weight[nodeId]);
		}
		return;
	}
	if (sum + weight[nodeId] >= target) {
		return;
	}
	sum += weight[nodeId];
	path.push_back(nodeId);
	for (int i = 0; i < adj[nodeId].size(); ++i) {
		dfs(adj, path, target, sum, adj[nodeId][i]);
	}
	sum -= weight[nodeId];
	path.pop_back();
}

int main() {
	int N, M, S;
	cin >> N >> M >> S;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &weight[i]);
	}
	vector<vector<int> > adj(N, vector<int>());
	for (int i = 0; i < M; ++i){
		int id, k;
		scanf("%d %d", &id, &k);
		int next;
		for (int j = 0; j < k; ++j) {
			scanf("%d", &next);
			adj[id].push_back(next);
		}
		sort(adj[id].begin(), adj[id].end(), cmp);
		/*for (int j = 0; j < k; ++j) {
			cout << weight[adj[id][j]] << " ";
		}puts("");*/
	}
	vector <int> path;
	int sum = 0;
	dfs(adj, path, S, sum, 0);
	return 0;
}
