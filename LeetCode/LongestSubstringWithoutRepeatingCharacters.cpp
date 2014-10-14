#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
	if (s.empty()) {
		return 0;
	}
	unordered_map<char, bool> umap;
	int ret = 1;
	int start = 0;
	int end = 1;
	umap[s[0]] = true;
	while (end < s.length()) {
		auto itr = umap.find(s[end]);
		if (itr == umap.end() || umap[s[end]] == false) {
			umap[s[end]] = true;
		} else {
			ret = end-start > ret ? (end-start) : ret;
			while (start < end && umap[s[end]] == true) {
				umap[s[start++]] = false;
			}
			umap[s[end]] = true;
		}
		++end;
	}
	ret = end-start > ret ? (end-start) : ret;
	
	return ret;
}

int main() {
	return 0;
}
