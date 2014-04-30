#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
	if (a.empty()) {
		return b;
	}
	if (b.empty()) {
		return a;
	}
	int idxa = a.length()-1;
	int idxb = b.length()-1;
	int inc = 0;
	string ret = "";
	while (idxa>=0 && idxb>=0) {
		int res = inc + a[idxa] - '0' + b[idxb] - '0';
		ret.push_back(res%2 + '0');
		inc = res / 2;
		--idxa, --idxb;
	}
	while (idxa >= 0) {
		int res = inc + a[idxa] - '0';
		ret.push_back(res%2+'0');
		inc = res / 2;
		--idxa;
	}
	while (idxb >= 0) {
		int res = inc + b[idxb] - '0';
		ret.push_back(res%2 + '0');
		inc = res / 2;
		--idxb;
	}
	if (inc > 0) {
		ret.push_back('1');
	}
	
	for (int i = 0; i < ret.size()/2; ++i) {
		char ch = ret[ret.size()-i-1];
		ret[ret.size()-i-1] = ret[i];
		ret[i] = ch;
	}
	
	return ret;
}

int main() {
	return 0;
}
