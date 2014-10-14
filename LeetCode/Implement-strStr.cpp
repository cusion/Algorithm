#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// compute nextval
void get_next(char * patrn, int len, vector<int> &nextval) {
	nextval[0] = -1;
	int i = 0;
	int j = -1;
	while (i < len-1) {
		if (j == -1 || patrn[i] == patrn[j]) {
			++i;
			++j;
			if (patrn[i] != patrn[j]) {
				nextval[i] = j;
			} else {
				//nextval[i] = nextval[j];
				int tmpJ = j;
				//cout << "========== test " << i << " ==============" << endl;
				while (tmpJ >= 0 && patrn[i] == patrn[tmpJ]) {
					//cout << tmpJ << endl;
					tmpJ = nextval[tmpJ];
				}
				//cout << tmpJ << endl;
				//cout << "==== end ===" << endl;
				nextval[i] = tmpJ;
			}
		} else {
			j = nextval[j];
		}
	}
	/*for (int i = 0; i < nextval.size(); ++i) {
		cout << nextval[i] << " ";
	}puts("");*/
}

// my compute nextval
// if there exists some common prefix && suffix(prefix must be different from suffix),
// then set its length to next[pos], otherwise we need to tell whether current character 
// equals to the first character or not, if they are equivalent then next[pos] = -1, else
// next[pos] = 0;
// previous matched length is not equivalent to next[cur-1], though there are some connections
// between them, so we must keep a record of the previous matched length rather than using 
// only next[cur-1];

/*void my_get_next(char *ptrn, int len, vector<int> &nextval) {
	nextval[0] = -1;
	nextval[1] = ptrn[1] == ptrn[0] ? -1 : 0;
	
	int preMatch = 0;
	for(int i = 2; i < len; ++i) {
		int tmpNext = preMatch;
		while (tmpNext >= 0 && ptrn[i-1] != ptrn[tmpNext]) {
			tmpNext = nextval[tmpNext];
		}
		preMatch = tmpNext + 1;
		if (ptrn[i] != ptrn[preMatch]) {
			nextval[i] = tmpNext + 1;
		} else {
			int tmpMatch = preMatch;
			while (tmpMatch >= 0 && ptrn[i] == ptrn[tmpMatch]) {
				tmpMatch = nextval[tmpMatch];
			}
			nextval[i] = tmpMatch;
		}
	}
	
	for (int i = 0; i < nextval.size(); ++i) {
		cout << nextval[i] << " ";
	}puts("");
}*/

char * kmp_search(char * haystack, int hlen, char * needle, int nlen, vector<int>&next) {
	int i = 0;
	int j = 0;
	while (i < hlen && j < nlen) {
		if (j == -1 || haystack[i] == needle[j]) {
			++i;
			++j;
		} else {
			j = next[j];
		}
	}
	if (j >= nlen) {
		return &haystack[i-nlen];
	} else {
		return NULL;
	}
}

char *strStr(char *haystack, char *needle) {
	if (haystack == NULL || needle == NULL) {
		return NULL;
	}
	int slen = strlen(haystack);
	int plen = strlen(needle);
	if (plen == 0) {
		return haystack;
	}
	if (slen == 0) {
		if (plen != 0) return NULL;
		else return haystack;
	}
	vector<int> nextval(plen, -1);
	
	// compute nextval
	get_next(needle, plen, nextval);
	
	return kmp_search(haystack, slen, needle, plen, nextval);
}

int main() {
	char str[] = "abb";
	vector<int> next1(3, 56);
	get_next(str, 3, next1);
	vector<int> next2(3, 56);
	my_get_next(str, 3, next2);
	return 0;
}
