#include <cstdio>
#include <iostream>
using namespace std;

int removeElement(int A[], int n, int elem) {
	if (n == 0) {
		return 0;
	}
	int ind = 0;
	for (int i = 0; i < n; ++i) {
		if (A[i] != elem) {
			A[ind++] = A[i];
		}
	}
	
	return ind;
}

int main() {
	return 0;
}
