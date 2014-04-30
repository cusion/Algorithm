#include <cstdio>
#include <iostream>
using namespace std;

bool directSearch(int A[], int low, int high, int target) {
	for (int i = low; i <= high; ++i) {
		if (A[i] == target) {
			return true;
		}
	}
	return false;
}

bool search(int A[], int n, int target) {
	if (A == NULL || n == 0) {
		return false;
	}
	int low = 0;
	int high = n-1;
	while (low <= high) {
		int mid = (low+high) >> 1;
		if (A[mid] == A[low] && A[mid] == A[high]) {
			return directSearch(A, low, high, target);
		}
		if (A[mid] == target) {
			return true;
		} else if (A[mid] > target) {
			if (A[mid] <= A[high] || target >= A[low]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		} else {
			if (A[mid] >= A[low] || target <= A[high]) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
	}
	
	return false;
}

int main() {
	return 0;
}
