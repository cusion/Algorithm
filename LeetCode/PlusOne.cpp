#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

vector <int> plusOne(vector<int> &digits) {
	int inc = 1;
	for (int i = digits.size()-1; i >= 0; --i) {
		int tmp = (digits[i] + inc) % 10;
		inc = (digits[i] + inc)/10;
		digits[i] = tmp;
	}
	if (inc == 1) {
		digits.insert(digits.begin(), 1);
	}
	return digits;
}

int main() {
	int n;
	while(1) {
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		vector <int> digits(arr, arr+n);
		plusOne(digits);
		for (int i = 0; i < digits.size(); ++i) {
			cout << digits[i];
		}puts("");
	}
	return 0;
}
