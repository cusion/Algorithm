#include <cstdio>
#include <iostream>

using namespace std;
#define MAX 104
#define MAXDISTANCE 100000000

int adj[MAX][MAX];

void Floyd(int adj[][MAX], int num) {
	for (int i = 1; i <= num; ++i) {
		for (int j = 1; j <= num; ++j) {
			for (int k = 1; k <=num; ++k) {
				if (adj[j][k] > adj[j][i] + adj[i][k]) {
					adj[j][k] = adj[j][i] + adj[i][k];
				}
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			adj[i][j] = i==j ? 0:MAXDISTANCE;
		}
	}

	for (int i =0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cin >> adj[a][b];
		adj[b][a] = adj[a][b];
	}

	Floyd(adj, n);

	int sel, maxLen = MAXDISTANCE + 1;
	for (int i = 1; i <= n; ++i) {
		int rowMax = -1;
		for (int j = 1; j <= n; ++j) {
			if (adj[i][j] > rowMax) {
				rowMax = adj[i][j];
			}
		}
		if (rowMax == MAXDISTANCE) {
			puts("0");
			return 0;
		}
		if (rowMax < maxLen) {
			sel = i;
			maxLen = rowMax;
		}
	}

	cout << sel << " " << maxLen << endl;

	return 0;
}
