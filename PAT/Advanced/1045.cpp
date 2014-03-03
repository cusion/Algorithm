#include <cstdio>
#include <iostream>
using namespace std;

int findMaxLen(int indx, int maxLen[], int fcorder[]) {
	int ret = -1;
	for (int i = indx; i >= 0; --i) {
		if (maxLen[fcorder[i]] > ret) {
			ret = maxLen[fcorder[i]];
		}
	}
	
	return ret;
}

int main() {
	int n, m, l;
	cin >> n;
	cin >> m;
	int fcorder[m];
	int indxmap[205];
	for (int i = 0; i <= n; ++i) {
		indxmap[i] = -1;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &fcorder[i]);
		indxmap[fcorder[i]] = i;
	}
	
	int maxLen[205];
	for (int i = 0; i <= n; ++i) {
		maxLen[i] = 0;
	}
	cin >> l;
	for (int i = 0; i < l; ++i) {
		int color;
		scanf("%d", &color);
		if (indxmap[color] == -1) {
			continue;
		} else {
			int maxBefore = findMaxLen(indxmap[color], maxLen, fcorder);
			maxLen[color] = maxBefore + 1;
			/*puts("=================");
			cout << i << " " << color << " " << maxLen[color] << endl;
			puts("=================");*/
		}
	}
	
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		if (ans < maxLen[fcorder[i]]) {
			ans = maxLen[fcorder[i]];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
