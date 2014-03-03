#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void isPalindrome(int n, int b) {
	vector <int> kbase;
	if (n == 0) {
		cout << "Yes" << endl;
		cout << "0" << endl;
		return ;
	}
	
	while (n > 0) {
		kbase.push_back(n%b);
		n /= b;
	}
	bool isPalindrome = true;
	for (int i = 0; i < kbase.size(); ++i) {
		if (kbase[i]!=kbase[kbase.size()-1-i]) {
			cout << "No" << endl;
			isPalindrome = false;
			break;
		}
	}
	if (isPalindrome) {
		cout << "Yes" << endl;
	}
	for (int i = kbase.size()-1; i > 0; --i) {
		printf("%d ", kbase[i]);
	}
	printf("%d\n", kbase[0]);
	return;
}

int main() {
	int n, b;
	cin >> n >> b;
	isPalindrome(n, b);
	return 0;
}
