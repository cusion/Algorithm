#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n, v;
	cin >> n >> v;
	int ans[n];
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		bool isFound = false;
		for (int j = 0; j < k; ++j) {
			int tmp;
			cin >> tmp;
			if (!isFound && tmp < v) {
				ans[idx++] = i+1;
				isFound = true;
			}
		}
	}
	
	cout << idx << endl;
	for (int i = 0; i < idx; ++i) {
		cout << ans[i] << " ";
	}
	return 0;
}
