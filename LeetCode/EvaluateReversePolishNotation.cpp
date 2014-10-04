#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isOperator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int str2num(string s) {
	int ret = 0;
	int start = isOperator(s[0]) ? 1 : 0;
	bool flag = s[0] == '-' ? false : true;
	for (int i = start; i < s.length(); ++i) {
		ret = ret*10 + s[i] - '0';
	}
	
	return flag ? ret : -ret;
}

int evaluate(int a, int b, char op) {
	switch(op) {
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}

int evalRPN(vector<string> &tokens) {
	if (tokens.empty()) {
		return 0;
	}
	stack<int> num;
	for (int i = 0; i < tokens.size(); ++i) {
		if (tokens[i].size() == 1 && isOperator(tokens[i][0])) {
			int b = num.top();
			num.pop();
			int a = num.top();
			num.pop();
			num.push(evaluate(a, b, tokens[i][0]));
			//cout << "calc " << num.top() << endl;
		} else {
			num.push(str2num(tokens[i]));
		}
	}
	
	return num.top();
}

int main() {
	string s[] = {"4", "13", "5", "/", "+"};
	vector <string> tokens(s, s+5);
	cout << evalRPN(tokens);
	return 0;
}
