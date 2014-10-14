#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	int tmp;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		d -= tmp;
		if (d < 0) {
			cout << -1 << endl;
			return 0;
		}
		if (i < n-1) {
			d -= 10;
			ans += 2;
		} else {
			ans += d/5;
		}
	}
	
	cout << ans << endl;
	return 0;
}
