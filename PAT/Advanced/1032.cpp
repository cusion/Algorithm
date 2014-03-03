#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100003;
int nextAdd[N];

int main() {
	int n;
	int addA, addB;
	cin >> addA >> addB >> n;
	for (int i = 0; i < N; ++i) {
		nextAdd[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		int tmpAdd, tmpNext;
		char ch;
		scanf("%d %c %d", &tmpAdd, &ch, &tmpNext);
		nextAdd[tmpAdd] = tmpNext;
	}
	int lenA = 0, lenB = 0;
	int curA = addA, curB = addB;
	while (curA != -1) {
		++lenA;
		curA = nextAdd[curA];
	}
	while (curB != -1) {
		++lenB;
		curB = nextAdd[curB];
	}
	int longer, shorter, preStep;
	if (lenA > lenB) {
		preStep = lenA - lenB;
		longer = addA;
		shorter = addB;
	} else {
		preStep = lenB - lenA;
		longer = addB;
		shorter = addA;
	}
	
	while (preStep--) {
		longer = nextAdd[longer];
	}
	
	while (longer != shorter) {
		longer = nextAdd[longer];
		shorter = nextAdd[shorter];
	}
	
	if (longer != -1) {
		printf("%05d\n", longer);
	} else {
		puts("-1");
	}
	
	return 0;
}
