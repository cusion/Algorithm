#include <cstdio>
#include <iostream>
using namespace std;

int findKthInSortedArrays(int A[], int m, int B[], int n, int k) {
	if (m > n) {
		return findKthInSortedArrays(B, n, A, m, k);
	}
	if (m <= 0) {
		return B[k-1];
	}
	if (k == 1) {
		return A[0] < B[0] ? A[0] : B[0];
	}
	
	int a = m > k/2 ? k/2 : m;
	int b = k - a;
	if (A[a-1] < B[b-1]) {
		return findKthInSortedArrays(A+a, m-a, B, n, k-a);
	} else if(A[a-1] > B[b-1]) {
		return findKthInSortedArrays(A, m, B+b, n-b, k-b);
	} else {
		return A[a-1];
	}
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	if (m <= 0) {
		return (B[n/2]+B[(n-1)/2])*1.0/2;
	}
	if (n <= 0) {
		return (A[m/2]+A[(m-1)/2])*1.0/2;
	}
	int a = findKthInSortedArrays(A, m, B, n, (m+n)/2+1);
	int b = findKthInSortedArrays(A, m, B, n, (m+n-1)/2+1);
	
	return (a+b)*1.0/2;
}

int main() {
	return 0;
}
