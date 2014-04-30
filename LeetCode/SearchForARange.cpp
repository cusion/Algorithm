#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/************* method 1 using stl lower_bound && upper_bound ************
vector<int> searchRange(int A[], int n, int target) {
	vector<int> ret(2, -1);
	if (n <= 0 || A == NULL) {
		return ret;
	}
	vector<int> num(A, A+n);
	vector<int>::iterator low = lower_bound(num.begin(), num.end(), target);
	vector<int>::iterator up = upper_bound(num.begin(), num.end(), target);
	if (low != up) {
		ret[0] = low - num.begin();
		ret[1] = up - num.begin() - 1;
	}
	
	return ret;
}*/

/************ method 2 using binary search *************/
int my_lower_bound(int A[], int n , int target) {
	int low = 0; 
	int high = n - 1;
	int mid = (low + high) >> 1;
	if (target > A[high]) {
		return n;
	} else if (target < A[low]) {
		return -1;
	}
	while (low < high) {
		if (A[mid] < target) {
			low = mid + 1;
		} else {
			high = mid;
		}
		mid = (low + high) >> 1;
	}
	return mid;
}

int my_upper_bound(int A[], int n, int target) {
	int low = 0;
	int high = n - 1;
	int mid = (low + high) >> 1;
	if (target >= A[high]) {
		return n;
	} else if (target < A[low]) {
		return -1;
	}
	while (low < high) {
		if (A[mid] > target) {
			high = mid;
		} else {
			low = mid + 1;
		}
		mid = (low + high) >> 1;
	}
	
	return mid;
}
vector<int> searchRange(int A[], int n, int target) {
	vector<int> ret(2, -1);
	if (n <= 0 || A == NULL) {
		return ret;
	}
	int low = my_lower_bound(A, n, target);
	int up = my_upper_bound(A, n, target);
	if (low != up) {
		ret[0] = low;
		ret[1] = up - 1;
	}
	return ret;
}

int main() {
	
	return 0;
}
