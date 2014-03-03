#include <cstdio>
#include <iostream>
#include <stack>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Node {
	int height;
	int indx;
	Node(int h, int i): height(h), indx(i) {}
};

/************************** Method 1 **********************************
int trap(int A[], int n) {
	if (n == 0) return 0;
	int ret = 0;
	stack <Node> left;
	Node tmp(A[0], 0);
	left.push(tmp);
	
	for (int i = 1; i < n; ++i) {
		tmp = left.top();
		//cout << left.size() << endl;
		//cout << i << " " << A[i] << " " << tmp.indx << " " << tmp.height << endl;
		//system("pause");
		if (A[i] > tmp.height) {
			if (left.size() == 1) {
				left.pop();
				tmp.height = A[i];
				tmp.indx = i;
				left.push(tmp);
			} else {
				Node base = left.top();
				left.pop();
				Node leftWall = left.top();
				while (A[i] > base.height) {
					ret += (min(leftWall.height, A[i]) - base.height) * (i-1-leftWall.indx);
					//cout << ret << " " << base.height << " " << base.indx << " " << leftWall.height << " " << leftWall.indx << endl;
					//system("pause");
					base = leftWall;
					left.pop();
					if (left.empty()) {
						break;
					}
					leftWall = left.top();
				}
				if (A[i] < base.height) {
					left.push(base);
				}
				tmp.height = A[i];
				tmp.indx = i;
				left.push(tmp);
			}
		} else if (A[i] < tmp.height) {
			tmp.height = A[i];
			tmp.indx = i;
			left.push(tmp);
		} else {
			tmp.indx = i;
			left.pop();
			left.push(tmp);
		}
	}
	
	return ret;
}
*/

/*********************** Method 2 **************************/
int trap(int A[], int n) {
	int ret = 0;
	if (n == 0) return ret;
	Node maxLeft(A[0], 0);
	for (int i = 1; i < n; ++i) {
		if (A[i] > maxLeft.height) {
			for (int j = maxLeft.indx+1; j < i; ++j) {
				ret += maxLeft.height - A[j];
				A[j] = maxLeft.height;
			}
			maxLeft.height = A[i];
			maxLeft.indx = i;
		} else {
			if (A[i] > A[i-1] && (i==n-1 || A[i] >= A[i+1])) {
				for (int j = maxLeft.indx+1; j < i; ++j) {
					if(A[i] > A[j]){
						ret += A[i] - A[j];
						A[j] = A[i];
					}
				}
				if (A[i] == maxLeft.height) {
					maxLeft.indx = i;
				}
			}
		}
	}
	
	return ret;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d,", &arr[i]);
	}
	cout << trap(arr, n);
	return 0;
}
