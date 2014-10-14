#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int longestValidParentheses(string s) {
	if (s.empty()) {
		return 0;
	}
	stack <int> left;
	vector<bool> isMatch(s.length(), false);
	int idx = 0;
	while (idx < s.length()) {
		if (s[idx] == '(') {
			left.push(idx);
		} else {
			if (!left.empty()) {
				isMatch[left.top()] = true;
				isMatch[idx] = true;
				left.pop();
			}
		}
		++idx;
	}
	
	int len = 0;
	int tmpLen = 0;
	for (int i = 0; i < isMatch.size(); ++i) {
		if (!isMatch[i]) {
			len = len < tmpLen ? tmpLen : len;
			tmpLen = 0;
		} else {
			++tmpLen;
		}
	}
	len = len < tmpLen ? tmpLen : len;
	
	return len;
}

int main() {
	string s = "()";
	cout << longestValidParentheses(s) << endl;
	return 0;
}
