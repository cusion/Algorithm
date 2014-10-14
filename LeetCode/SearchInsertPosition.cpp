#include <cstdio>
#include <iostream>
using namespace std;

// When collating this file, you should make an entire
// comparison between different binary search problem
int searchInsert(int A[], int n, int target) {
	if (n == 0) {
		return 0;
	}
	if (target > A[n-1]) {
		return n;
	} else if (target < A[0]) {
		return 0;
	}
	int low = 0;
	int high = n-1;
	int mid = (low+high) >> 1;
	while (low < high) {
		mid = (low+high)>>1;
		if (A[mid] == target) {
			return mid;
		} else if (A[mid] > target) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	
	return high;
}

int main() {
	return 0;
}
