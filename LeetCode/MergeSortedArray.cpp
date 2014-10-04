#include <cstdio>
#include <iostream>
using namespace std;

void merge(int A[], int m, int B[], int n) {
	for (int i = 0; i < m; ++i) {
		A[m+n-1-i] = A[m-1-i];
	}
	int aind = n;
	int bind = 0;
	int mergeind = 0;
	while (aind < m+n && bind < n) {
		if (A[aind] < B[bind]) {
			A[mergeind++] = A[aind++];
		} else if (A[aind] > B[bind]) {
			A[mergeind++] = B[bind++];
		} else {
			A[mergeind++] = A[aind++];
			A[mergeind++] = B[bind++];
		}
	}
	while (bind < n) {
		A[mergeind++] = B[bind++];
	}
}

int main() {
	return 0;
}
