#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getPermutation(int n, int k) {
	string ret = "";
	if (n <= 0 || k <= 0) {
		return ret;
	}
	// make the permutation index start from 0 for computation convenience
	--k;
	vector<int> factorial(n+1, 1);
	vector<char> digits;
	for (int i = 1; i <= n; ++i) {
		factorial[i] = i*factorial[i-1];
		digits.push_back(i+'0');
	}
	if (k >= factorial[n]) {
		k = k % factorial[n];
	}
	
	int cnt = 0;
	while (cnt < n) {
		//cout << n << " " << k << " " << factorial[digits.size()-1] << endl;
		int currentCharIdx = k / factorial[digits.size()-1];
		ret.push_back(digits[currentCharIdx]);
		k = k % factorial[digits.size()-1];
		++cnt;
		digits.erase(digits.begin()+currentCharIdx);
	}
	
	return ret;
}

int main() {
	cout << getPermutation(3,2) << endl;
	return 0;
}
