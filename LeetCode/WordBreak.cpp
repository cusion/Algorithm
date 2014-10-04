#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

bool helper(string s, unordered_set<string> &dict, int start) {
	if (start >= s.length()) {
		return true;
	}
	for (auto it = dict.begin(); it != dict.end(); ++it) {
		int len = (*it).length();
		string word = "";
		if (start + len > s.length()) {
			word = s.substr(start, s.length()-start);
		} else {
			word = s.substr(start, len);
		}
		//cout << word << endl;
		if (dict.find(word) != dict.end() && helper(s, dict, start+len)) {
			return true;
		}
	}
	
	return false;
}

bool wordBreak(string s, unordered_set<string> &dict) {
	if (dict.empty()) {
		return false;
	}
	if (s.empty()) {
		return false;
	}
	unordered_set<char> letters;
	for (auto it = dict.begin(); it != dict.end(); ++it) {
		for (int i = 0; i < (*it).length(); ++i) {
			if (letters.find((*it)[i]) == letters.end()) {
				letters.insert((*it)[i]);
			}
		}
	}
	
	for (int i = 0; i < s.length(); ++i) {
		if (letters.find(s[i]) == letters.end()) {
			return false;
		}
	}
	
	return helper(s, dict, 0);
}

int main() {
	string s = "leetcode";
	unordered_set<string> dict = {"leet", "code"};
	cout << wordBreak(s, dict);
	return 0;
}
