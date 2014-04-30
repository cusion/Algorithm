#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int bin2gray(int n) {
	return n ^ (n >> 1);
}

vector<int> grayCode(int n) {
	vector <int> ret;
	if (n < 0) {
		return ret;
	}
	int total = 1 << n;
	//cout << total << endl;
	for (int i = 0; i < total; ++i) {
		ret.push_back(bin2gray(i));
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> ret = grayCode(n);
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << endl;
	}
	return 0;
}
