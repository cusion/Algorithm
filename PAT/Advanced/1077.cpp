#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int getCommom(const char *src, const char *tar, int start, int lentar) {
	int lensrc = strlen(src);
	int srcIdx = lensrc-1;
	int tarIdx = lentar-1;
	while (srcIdx >= 0 && tarIdx > start) {
		if (src[srcIdx] == tar[tarIdx]) {
			--srcIdx;
			--tarIdx;
		} else {
			break;
		}
	}
	
	return tarIdx;
}

int main() {
	char pre[300];
	char cur[300];
	int start = -1;
	int n;
	cin >> n;
	getchar();
	gets(pre);
	int lenPre = strlen(pre);
	for (int i = 1; i < n; ++i) {
		gets(cur);
		start = getCommom(cur, pre, start, lenPre);
	}
	if (start == lenPre-1) {
		cout << "nai" << endl;
	} else {
		puts(&pre[start+1]);
	}
	return 0;
}
