#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isNumerical(char ch) {
	if (((ch >= '0')&&(ch <= '9')) || (ch == '.')) {
	//	puts("isNumerical");
		return true;
	}
	return false;
}

string getnum(string input, int &indx) {
	string ret = "";
	if ((input[indx] == '-') || (input[indx] == '+')) {
		if (input[indx] == '-') ret.append(1, input[indx]);
		indx++;
	}
	if (input[indx] == '.') {
		ret.append(1, '0');
		ret.append(1, '.');
		indx++;
	}
	while ((indx < input.size()) && isNumerical(input[indx])) {
		ret.append(1, input[indx]);
		//cout << ret << endl;
		//getchar();
		indx++;
	}
	return ret;
}

bool isOperator(string input, int indx) {
	if ((indx == 0) || (input[indx-1] == '(') || isNumerical(input[indx])) {
		//puts("isNotOperator");
		return false;
	}
	return true;
}

int getpriority(char ch) {
	switch (ch) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
}

bool compare(char cur, char top) {
	if (top == '(') return false;
	int curprio = getpriority(cur);
	int topprio = getpriority(top);
	if (curprio > topprio) {
		return false;
	}
	return true;
}

vector <string> parse(string input) {
	vector <string> ret;
	int indx = 0;
	stack <char> opstack;
	while (indx < input.size()) {
		//printf("indx = %d ch = %c\n", indx, input[indx]);
		//getchar();
		if (input[indx] == '(') {
			//puts("(");
			opstack.push('(');
			indx++;
		} else if (input[indx] == ')') {
			//puts(")");
			while (opstack.top()!='(') {
				//cout<<opstack.top()<<endl;;
				string tmp = "";
				tmp.append(1, opstack.top());
				opstack.pop();
				ret.push_back(tmp);
				//printf("Going to Pop %c\n", opstack.top());
				//puts("Press to continue ...");
				//getchar();
			}
			opstack.pop();
			indx++;
		} else if (isOperator(input, indx)) {
			//puts("operator");
			if (opstack.empty()) {
				opstack.push(input[indx]);
			} else {
				while (!opstack.empty() && compare(input[indx], opstack.top())) {
					string tmp = "";
					tmp.append(1, opstack.top());
					opstack.pop();
					ret.push_back(tmp);
				}
				opstack.push(input[indx]);
			}
			indx++;
		} else {
			//puts("number");
			string num = getnum(input, indx);
			ret.push_back(num);
		}
	}
	while (!opstack.empty()) {
		string tmp = "";
		tmp.append(1, opstack.top());
		ret.push_back(tmp);
		opstack.pop();
	}

	return ret;
}

int main()
{
	string input;
	cin >> input;
	vector <string> output;
	output = parse(input);
	cout << output[0];
	for (int i = 1; i < output.size(); ++i) {
		cout << " " << output[i];
	}

	return 0;
}
