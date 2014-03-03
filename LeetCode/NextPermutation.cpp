#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
	a += b;
	b = a - b;
	a = a - b;
}

void nextPermutation(vector<int> &num) {
	if (num.size() < 2) {
		return;
	}
	int firstAscend = num.size()-2;
	while (firstAscend >= 0 && num[firstAscend] >= num[firstAscend+1]) {
		--firstAscend;
	}
	if (firstAscend < 0) {
		for (int i = 0; i < num.size()/2; ++i) {
			swap(num[i], num[num.size()-1-i]);
		}
		return ;
	}
	int firstLarger = num.size()-1;
	while (num[firstLarger] <= num[firstAscend]) {
		--firstLarger;
	}
	//cout << firstAscend << " " << firstLarger << endl;
	swap(num[firstAscend], num[firstLarger]);
	for (int i = 0; i < (num.size()-1-firstAscend)/2; ++i) {
		swap(num[i+firstAscend+1], num[num.size()-1-i]);
	}
	return ;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0;i < n; ++i) {
		cin >> arr[i];
	}
	vector<int> num(arr, arr+n);
	nextPermutation(num);
	for (int i = 0; i < n; ++i) {
		cout << num[i] << " ";
	}puts("");
	return 0;
}
