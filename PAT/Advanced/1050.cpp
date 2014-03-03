#include <cstdio>
#include <iostream>
#include <unordered_set>
using namespace std;

void stringSubtraction(char str[], unordered_set<char> &dict) {
	if (dict.empty()) {
		puts(str);
		return;
	}
	int indx = 0;
	while (str[indx]!='\0') {
		if (dict.find(str[indx]) == dict.end()) {
			printf("%c", str[indx]);
		}
		++indx;
	}
	
	return;
}

int main() {
	char str[10004];
	char dic[10004];
	unordered_set<char> dict;
	gets(str);
	gets(dic);
	int indx = 0;
	while (dic[indx] != '\0') {
		if (dict.find(dic[indx]) == dict.end()) {
			dict.insert(dic[indx]);
		}
		++indx;
	}
	stringSubtraction(str, dict);
	
	return 0;
}
