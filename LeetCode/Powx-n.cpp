#include <cstdio>
#include <iostream>
using namespace std;

double pow(double x, int n) {
	double ret = 1;
	if (n == 0) {
		return ret;
	}
	bool revert = n < 0 ? true : false;
	n = n > 0 ? n : -n;
	int flag = 0x7fffffff;
	while ((flag & n) != 0) {
		if (n & 1) {
			ret *= x;
		}
		x *= x;
		n = n>>1;
	}
	
	return revert ? 1/ret : ret;
}

int main() {
	while (1) {
		double x;
		int n;
		cin >> x >> n;
		cout << pow(x, n) << endl;
	}
	return 0;
}
