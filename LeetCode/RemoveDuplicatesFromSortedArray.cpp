#include <cstdio>
#include <iostream>

using namespace std;

int removeDuplicates(int arr[], int n) {
	if (arr == NULL) return 0;
	
	int ind = 1;
	int cur = 1;
	
	while (cur < n) {
		if (arr[cur] != arr[cur-1]) {
			arr[ind++] = arr[cur];
		}
		++cur;
	}
	
	return ind;
}

int main() {
	int arr[] = {1, 1, 3, 5, 7,7, 8};
	
	int len = removeDuplicates(arr, 7);
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << " ";
	}puts("");
	
	return 0;
}
