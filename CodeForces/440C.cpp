#include <iostream>
#include <cstdio>
using namespace std;

inline int min(int a, int b) {
	return a > b ? b : a;
}

int minOnes(long long n, long long major, int digits) {
	if (n <= 11) {
		return min(13-n, n);
	}
	int k = n/major;
	
	if ((n%major) == 0) {
		return digits*k;
	}
	
	return min(digits*k + minOnes(n-k*major, major/10, digits-1), 
			   digits*(k+1) + minOnes((k+1)*major-n, major/10, digits-1));
}

int main() {
	long long n;
	cin >> n;
	long long major = 1;
	int digits = 1;
	while (n >= major) {
		++digits;
		major = major*10 + 1;
	}
	cout << minOnes(n, major, digits);
	
	return 0;
}
