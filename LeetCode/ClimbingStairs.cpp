#include <cstdio>
#include <iostream>
using namespace std;

int climbStairs(int n) {
	int f1 = 1;
	int f2 = 1;
	int f = f2;
	for (int i = 1;i < n; ++i) {
		f = f1 + f2;
		f1 = f2;
		f2 = f;
	}
	
	return f;
}

int main() {
	int n;
	while (1) {
		cin >> n;
		cout << climbStairs(n) << endl;
	}
	return 0;
}
