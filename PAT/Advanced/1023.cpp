#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string doubleStringNum(string num) {
	int inc = 0;
	string ret = "";
	for (int i = num.length()-1; i >= 0; --i) {
		int res = (num[i]-'0')*2+inc;
		ret.push_back(res%10+'0');
		inc = res/10;
	}
	if (inc > 0) {
		ret.push_back(inc+'0');
	}
	
	for (int i = 0;i < ret.length()/2; ++i) {
		char ctmp = ret[i];
		ret[i] = ret[ret.length()-i-1];
		ret[ret.length()-i-1] = ctmp;
	}
	
	return ret;
}

int main() {
	string str;
	cin >> str;
	string dstr = doubleStringNum(str);
	if (str.size() != dstr.size()) {
		cout << "No" << endl;
	} else {
		string dstrTmp = dstr;
		sort(str.begin(), str.end());
		sort(dstrTmp.begin(), dstrTmp.end());
		if (str == dstrTmp) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	cout << dstr << endl;	
	
	return 0;
}
