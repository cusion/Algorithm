#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

/*********** Dynamic Approach **************
int jump(int arr[], int n) {
	int steps[n];
	steps[0] = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (i-j <= arr[j]) {
				steps[i] = steps[j] + 1;
				break;
			}
		}
	}
	
	return steps[n-1];
}
*/

/************ Greedy Approach *************/
int jump(int arr[], int n) {
	
	if (n==1) return 0;
	
	int curMinStep = 1, curMaxIndx = arr[0], nextMaxIndx = -1;
	
	for (int i = 1; i < n; ++i) {
		if (i > curMaxIndx) {
			curMinStep++;
			curMaxIndx = nextMaxIndx;
			
			if (curMaxIndx >= n-1) break;
		}
		nextMaxIndx = max(nextMaxIndx, i + arr[i]);
	}
	
	return curMinStep;
}

int main() {
	int A[] = {2, 3, 1, 1, 4};
	cout << jump(A, 5) << endl;
	return 0;
}
