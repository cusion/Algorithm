#include <cstdio>
#include <iostream>
using namespace std;

int search(int A[], int n, int target) {
	if (n == 0) return -1;
	
	int left = 0;
	int right = n-1;
	while (left <= right) {
		int mid = (left + right)/2;
		if (A[mid] == target) {
			return mid;
		} else if (A[mid] < target) {
			if (A[mid] >= A[left] || A[right] >= target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		} else if (A[mid] > target) {
			if (A[mid] <= A[right] || A[left] <= target) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
	}
	
	return -1;
}

int main() {
	return 0;
}
