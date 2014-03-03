#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

#define eps 1e-10
#define abs(a) ((a)>0?(a):-(a))

struct Token {
	bool flag;    // true for operator and false for oprand
	double data;
	char opt;
}tokens[50];

bool isOperator(char ch) {
	switch (ch) {
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
		default:
			return false;
	}
}

double getnum(char * str) {
	double ret = 0;
	int sign = 1;
	int exp = -1;
	int i = 0;
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-') sign = -1;
		i++;
	}
	while (str[i]!='\0') {
		if (exp >= 0) {
			exp++;
		}
		if (str[i] == '.') {
			exp++;
		} else {
			ret = ret*10 + str[i] - '0';
		}
		++i;
	}
	
	if (exp > 0){
		while (exp--) {
			ret /= 10;
		}
	}
	
	//printf("Number: %s %lf\n", str, ret);

	return sign*ret;
}

Token parseToken(char * str) {
	Token ret;
	if ((str[1] == '\0') && isOperator(str[0])) {
		ret.flag = true;
		ret.data = 0;
		ret.opt = str[0];
	} else {
		ret.flag = false;
		ret.data = getnum(str);
		ret.opt = '#';
	}

	return ret;
}

bool isValid(double a, double b, char ch) {
	if (ch == '/' && abs(b) <= eps) {
		return false;
	}
	return true;
}

double eval(double a, double b, char ch) {
	switch (ch) {
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

int main()
{
	int cnt = 0;
	char str[35];
	while (scanf("%s", str)!=EOF && (str[0]!='#')) {
		tokens[cnt++] = parseToken(str);
		//printf("%lf %c\n", tokens[cnt-1].data, tokens[cnt-1].opt);
	}

	bool isResultValid = true;
	stack <double> res;
	for (int i = cnt-1; i>=0; --i) {
		if (!tokens[i].flag){
			res.push(tokens[i].data);
		} else if(tokens[i].flag && !res.empty()) {
			double a = res.top();
			res.pop();
			double b = res.top();
			res.pop();
			if (isValid(a, b, tokens[i].opt)) {
				res.push(eval(a, b, tokens[i].opt));
				//cout << res.top() << endl;
			} else {
				//puts("divide 0");
				puts("ERROR");
				isResultValid = false;
				break;
			}
		} else {
			//puts("invalid input");
			puts("ERROR");
			isResultValid = false;
			break;
		}
	}
	if (isResultValid) {
		printf("%.1lf\n", res.top());
	}

	return 0;
}
