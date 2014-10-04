#include <iostream>
#include <cstdio>
using namespace std;

int getNext(const char * p) {
	int ind = 0;
	while(p[ind] == '*') ++ind;
	return ind;
}

bool isMatch(const char *s, const char *p) {
	int i;
	for (i = 0; s[i]!='\0' && p[i]!='\0'; ++i) {
		if (p[i] == '*') {
			int pn = getNext(&p[i]);
			if (p[i+pn] == '\0') {
				return true;
			} else {
				for (int j = i; s[j]!='\0';++j) {
					if (s[j] == p[i+pn] && isMatch(&s[j+1], &p[i+pn])) {
						return true;
					}
				}
				return false;
			}
		} else if (p[i] == '?') {
			continue;
		} else {
			if (s[i]!=p[i]) {
				return false;
			}
		}
	}
	
	if (s[i] == '\0') {
		int pn = getNext(&p[i]);
		if (p[i+pn]=='\0')return true;
		return false;
	}
	
	return false;
}

int main() {
	char str1[100];
	char str2[100];
	
	while(1) {
		gets(str1);
		gets(str2);
		puts("=================");
		puts(str1);
		puts(str2);
		if (isMatch(str1, str2)) {
			puts("Yes");
		} else {
			puts("No");
		}
		puts("#################");
	}
	
	return 0;
}
