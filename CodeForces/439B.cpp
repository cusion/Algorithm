#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	long long subs[n];
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", &subs[i]);
	}
	sort(subs, subs+n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += subs[i]*x;
		--x;
		if (x <= 0) {
			x = 1;
		}
	}
	
	cout << ans << endl;
	return 0;
}
