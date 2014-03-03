#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct Result {
	string quotient;
	int remainder;
};

int char2num(string str, int ind, int len, int res) {
	int ret = res;
	for (int i = 0; i < len; ++i) {
		ret = ret*10 + str[ind+i] - '0';
	}
	return ret;
}

Result divide(string num, int p) {
	string quotient;
	int remainder = 0;
	
	int ind = 0;
	int res = 0;
	int len = 1;
	int tmp = 0;
	while (ind < num.size()) {
		if (ind + len > num.size()) {
			quotient.append(1, '0');
			res = tmp%p;
			break;
		}
		tmp = char2num(num, ind, len, res);
		if (tmp >= p) {
			quotient.append(1, '0' + tmp/p);
			res = tmp%p;
			ind += len;
			len = 1;
		} else {
			if (ind > 0) {
				quotient.append(1, '0');
			}
			if (tmp == 0) {
				++ind;
			} else {
				++len;
			}
		}
	}
	
	Result ret;
	ret.quotient = quotient.empty() ? "0" : quotient;
	ret.remainder = res;
	return ret;
}

int main() {
	
	string num;
	int p;
	cin >> num >> p;
	Result res = divide(num, p);
	cout << res.quotient << " " << res.remainder << endl;
	
	return 0;
}
