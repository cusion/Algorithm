#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverseWords(string &s) {
	if (s.empty()) {
		return ;
	}
	vector <string> words;
	string tmp = "";
	int ind = 0;
	while (ind < s.length()) {
		tmp = "";
		while (ind < s.length() && s[ind] == ' ') {
			++ind;
		}
		while (ind < s.length() && s[ind] != ' ') {
			tmp.append(1, s[ind]);
			++ind;
		}
		if (!tmp.empty()) {
			words.push_back(tmp);
		}
	}
	s.clear();
	if (!words.empty()) {
		s.append(words[words.size()-1]);
		for (int i = words.size()-2; i >= 0; --i) {
			s.append(1, ' ');
			s.append(words[i]);
		}
	}
	
	return ;
}

int main() {
	return 0;
}
