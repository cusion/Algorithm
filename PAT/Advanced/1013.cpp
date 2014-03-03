#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int> > &adj, vector<bool> &visit, int cur) {
	if (visit[cur] == true) {
		return;
	}
	visit[cur] = true;
	for (int i = 0; i < adj[cur].size(); ++i) {
		if (!visit[adj[cur][i]]) {
			dfs(adj, visit, adj[cur][i]);
		}
	}
}

int dfsMethod(vector<vector<int> > &adj, int tmp) {
	vector<bool> visit(adj.size(), false);
	visit[tmp] = true;
	int num = 0;
	for (int i = 1; i < visit.size(); ++i) {
		if (!visit[i]) {
			dfs(adj, visit, i);
			++num;
		}
	}
	
	return num;
}

int father(int x, int fa[]) {
	return fa[x] == x ? x : fa[x] = father(fa[x], fa);
}

void merge(int x, int y, int fa[]) {
	int fx = father(x, fa);
	int fy = father(y, fa);
	if (fx != fy) {
		// stucked here again, noting that when we 
		// merge a tree containing y to a tree containing x,
		// we should merge those tree roots rather attach y
		// to x or to root of x, that is we should not mistake
		// it as fa[y] = x or fa[y] = fx;
		fa[fy] = fx;
	}
}
/*
void printFa(int fa[], int n) {
	puts("**********************");
	for (int i = 1; i < n; ++i) {
		cout << fa[i] << " ";
	}puts("");
	puts("**********************");
}*/
int ufMethod(vector<vector<int> >&adj, int tmp) {
	int fa[adj.size()];
	for (int i = 1; i < adj.size(); ++i) {
		fa[i] = i;
	}
	
	for (int i = 1; i < adj.size(); ++i) {
		if (i == tmp) {
			continue;
		}
		//printFa(fa, adj.size());
		for (int j = 0; j < adj[i].size(); ++j) {
			if (adj[i][j] == tmp) {
				continue;
			}
			merge(i, adj[i][j], fa);
		}
		//printFa(fa, adj.size());
	}
	
	int num = 0;
	for (int i = 1; i < adj.size(); ++i) {
		if (i == tmp) {
			continue;
		}
		//puts("========================");
		//cout << i << " " << fa[i] << endl;
		if (fa[i] == i) {
			++num;
		}
	}
	
	return num;
}

int getCluster(vector<vector<int> > &adj, int tmp) {
	//return dfsMethod(adj, tmp);
	return ufMethod(adj, tmp);
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > adj(n+1);
	for (int i = 0; i < m; ++i) {
		int a,b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int i = 0; i < k; ++i) {
		int tmp;
		scanf("%d", &tmp);
		cout << getCluster(adj, tmp)-1 << endl;
	}
	return 0;
}
