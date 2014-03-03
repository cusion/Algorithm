#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	int arr[103];
	cin >> n >> m;
	// Method 1
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int border = m % n;
	
	if (border > 0) {
		for (int i = 0; i < n/2; ++i) {
			arr[i] = arr[i] + arr[n-1-i];
			arr[n-1-i] = arr[i] - arr[n-1-i];
			arr[i] = arr[i] - arr[n-1-i];
		}
		for (int i = 0; i < border/2; ++i) {
			arr[i] = arr[i] + arr[border-1-i];
			arr[border-1-i] = arr[i] - arr[border-1-i];
			arr[i] = arr[i] - arr[border-1-i];
		}
		for (int i = border; i < (n+border)/2; ++i) {
			arr[i] = arr[i] + arr[n-1-(i-border)];
			arr[n-1-(i-border)] = arr[i] - arr[n-1-(i-border)];
			arr[i] = arr[i] - arr[n-1-(i-border)];
		}
	}

	for (int i = 0; i < n-1; ++i) {
		cout << arr[i]<<" ";
	}
	cout << arr[n-1] << endl;

	return 0;
}
