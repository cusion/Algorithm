#include <cstdio>
#include <iostream>
using namespace std;

int reverse(int x) {
	if (x > -10 && x < 10) {
		return x;
	}
	int ret = 0;
	while (x) {
		ret = ret*10 + x%10;
		x /= 10;
	}
	return ret;
}

int main() {
	int n;
	while (1) {
		cin >> n;
		cout << reverse(n) << endl;
	}
	return 0;
}
