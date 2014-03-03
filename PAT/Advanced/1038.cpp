#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment {
	string str;
	
	Segment(string st):str(st){}
	Segment(){}
	
	/*bool operator <(Segment &seg) {
		string a = str;
		a.append(seg.str);
		string b = seg.str;
		b.append(str);
		
		return a < b;
	}*/
	friend bool operator <(Segment a, Segment b) {
		string astr = a.str;
		astr.append(b.str);
		string bstr = b.str;
		bstr.append(a.str);
		
		return astr < bstr;
	}
};

int main() {
	vector <Segment> seg;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		seg.push_back(Segment(str));
	}
	sort(seg.begin(), seg.end());
	string res = "";
	for (int i = 0; i < n; ++i) {
		res.append(seg[i].str);
	}
	int start = 0;
	for (start = 0; start < res.length(); ++start) {
		if (res[start] != '0') {
			break;
		}
	}
	if (start == res.length()) {
		cout << "0" << endl;
	} else {
		for (; start < res.length(); ++start) {
			cout << res[start];
		}puts("");
	}
	return 0;
}
