#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

/*****************************************************
/* The thought behind this algorithm is simple, just a 
/* greedy method, however, the coding is too much complicated,
/* and I do not want to simplify it right now, a future look back
/* may be helpful for improvment about myself. During the 
/* coding process, I have made a lot of small mistakes, such as
/* misundertaking the boundary conditions, and missing index etc.
/* It should be paid more attention about thoughtfully coding.
*/
void getSubstr(int &l, int &r, const char * p) {
	if (l==0 && p[l] == '*') {
		l = -2;
		r = -1;
		return;
	}
	l = r+1;
	while (p[l]=='*')++l;
	r = l;
	while (p[r]!='*' && p[r]!= '\0')++r;
	--r;
}

bool greedyMatch(int &sl, int slen, const char * s, int pl, int pr, const char * p) {
	if (pr < 0) return true;
	int len = pr - pl + 1;
	if (pl == 0) slen = len > slen ? slen : len;
	for (int i = 0; slen-sl-i >= len; ++i) {
		if (s[sl+i] == p[pl] || p[pl]=='?') {
			int j=1;
			for (j=1; j < len; ++j) {
				if (s[sl+i+j]!=p[pl+j] && p[pl+j]!='?') break;
			}
			if (j == len ) {
				sl += i+j;
				return true;
			}
		}
	}
	return false;
}

bool isMatch(const char *s, const char *p) {
	
	if (p == NULL) {
		if (s == NULL) return true;
		else return false;
	}
	
	int slen = 0;
	while(s[slen]!='\0')++slen;
	
	int pSubl=0, pSubr=-1, sSubl=0, sSubr;
	while (1) {
		getSubstr(pSubl, pSubr, p);
		
		if (pSubl >= 0) {
			for (int i = pSubl; i <= pSubr; ++i) {
				cout << p[i];
			}puts("");
			system("pause");
		}
		
		if (pSubl > 0 && p[pSubl]=='\0') break;
		
		if (p[pSubr+1] == '\0') {
			puts("1");
			if (pSubl == 0) {
				for (int i = 0; i < slen; ++i) {
					if (s[i] != p[i] && p[i]!='?') return false;
				}
				if (p[slen] != '\0') return false;
				return true;
			}
			sSubr = slen-1;
			if (sSubr - sSubl < pSubr - pSubl) return false;
			for (int i = pSubr-pSubl; i >= 0; --i) {
				if (p[pSubr-i] != s[sSubr-i] && p[pSubr-i]!='?') {
					return false;
				}
			}
			return true;
		} else {
			puts("2");
			puts(&s[sSubl]);
			if (!greedyMatch(sSubl, slen, s, pSubl, pSubr, p)) {
				return false;
			}
		}
	}
	//puts("test");
	if (p[pSubl-1] != '*') return false;
	return true;
}

int main() {
	char str1[100];
	char str2[100];
	while(1) {
		gets(str1);
		gets(str2);
		puts("===================");
		puts(str1);
		puts(str2);
		if (isMatch(str1, str2)) {
			puts("Yes");
		} else {
			puts("No");
		}
		puts("###################");
	}
	
	return 0;
}
