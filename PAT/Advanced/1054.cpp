#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	unordered_map <int, int> umap;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int tmp;
			scanf("%d", &tmp);
			if (umap.find(tmp) == umap.end()) {
				umap[tmp] = 1;
			} else {
				++umap[tmp];
			}
		}
	}
	
	for (auto it = umap.begin(); it != umap.end(); ++it) {
		if (it->second > m*n/2) {
			cout << it->first << endl;
			break;
		}
	}
	return 0;
}
