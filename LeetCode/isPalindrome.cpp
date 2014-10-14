#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
/************************* Method 1 *****************
/*
/* This is a slow iterative method; 
/*
bool isPalindrome(int x) {
	int cnt = 1;
	long long ord = 10;
	while (x/ord) {
		ord *= 10;
		cnt += 1;
	}
	if (cnt == 1) {
		return true;
	} else {
		while (cnt > 1) {
			int p = (int)pow(10, cnt-1);
			int left = x / p;
			int right = x % 10;
			if (left != right) {
				return false;
			}
			x = (x - left*p)/10;
			cnt -= 2;
		}
		return true;
	}
	return true;
}
*/

/********************** Method 2 *********************/
bool isPalindrome(int x) {
	if (x < 10 && x >= 0) return true;
	if (x < 0 || (x%10 == 0)) {
		return false;
	}
	int rev = 0;
	while (rev < x) {
		rev = rev * 10 + x % 10;
		x = x/10;
	}
	if (x == rev || x == rev/10) {
		return true;
	}
	return false;
}

int main() {
	int n;
	while (1) {
		cin >> n;
		if (isPalindrome(n)) {
			cout << "true" << endl;
		} else {
			cout << "false" << endl;
		}
	}
	return 0;
}
