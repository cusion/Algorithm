#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int cnt[10];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &cnt[i]);
	}
	for (int i = 1; i < 10; ++i) {
		if (cnt[i] > 0) {
			cout << i ;
			--cnt[i];
			break;
		}
	}
	for (int i = 0; i < 10; ++i) {
		while (cnt[i] > 0) {
			cout << i;
			--cnt[i];
		}
	}
	cout << endl;
	return 0;
}
