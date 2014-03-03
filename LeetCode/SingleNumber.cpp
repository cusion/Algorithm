#include <cstdio>
#include <iostream>
using namespace std;

// there should be another very delicate algorithm as I remembered,
// the algorithm could not only solve this problem, but also solve
// problem like all numbers appears 3 times rather than only one 
// appears 1 time, or 2 times, or even 2 numbers appear 1 time respectively.
// I would find this algorithm out when I rearrange all those solutions of leetcode.
int singleNumber(int A[], int n) {
	if (n == 0) {
		return 0;
	}
	int ret = A[0];
	for (int i = 1; i < n; ++i) {
		ret ^= A[i];
	}
	
	return ret;
}

int main() {
	return 0;
}
