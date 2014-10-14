#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100005;
char str[MAX];
bool isPreEqualSuf[MAX];
int prefixLenCnt[MAX];
void solve(char *str, int len) {
	vector <int> next(len);
	next[0] = 0;  // this is different from kmp search
	for (int i = 1; i < len; ++i) {
		int k = next[i-1];
		while (k != 0 && str[i] != str[k]) {
			k = next[k-1];    // because index is different from length
		}
		if (str[i] == str[k]) {
			++k;
		}
		next[i] = k;
	}
	/*for (int i = 0; i < len; ++i) {
		cout << next[i] << " ";
	}puts("");*/
	int suffixLen = len;
	int cnt = 0;
	while (suffixLen > 0) {
		isPreEqualSuf[suffixLen] = true;
		++cnt;
		suffixLen = next[suffixLen-1];
	}
	for (int i = 0; i < len; ++i) {
		prefixLenCnt[next[i]]++;
	}
	for (int i = len; i >=1; --i) {
		prefixLenCnt[next[i-1]] += prefixLenCnt[i];
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= len; ++i) {
		if (isPreEqualSuf[i]) {
			printf("%d %d\n", i, prefixLenCnt[i]+1);
		}
	}
}

int main() {
	gets(str);
	int len = strlen(str);
	solve(str, len);
	return 0;
}
