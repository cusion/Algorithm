#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string s, int st, int ed) {
	for (int i = st, j = ed; i < j; ++i, --j ) {
		if (s[i]!=s[j])return false;
	}
	return true;
}

void myPartition(int indx, string s, vector <string> vec, vector <vector <string> > &ret) {
	if (indx >= s.length()) {
		ret.push_back(vec);
		return ;
	}
	string stmp;
	for (int i = indx; i < s.length(); ++i) {
		if (isPalindrome(s, indx, i)) {
			stmp.assign(s, indx, i-indx+1);
			vec.push_back(stmp);
			myPartition(i+1,s, vec, ret);
			vec.pop_back();
		}
	}
}

vector <vector <string> > partition(string s) {
	vector <vector <string> > ret;
	if (s.empty())  return ret;
	vector <string> vec;
	if (s.length() == 1) {
		vec.push_back(s);
		ret.push_back(vec);
		return ret;
	}
	myPartition(0, s, vec, ret);
	
	return ret;
}

int main() {
	string s;
	cin >> s;
	vector <vector<string> > ret = partition(s);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}puts("");
	}
	return 0;
}
