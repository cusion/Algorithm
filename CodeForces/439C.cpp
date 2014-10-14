#include <cstdio>
#include <iostream>
using namespace std;

const int NUM = 100005;

int odd[NUM], even[NUM];

int main() {
	int n, k, p;
	cin >> n >> k >> p;
	int oddNum = 0, evenNum = 0;
	for (int i = 0; i < n; ++i) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp % 2 == 0) {
			even[evenNum++] = tmp;
		} else {
			odd[oddNum++] = tmp;
		}
	}
	
	if (p == 0) {
		if ((oddNum-k) % 2 == 0) {
			puts("YES");
			for (int i = 0; i < k-1; ++i) {
				cout << "1 " << odd[i] << endl;
			}
			cout << oddNum-k+1 + evenNum;
			for (int i = k-1; i < oddNum; ++i) {
				cout << " " << odd[i];
			}
			for (int i = 0; i < evenNum; ++i) {
				cout << " " << even[i];
			}puts("");
		} else {
			puts("NO");
		}
		return 0;
	}
	
	if (evenNum >= p) {
		if (oddNum >= (k-p) && (oddNum-(k-p)) % 2 == 0) {
			puts("YES");
			for (int i = 0; i < k-p; ++i) {
				cout << "1 " << odd[i] << endl;
			}
			for (int i = 0; i < p-1; ++i) {
				cout << "1 " << even[i] << endl;
			}
			int left = oddNum-(k-p) + evenNum - p + 1;
			cout << left;
			for (int i = k-p; i < oddNum; ++i) {
				cout << " " << odd[i];
			}
			for (int i = p-1; i < evenNum; ++i) {
				cout << " " << even[i];
			}
			puts("");
		} else {
			puts("NO");
		}
	} else {
		int need = (p-evenNum)*2;
		if (oddNum - need >= (k-p) && (oddNum-need-k+p) % 2 == 0) {
			puts("YES");
			for (int i = 0; i < k-p; ++i) {
				cout << "1 " << odd[i] << endl;
			}
			for (int i = 0; i < evenNum; ++i) {
				cout << "1 " << even[i] << endl;
			}
			int oddIdx = k-p;
			for (int i = evenNum; i < p-1; ++i) {
				cout << "2 " << odd[oddIdx++] << " " << odd[oddIdx++] << endl;
			}
			cout << oddNum-oddIdx;
			while (oddIdx < oddNum) {
				cout << " " << odd[oddIdx++];
			}
			puts("");
		} else {
			puts("NO");
		}
	}
	
	return 0;
}
