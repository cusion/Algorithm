#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

/******************************** O(N^2) ***************************
However, this solution fails because the problem is to find the substring,
not the subsecquence, note the difference between the two problem.
/*void getLongestIndex(string &s, string &rs, vector<vector<int> > &dp, vector<int> &indx, int a, int b) {
	if (a == 0 || b == 0) return;
	if (s[a-1] == rs[b-1]) {
		indx.push_back(a-1);
		getLongestIndex(s, rs, dp, indx, a-1, b-1);
	} else {
		if (dp[a-1][b] > dp[a][b-1]) {
			getLongestIndex(s, rs, dp, indx, a-1, b);
		} else {
			getLongestIndex(s, rs, dp, indx, a, b-1);
		}
	}
}*/
/*int dp[1001][1001];
string longestPalindrome(string s) {
	string ret;
	if (s.empty()) {
		return ret;
	}
	if (s.size() == 1) {
		return s;
	}
	string rs = s;
	for (int i = 0; i < rs.size()/2; ++i) {
		char ch = rs[i];
		rs[i] = rs[rs.size()-1-i];
		rs[rs.size()-1-i] = ch;
	}
	//cout << s << endl;
	//cout << rs << endl;
	
	//vector<vector<int> > dp(s.size()+1, vector<int>(s.size()+1));
	//int dp[s.size()+1][s.size()+1];
	for (int i = 0; i <= s.size(); ++i) {
		dp[0][i] = dp[i][0] = 0;
	}
	
	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 1; j <= s.size(); ++j) {
			if (s[i-1] == rs[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	cout << dp[s.size()][s.size()] << endl;
	system("pause");
	vector<int> indx;
	//getLongestIndex(s, rs, dp, indx, s.size(), s.size());
	int x = s.size();
	int y = s.size();
	int cnt = dp[s.size()][s.size()];
	while (cnt > 0) {
		if (s[x-1] == rs[y-1]) {
			indx.push_back(x-1);
			--x;
			--y;
			--cnt;
		} else {
			if (dp[x-1][y] > dp[x][y-1]) {
				--x;
			} else {
				--y;
			}
		}
	}
	
	for (int i = indx.size()-1; i >= 0; --i) {
		ret.push_back(s[indx[i]]);
	}
	
	return ret;
}*/
/*********************** O(N^2) solution using DP ****************
void print(vector<vector<bool> > dp) {
	for (int i = 0; i < dp.size(); ++i) {
		for (int j = 0; j < dp[0].size(); ++j) {
			cout << dp[i][j] << " ";
		}puts("");
	}
}
string longestPalindrome(string s) {
	string ret;
	if (s.empty()) {
		return ret;
	}
	int start = 0, len = 1;
	//bool dp[s.size()][s.size()];
	vector<vector<bool> > dp(s.size(), vector<bool>(s.size()));
	for (int i = 0; i < s.size(); ++i) {
		dp[i][i] = true;
		if (i < s.size()-1) {
			dp[i][i+1] = s[i] == s[i+1] ? true:false;
			if (dp[i][i+1]){
				start = i;
				len = 2;
			}
		}
	}
	//print(dp);
	for (int i = 3; i <= s.size(); ++i) {
		for (int j = 0; j+i <= s.size(); ++j) {
			dp[j][j+i-1] = dp[j+1][j+i-2] && (s[j] == s[j+i-1]);
			if (dp[j][j+i-1]) {
				start = j;
				len = i;
			}
		}
	}
	
	return s.substr(start, len);
}*/

/*********************** O(N^2) using search ***************
// enumerate the center point of the palindrome, for each center
// point, find its longest palindrome, and compares with the current
// longest palindrome
string longestPalindrome(string s) {
	if (s.size() <= 1) {
		return s;
	}
	int start = 0;
	int len = 1;
	for (int i = 0; i < s.size(); ++i) {
		int step1 = 1;
		while ((i-step1>=0) && (i+step1<s.size()) && (s[i-step1]==s[i+step1])) {
			++step1;
		}
		if (len < 2*step1-1) {
			start = i-step1+1;
			len = 2*step1-1;
		}
		int step2 = 1;
		if (i+1<s.size() && s[i]==s[i+1]) {
			while ((i-step2>=0) && (i+1+step2<s.size()) && (s[i-step2] == s[i+1+step2])) {
				++step2;
			}
			if (len < 2*step2) {
				start = i-step2+1;
				len = 2*step2;
			}
		}
	}
	return s.substr(start, len);
}*/

/***************** O(N) solution ****************/
// Manacher's Algorithm
string longestPalindrome(string s) {
	if (s.size() <= 1) {
		return s;
	}
	string s1 = "#";
	for (int i = 0; i < s.size(); ++i) {
		s1.push_back(s[i]);
		s1.push_back('#');
	}
	int expand[s1.length()];
	int pivot = 0, cover = 0;
	for (int i = 0; i < s1.length(); ++i) {
		if (cover > i) {
			expand[i] = min(expand[2*pivot-i], cover-i);
		} else {
			expand[i] = 0;
		}
		while (i-expand[i] >= 0 && i+expand[i] < s1.length() && s1[i-expand[i]] == s1[i+expand[i]]) {
			expand[i]++;
		}
		--expand[i];
		if (i+expand[i] > cover) {
			cover = i + expand[i];
			pivot = i;
		}
	}
	int maxLen = 0, maxId = 0;
	for (int i = 0; i < s1.size(); ++i) {
		if (maxLen < expand[i]) {
			maxLen = expand[i];
			maxId = i;
		}
	}
	
	return s.substr((maxId-maxLen)/2, maxLen);
}

int main() {
	string s = "aabddbabdg";
	//string s = "abb";
	cout << longestPalindrome(s) << endl;
	return 0;
}
