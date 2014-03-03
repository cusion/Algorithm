#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

void myWordBreak(string &s, int st, unordered_set<string> &dict, vector <int> &lenOpt, int &lensize, vector<string> &ret, string &sen) {
	if (st == s.size()) {
		ret.push_back(sen);
		return;
	}
	for (int i = 0; i < lensize; ++i) {
		if (st+lenOpt[i] > s.size()) break;
		string word = s.substr(st, lenOpt[i]);
		if (dict.find(word) != dict.end()) {
			int tmp = sen.length();
			if (sen.empty()) {
				sen.append(word);
				myWordBreak(s, st+lenOpt[i], dict, lenOpt, lensize, ret, sen);
				sen.erase(tmp, lenOpt[i]);
			} else {
				sen.append(1, ' ');
				sen.append(word);
				myWordBreak(s, st+lenOpt[i], dict, lenOpt, lensize, ret, sen);
				sen.erase(tmp, lenOpt[i]+1);
			}
		}
	}
}

int getId(char ch) {
	return (int)ch;
}

vector <string> wordBreak(string s, unordered_set<string> &dict) {
	vector <string> ret;
	if (s.empty() || dict.empty()) return ret;
	
	int letters[256];
	for (int i = 0; i < 256; ++i) {
		letters[i] = 0;
	}
	vector <int> lenOpt;
	
	unordered_set<string>::iterator itr;
	for (itr = dict.begin(); itr != dict.end(); ++itr) {
		lenOpt.push_back((*itr).size());
		for (int i = 0; i < (*itr).length(); ++i) {
			++letters[getId((*itr)[i])];
		}
	}
	
	for (int i = 0; i < s.length(); ++i) {
		if (letters[getId(s[i])] == 0) {
			return ret;
		}
	}
	
	sort(lenOpt.begin(), lenOpt.end());
	int ind = 1;
	for (int i = 1; i < lenOpt.size(); ++i) {
		if (lenOpt[i] != lenOpt[i-1]) {
			lenOpt[ind++] = lenOpt[i];
		}
	}
	string sentence = "";
	myWordBreak(s, 0, dict, lenOpt, ind, ret, sentence);
	
	return ret;
}

int main() {
	string s = "aaaaaaaa";
	unordered_set<string> dict = {"a","aa","aaa", "aaaa"};
	vector <string> ret = wordBreak(s, dict);
	sort(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << endl;
	}
	return 0;
}
