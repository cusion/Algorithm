#include <cstdio>
#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
	if (n <= 2) {
		return n;
	}
	int cnt = 1;
	int indx = 1;
	for (int i = 1; i < n; ++i) {
		if (A[i] == A[i-1]) {
			if (cnt < 2) {
				A[indx++] = A[i];
				++cnt;
			}
		} else {
			A[indx++] = A[i];
			cnt = 1;
		}
	}
	
	return indx;
}

int main() {
	return 0;
}
