#include <cstdio>
#include <iostream>
#include <string>
#include <climits>
using namespace std;

string itoa(int num) {
	string ret = "";
	if (num == 0) {
		ret.push_back('0');
		return ret;
	}
	int n = num;
	int sign = num > 0 ? 1 : -1;
	while (n) {
		ret.push_back((n%10)*sign + '0');
		n /= 10;
	}
	if (sign < 0) {
		ret.push_back('-');
	}
	
	for (int i = 0; i < ret.size()/2; ++i) {
		char tmp = ret[i];
		ret[i] = ret[ret.size()-1 - i];
		ret[ret.size()-1 - i] = tmp;
	}
	
	return ret;
}

int compare(string aa, string bb) {
	int signa = aa[0] == '-' ? -1 : 1;
	int signb = bb[0] == '-' ? -1 : 1;
	if (signa != signb) {
		return signa-signb;
	}
	string a = "";
	string b = "";
	
	int idx = signa > 0 ? 0 : 1;
	while (aa[idx] == '0') {
		++idx;
	}
	a = aa.substr(idx, aa.size()-idx);
	
	idx = signb > 0 ? 0 : 1;
	while (bb[idx] == '0') {
		++idx;
	}
	b = bb.substr(idx, bb.size()-idx);
	
	if (a.length() != b.length()) {
		return (a.length()-b.length())*signa;
	}
	idx = 0;
	while (idx < a.size()) {
		if (a[idx] != b[idx]) {
			return (a[idx]-b[idx])*signa;
		}
		++idx;
	}
	
	return 0;
}

int convert(string numbers) {
	if (numbers.empty()) {
		return 0;
	}
	
	int start = 0;
	int sign = 1;
	if (numbers[start] == '-') {
		sign = -1;
		++start;
	}
	
	if (sign < 0 && compare(itoa(INT_MIN), numbers) > 0) {
		return INT_MIN;
	}
	if (sign > 0 && compare(itoa(INT_MAX), numbers) < 0) {
		return INT_MAX;
	}
	
	int ret = 0;
	for (int i = start; i < numbers.size(); ++i) {
		ret = ret*10 + sign*(numbers[i]-'0');
	}
	
	return ret;
}

int atoi(const char *str) {
	if (str == NULL) {
		return 0;
	}
	string numbers;
	int idx = 0;
	// ignore leading whitespaces
	while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n') {
		++idx;
	}
	
	// get sign
	if (str[idx] == '-' || str[idx] == '+') {
		if (str[idx++] == '-') {
			numbers.push_back('-');
		}
	}
	
	// get numbers
	while (str[idx] >= '0' && str[idx] <= '9') {
		numbers.push_back(str[idx++]);
	}
	
	return convert(numbers);
}

int main() {
	char str[] = "1";
	cout << atoi(str) << endl;
	return 0;
}
