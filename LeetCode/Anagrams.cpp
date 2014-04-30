#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string getKey(const string &str) {
	if (str.empty()) {
		return "";
	}
	vector<int> cnt(26, 0);
	for (int i = 0; i < str.size(); ++i) {
		cnt[str[i]-'a']++;
	}
	string ret = "";
	for (int i = 0; i < cnt.size(); ++i) {
		if (cnt[i] > 0) {
			ret.push_back('a'+i);
			int tmp = cnt[i];
			while (tmp) {
				ret.push_back('0'+(tmp%10));
				tmp /= 10;
			}
		}
	}
	return ret;
}

vector<string> anagrams(vector<string> &strs) {
	vector<string> ret;
	if (strs.empty()) {
		return ret;
	}
	unordered_map<string, vector<int> > anaGroups;
	for (int i = 0; i < strs.size(); ++i) {
		string key = getKey(strs[i]);
		if (anaGroups.find(key) != anaGroups.end()) {
			anaGroups[key].push_back(i);
		} else {
			vector<int> tmp(1, i);
			anaGroups[key] = tmp;
		}
	}
	
	for (auto it = anaGroups.begin(); it != anaGroups.end(); ++it) {
		if (it->second.size() > 1) {
			for (int i = 0; i < it->second.size(); ++i) {
				ret.push_back(strs[it->second[i]]);
			}
		}
	}
	return ret;
}

int main() {
	return 0;
}
