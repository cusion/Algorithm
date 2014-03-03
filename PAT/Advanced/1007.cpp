#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n, arr[10002];
	cin>>n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int tmp = 0;
    int maxSum = arr[0];
	int leftTmp = 0, left = 0, right = 0;
	for (int i = 0; i < n; ++i) {
		if (tmp >= 0) {
			tmp += arr[i];
		} else {
			tmp = arr[i];
			leftTmp = i;
		}
		if (maxSum < tmp) {
			maxSum = tmp;
			left = leftTmp;
			right = i;
		}
	}
	
	if (maxSum < 0) {
		cout << 0 << " " << arr[0] << " " << arr[n-1] << endl;
	} else {
		cout << maxSum << " " << arr[left] << " " << arr[right] << endl;
	}

	return 0;
}
