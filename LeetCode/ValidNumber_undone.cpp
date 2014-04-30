#include <regex>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/********** regular expression (not supported)*********
bool isNumber(string str) {
	if (str.empty()) {
		return false;
	}
	regex pattern("^[+-]?[0-9]*\\.?[0-9]+$");
	system("pause");
	return regex_match(str, pattern);
}

int main() {
	string str = "0.9";
	if (isNumber(str)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
}*/
