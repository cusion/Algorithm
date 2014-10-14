#include <cstdio>
#include <iostream>
using namespace std;

int lengthOfLastWord(const char *s) {
	if (s == NULL || s[0] == '\0') {
		return 0;
	}
	
	int len = 0, lastLen = 0;
	
	for (int i = 0; s[i]!='\0'; ++i) {
		if (s[i]!=' ') {
			++len;
		} else {
			if (i == 0 || s[i-1] == ' ') continue;
			lastLen = len;
			len = 0;
		}
	}
	if (len) lastLen = len;
	
	return lastLen;
}

int main() {
	char s[] = "Hello World";
	cout << lengthOfLastWord(s);
	return 0;
}
