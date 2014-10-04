#include <cstdio>
#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;

/*************** Method 1 ****************
int maxSubArray(int A[], int n) {
	if (n == 0) {
		return 0;
	}
	int sum = A[0];
	int tmpSum = A[0];
	for (int i = 1; i < n; ++i) {
		if (tmpSum < 0) {
			tmpSum = A[i];
		} else {
			tmpSum += A[i];
		}
		sum = sum > tmpSum ? sum : tmpSum;
	}
	
	return sum;
}*/

/************* Method 2: Divide and Conqure ***********/
int divideAndConquer(int A[], int l, int r) {
	if (l == r) {
		return A[l];
	}
	if (l > r) return INT_MIN;
	int mid = (l+r)>>1;
	int leftMax = divideAndConquer(A, l, mid-1);
	int rightMax = divideAndConquer(A, mid+1, r);
	int midMax = INT_MIN;
	int leftSum = 0;
	for (int i = mid; i >= l; --i) {
		leftSum += A[i];
		if (midMax < leftSum) {
			midMax = leftSum;
		}
	}
	int rightSum = 0;
	int mid2right = 0;
	for (int i = mid+1; i <= r; ++i) {
		rightSum += A[i];
		if (mid2right < rightSum) {
			mid2right = rightSum;
		}
	}
	midMax += mid2right;
	//cout << "left " << leftMax << " mid " << midMax << " right " << rightMax << endl;
	return max(midMax, max(leftMax, rightMax));
}

int maxSubArray(int A[], int n) {
	if (n == 0) {
		return 0;
	}
	
	return divideAndConquer(A, 0, n-1);
}

int main() {
	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxSubArray(arr, 9) << endl;
	return 0;
}
