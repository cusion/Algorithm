#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool isValidChar(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
			|| (ch >= '0' && ch <= '9');
}

char getOneValidChar(string &s, int &indx, int step) {
	while (indx >= 0 && indx < s.length() && !isValidChar(s[indx])) {
		indx += step;
	}
	if (indx >= 0 && indx < s.length()) {
		if (s[indx] >= 'A' && s[indx] <= 'Z') {
			return s[indx]-'A'+'a';
		} else {
			return s[indx];
		}
	} else {
		return ' ';
	}
}

bool isPalindrome (string s) {
	if (s.empty()) {
		return true;
	}
	int left = 0, right = s.length()-1;
	while (left < right) {
		//cout << left << " " << right << endl;
		if (getOneValidChar(s, left, 1) != getOneValidChar(s, right, -1)) {
			return false;
		}
		++left;
		--right;
	}
	
	return true;
}

int main() {
	string s = "race a car";
	cout << isPalindrome(s) << endl;
	return 0;
}
