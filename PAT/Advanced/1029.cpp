#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int m, n;
	cin >> m;
	int a[m];
	for (int i = 0; i < m; ++i) {
		scanf("%d", &a[i]);
	}
	cin >> n;
	int b[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	
	int tar = (m+n-1)/2;
	
	int count = 0;
	int result;
	
	int inda = 0, indb = 0;
	while (count < tar && inda < m && indb < n) {
		if (a[inda] < b[indb]) {
			++inda;
		} else {
			++indb;
		}
		++count;
	}
	if (count < tar) {
		while (inda < m && count < tar) {
			++inda;
			++count;
		}
		while (indb < n && count < tar) {
			++indb;
			++count;
		}
	}
	
	if (inda == m) {
		cout << b[indb] << endl;
	} else if (indb == n) {
		cout << a[inda] << endl;
	} else {
		cout << min(a[inda], b[indb]) << endl;
	}
	return 0;
}
