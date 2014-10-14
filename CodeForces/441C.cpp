#include <cstdio>
#include <iostream>
using namespace std;

bool isValid(int j, int i, int c) {
	if (i % 2) {
		return j <= c;
	} else {
		return j > 0;
	}
}

int main() {
	int r, c ,k;
	cin >> r >> c >> k;
	int rowIdx = 1, colIdx = 1;
	
	int cnt = 0;
	for (int i = 1; i <= r; ++i) {
		int j = i % 2 ? 1 : c;
		int inc = i % 2 ? 1 : -1;
		while (isValid(j, i, c)) {
			if (cnt < 2*(k-1)) {
				if (cnt % 2 == 0) {
					if (cnt > 0) {
						cout << "\n";
					}
					cout << 2;
				}
				cout << " " << i << " " << j;
			} else {
				if (cnt == 2*(k-1)) {
					if (cnt > 0) {
						puts("");
					}
					cout << r*c-2*(k-1);
				}
				cout << " " << i << " " << j;
			}
			
			++cnt;
			j += inc;
		}
	}puts("");
	
	return 0;
}
