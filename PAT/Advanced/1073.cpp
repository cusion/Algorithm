#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int str2num(string str) {
	int ret = 0;
	for (int i = 0; i < str.length(); ++i) {
		ret = ret*10 + str[i] - '0';
	}
	return ret;
}

string convert(string str) {
	string ret = "";
	string tmpRet = "";
	int expPos = 0;
	while (str[expPos] != 'E') {
		tmpRet.push_back(str[expPos++]);
	}
	++expPos;
	int sign = str[expPos] == '+' ? 1 : -1;
	int exp = sign * str2num(str.substr(++expPos));
	
	int pointPos = 1;
	while (str[pointPos] != '.') {
		++pointPos;
	}
	
	if (exp == 0) {
		ret = tmpRet;
	} else if (exp > 0) {
		if (exp >= tmpRet.length() - pointPos - 1) {
			for (int i = 0; i < tmpRet.length(); ++i) {
				if (tmpRet[i] != '.') {
					ret.push_back(tmpRet[i]);
				}
			}
			for (int i = 0; i < exp - tmpRet.length() + pointPos + 1; ++i) {
				ret.push_back('0');
			}
		} else {
			for (int i = pointPos; i < pointPos + exp; ++i) {
				tmpRet[i] = tmpRet[i+1];
			}
			tmpRet[pointPos+exp] = '.';
			ret = tmpRet;
		}
	} else {
		ret.push_back(tmpRet[0]);
		ret.append("0.");
		for (int i = 1; i < -exp; ++i) {
			ret.push_back('0');
		}
		for (int i = 1; i < tmpRet.length(); ++i) {
			if (tmpRet[i] != '.') {
				ret.push_back(tmpRet[i]);
			}
		}
	}
	
	if (ret[0] == '+') {
		return ret.substr(1);
	} else {
		return ret;
	}
}

int main() {
	string str;
	getline(cin, str);
	cout << convert(str) << endl;
	return 0;
}
