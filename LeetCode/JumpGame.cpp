#include <cstdio>
#include <iostream>
using namespace std;

bool canJump(int A[], int n) {
	if (n == 0) return true;
	int cur = 0, maxIndx = A[0];
	
	while(cur < n){
		++cur;
		if (cur <= maxIndx) {
			maxIndx = max(maxIndx, cur + A[cur]);
		} else {
			break;
		}
	}
	
	return maxIndx >= n-1;
}

int main() {
	int arr[] = {0, 1};
	
	if(canJump(arr, 2)) {
		puts("Yes");
	} else {
		puts("No");
	}
		
	return 0;
}
