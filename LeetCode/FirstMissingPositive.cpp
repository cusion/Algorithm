#include <cstdio>
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int firstMissingPositive(int A[], int n) {
	if (n <= 0) {
		return 1;
	}
	for (int i = 0; i < n; ++i) {
		while ((A[i] != i+1) && (A[i] <= n && A[i] > 0 && A[A[i]-1] != A[i])) {
			swap(A[i], A[A[i]-1]);
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (A[i] != i+1) {
			return i+1;
		}
	}
	
	return n+1;
}

int main() {
	return 0;
}
