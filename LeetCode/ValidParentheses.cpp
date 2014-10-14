#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isMatch(char l, char r) {
	if ((l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}')) {
		return true;
	}
	return false;
}

bool isValid(string s) {
	if (s.empty()) return true;
	if (s.length() % 2) return false;
	stack <char> par;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			par.push(s[i]);
		} else {
			if (par.empty() || !isMatch(par.top(), s[i])) return false;
			par.pop();
		}
	}
	if (!par.empty()) return false;
	return true;
}

int main() {
	string s;
	while(1) {
		cin >> s;
		cout << isValid(s);
	}
	return 0;
}
