#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int numDecodings(string s) {
	if (s.empty() || s[0] == '0') return 0;
	int num[s.length()+1];
	num[0] = 1;
	num[1] = 1;
	for (int len = 2; len <= s.length(); ++len) {
		if (s[len-1] == '0') {
			if (s[len-2] == '0' || s[len-2] >= '3') return 0;
			num[len] = num[len-2];
		} else {
			if (s[len-1-1] == '1') {
				num[len] = num[len-1] + num[len-2];
			} else if (s[len-1-1] == '2') {
				if (s[len-1]<='6') {
					//cout << "test " << len << endl;
					num[len] = num[len-1] + num[len-2];
				} else {
					num[len] = num[len-1];
				}
			} else {
				num[len] = num[len-1];
			}
		}
	}
	return num[s.length()];
}

int main() {
	while (1) {
		string s;
		cin >> s;
		cout << numDecodings(s) << endl;
	}
	return 0;
}
