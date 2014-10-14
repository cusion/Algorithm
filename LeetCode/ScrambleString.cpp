#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/******************** Recursive Method *************************
bool checkScramble(string s1, string s2) {
	if (s1 == s2) return true;
	
	string ss1 = s1;
	sort(ss1.begin(), ss1.end());
	string ss2 = s2;
	sort(ss2.begin(), ss2.end());
	if (ss1 != ss2) return false;
	
	for (int i = 1; i < s1.length(); ++i) {
		if (checkScramble(s1.substr(0, i), s2.substr(s2.length()-i, i)) && 
		    checkScramble(s1.substr(i, s1.length()-i), s2.substr(0, s2.length()-i))){
			return true;
		}
	}
	for (int i = 1;i < s1.length(); ++i) {
		if (checkScramble(s1.substr(0, i), s2.substr(0, i)) && 
		    checkScramble(s1.substr(i, s1.length()-i), s2.substr(i, s2.length()-i))){
			return true;
		}
	}
	return false;
}

bool isScramble(string s1, string s2) {
	if (s1.empty()) {
		if (s2.empty()) {
			return true;
		} else {
			return false;
		}
	}
	
	if (s1.length() != s2.length()) return false;
	
	return checkScramble(s1, s2);
}
*/
/***************** Dynamic Method ****************************/
bool isScramble(string s1, string s2) {
	int len = s1.length();
	if (len != s2.length()) return false;
	string ss1 = s1;
	sort(ss1.begin(), ss1.end());
	string ss2 = s2;
	sort(ss2.begin(), ss2.end());
	if (ss1 != ss2) return false;
	
	bool isScramb[len][len][len];
	//bool dp[len+1][len][len];
	/*for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			for (int k = 0; k < len; ++k) {
				isScramb[i][j][k] = false;
				dp[i][j][k] = dp[i+1][j][k] = false;
			}
		}
	}*/
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			isScramb[0][i][j] = (s1[i] == s2[j]);
			//dp[0][i][j] = true;
			//dp[1][i][j] = (s1[i] == s2[j]);
		}
	}
	
	for (int l = 1; l < len; ++l) {
		for (int st1 = 0; st1 < len-l; ++st1) {
			for (int st2 = 0; st2 < len-l; ++st2) {
				isScramb[l][st1][st2] = false;
				ss1 = s1.substr(st1, l+1);
				ss2 = s2.substr(st2, l+1);
				if (ss1 == ss2) {
					isScramb[l][st1][st2] = true;
				} else{
					for (int sep = 0; sep < l; ++sep) {
						if ((isScramb[sep][st1][st2] && isScramb[l-1-sep][st1+sep+1][st2+sep+1])
						  || (isScramb[sep][st1][st2+l-sep] && isScramb[l-1-sep][st1+sep+1][st2])) {
						  	isScramb[l][st1][st2] = true;
						  	break;
						}
					}
				}
			}
		}
	}
	/*
	for (int l = 2; l <= len; ++l) {
		for (int st1 = 0; st1 <= len-l; ++st1) {
			for (int st2 = 0; st2 <= len-l; ++st2) {
				dp[l][st1][st2] = false;
				ss1 = s1.substr(st1, l);
				ss2 = s2.substr(st2, l);
				if (ss1 == ss2) {
					dp[l][st1][st2] = true;
				} else{
					for (int sep = 1; sep < l; ++sep) {
						if ((dp[sep][st1][st2] && dp[l-sep][st1+sep][st2+sep]) || (dp[sep][st1][st2+l-sep] && dp[l-sep][st1+sep][st2])) {
							dp[l][st1][st2] = true;
							break;
						}
					}
				}
			}
		}
	}
	
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			for (int k = 0; k < len; ++k) {
				cout << isScramb[i][j][k] << " ";
			}
			cout << " ||  ";
			for (int k = 0; k < len; ++k) {
				cout << dp[i+1][j][k] << " ";
			}puts("");			
		}
		printf("=========%d=========\n", i);
	}
	*/
	return isScramb[len-1][0][0];
	//return dp[len][0][0];
}

int main() {
	string s1, s2;
	while (1) {
		cin >> s1 >> s2;
		cout << isScramble(s1, s2) << endl;
	}
	return 0;
}
