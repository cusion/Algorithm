#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// recursion

/*bool isMatch(const char *s, const char *p) {
	if (s == NULL || p == NULL) {
		return false;
	}
	if (*p == '\0') {
		return *s == '\0';
	}
	
	if (p[1] != '*') {
		if (s[0] == p[0] || (p[0] == '.' && s[0] != '\0')) {
			return isMatch(s+1, p+1);
		} else {
			return false;
		}
	} else {
		while (*s == p[0] || (p[0] == '.' && *s != '\0')) {
			if (isMatch(s, p+2)) {
				return true;
			}
			++s;
		}
	}
	
	return isMatch(s, p+2);
}*/


// dp
void print(vector<vector<bool> > matrix) {
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			cout << matrix[i][j] << " ";
		}puts("");
	}
}
bool isMatch(const char *s, const char *p) {
	if (s == NULL || p == NULL) {
		return false;
	}
	if (*p == '\0') {
		return *s == '\0';
	}
	int slen = strlen(s);
	int plen = strlen(p);
	vector<vector<bool> > isMatch(plen+1, vector<bool>(slen+1, false));
	
	// initialize
	for (int i = 1; i <= slen; ++i) {
		isMatch[0][i] = false;
	}
	bool matchTmp = true;
	isMatch[0][0] = true;
	isMatch[1][0] = false;
	// the reason to start from 2 is to avoid special case that the first character of p is '*'
	// here we assume that '*' greedily match the preceding one;
	for (int i = 2; i <= plen; ++i) {
		if (matchTmp && p[i-1] == '*') {
			isMatch[i][0] = true;
		} else {
			if (i%2 == 0) {
				matchTmp = false;
			}
			isMatch[i][0] = false;
		}
	}
	
	for (int i = 1; i <= plen; ++i) {
		for (int j = 1; j <= slen; ++j) {
			if (p[i-1] == '*' && i > 1) {
				for (int k = 0; k <= j; ++k) {  // length for x* to match
					if (p[i-2] == '.' || k == 0 || (p[i-2] == s[j-k])) {
						if (isMatch[i-2][j-k]) {
							isMatch[i][j] = true;
							break;
						}
					} else {
						break;
					}
				}
			} else {
				isMatch[i][j] = isMatch[i-1][j-1] && (p[i-1]==s[j-1] || (p[i-1] == '.'));
			}
		}
	}
	print(isMatch);
	
	return isMatch[plen][slen];
}

int main() {
	char a[] = "aa";
	char b[] = "a";
 	cout << isMatch(a, b) << endl;
	return 0;
}
