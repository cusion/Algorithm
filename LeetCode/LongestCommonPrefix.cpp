#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/********************** Method 2 **********************/
bool isMatchAll(vector <string> &strs, int left, int right, int indx) {
	if (indx >= strs[right].size() || indx >= strs[left].size()) {
		return false;
	}
	if (left == right) {
		return true;
	}
	int mid = (left + right)/2;
	if (isMatchAll(strs, left, mid, indx) && isMatchAll(strs, mid+1, right, indx)) {
		if (strs[left][indx] == strs[right][indx]) {
			return true;
		}
	}
	return false;
}
string longestCommonPrefix(vector <string> &strs) {
	string ret = "";
	if (strs.empty()) {
		return ret;
	}
	if (strs.size() == 1) {
		return strs[0];
	}
	for (int i = 0; i < strs[0].size(); ++i) {
		if (isMatchAll(strs, 0, strs.size()-1, i)) {
			ret.append(1, strs[0][i]);
		} else {
			break;
		}
	}
	
	return ret;
}

/********************* Method 1 **********************

string longestCommonPrefix(vector <string> &strs) {
	string ret = "";
	if (strs.empty()) {
		return ret;
	}
	
	if (strs.size() == 1) {
		return strs[0];
	}
	
	for (int i = 0; i < strs[0].size(); ++i) {
		char ch = strs[0][i];
		bool isSame = true;
		for (int j = 1; j < strs.size(); ++j) {
			if (i >= strs[j].size() || ch != strs[j][i]) {
				cout << i << j << endl;
				isSame = false;
				break;
			}
		}
		if (isSame) {
			ret.append(1, ch);
		} else {
			break;
		}
	}
	
	return ret;
}*/

/* This is a wrong understanding of the problem
int getCommonPrefix(string str1, string str2) {
	int ind = 0;
	while (ind < str1.size() && ind < str2.size() && str1[ind] == str2[ind]) ++ind;
	
	return ind;
}

string longestCommonPrefix(vector <string> &strs) {
	string ret = "";
	if (strs.empty()) return ret;
	if (strs.size() == 1) return strs[0];
	
	for (int i = 0;i < strs.size(); ++i) {
		for (int j = i+1; j < strs.size(); ++j) {
			int len = getCommonPrefix(strs[i], strs[j]);
			if (len > ret.size()) {
				ret = strs[i].substr(0, len);
			}
		}
	}
	
	return ret;
}*/

int main() {
	vector <string> strs;
	strs.push_back("aca");
	strs.push_back("acba");
	cout << longestCommonPrefix(strs) << endl;
	return 0;
}
