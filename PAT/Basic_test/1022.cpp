#include <cstdio>
#include <iostream>
using namespace std;

string d_radix(int n, int d) {
	string ret = "";
	if (n == 0) {
		ret.push_back('0');
		return ret;
	}
	while (n) {
		ret.push_back(n%d + '0');
		n /= d;
	}
	for (int i = 0; i < ret.size()/2; ++i) {
		char tmp = ret[i];
		ret[i] = ret[ret.size()-1-i];
		ret[ret.size()-1-i] = tmp;
	}
}

int main() {
	int a, b, d;
	cin >> a >> b >> d;
	if (d == 10) {
		cout << a+b << endl;
	} else {
		cout << d_radix(a+b, d) << endl;
	}
	return 0;
}
