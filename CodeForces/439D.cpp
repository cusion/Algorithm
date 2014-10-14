#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100005;
int a[MAX], b[MAX];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}
	sort(a, a+n);
	sort(b, b+m, greater<int>());
	long long ans = 0;
	for (int i = 0; i < n && i < m && a[i] < b[i]; ++i) {
		ans += b[i] - a[i];
	}
	cout << ans << endl;
	return 0;
}
