#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

/************* TLE version ****************
bool helper(string s1, string s2, string s3, int idx1, int idx2, int idx3) {
	if (idx3 < 0 && idx1 < 0 && idx2 < 0) return true;
	char ch = s3[idx3];
	if (idx1>=0 && ch == s1[idx1]) {
		--idx1, --idx3;
		if (helper(s1, s2, s3, idx1, idx2, idx3)) {
			return true;
		}
		++idx1, ++idx3;
	}
	if (idx2 >= 0 && ch == s2[idx2]) {
		--idx2, --idx3;
		if (helper(s1, s2, s3, idx1, idx2, idx3)) {
			return true;
		}
		++idx2, ++idx3;
	}
	
	return false;
}

bool isInterleave(string s1, string s2, string s3) {
	if (s1.empty() && s2.empty() && s3.empty()) return true;
	if (s3.length() != s1.length() + s2.length()) {
		return false;
	}
	unordered_map<char, int> charCnt;
	for (int i = 0; i < s1.length(); ++i) {
		charCnt[s1[i]]++;
	}
	for (int i = 0; i < s2.length(); ++i) {
		charCnt[s2[i]]++;
	}
	int cnt = charCnt.size();
	for (int i = 0; i < s3.length(); ++i) {
		if (charCnt.find(s3[i]) == charCnt.end()) {
			return false;
		} else if (charCnt[s3[i]] <= 0) {
			return false;
		} else {
			charCnt[s3[i]]--;
		}
	}
	
	return helper(s1, s2, s3, s1.length()-1, s2.length()-1, s3.length()-1);
}*/

/*********************** Also TLE **********************
struct Node {
	int len1;
	int len2;
	Node(){}
	Node(int l1, int l2):len1(l1),len2(l2) {}
};

bool isInterleave(string s1, string s2, string s3) {
	if (s1.empty() && s2.empty() && s3.empty()) {
		return true;
	}
	if (s1.length() + s2.length() != s3.length()) {
		return false;
	}
	unordered_map<char, int> charCnt;
	for (int i = 0; i < s1.length(); ++i) {
		charCnt[s1[i]]++;
	}
	for (int i = 0; i < s2.length(); ++i) {
		charCnt[s2[i]]++;
	}
	int cnt = charCnt.size();
	for (int i = 0; i < s3.length(); ++i) {
		if (charCnt.find(s3[i]) == charCnt.end()) {
			return false;
		} else if (charCnt[s3[i]] <= 0) {
			return false;
		} else {
			charCnt[s3[i]]--;
		}
	}
	queue<Node> q;
	q.push(Node(0,0));
	for (int i = 1; i <= s3.length(); ++i) {
		int qsize = q.size();
		while (qsize--) {
			Node tmp = q.front();
			q.pop();
			if (tmp.len1 < s1.length() && s1[tmp.len1] == s3[i-1]) {
				q.push(Node(tmp.len1+1, tmp.len2));
			}
			if (tmp.len2 < s2.length() && s2[tmp.len2] == s3[i-1]) {
				q.push(Node(tmp.len1, tmp.len2+1));
			}
		}
		if (q.size() == 0) {
			return false;
		}
	}
	
	return true;
}*/

bool isInterleave(string s1, string s2, string s3) {
	if (s1.empty() && s2.empty() && s3.empty()) {
		return true;
	}
	if (s1.length()+s2.length() != s3.length()) {
		return false;
	}
	vector<vector<bool> > dp(s1.length()+1, vector<bool>(s2.length()+1, false));
	dp[0][0] = true;
	for (int i = 1; i <= s1.length(); ++i) {
		dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
	}
	for (int i = 1; i <= s2.length(); ++i) {
		dp[0][i] = dp[0][i-1] && (s2[i-1] == s3[i-1]);
	}
	
	for (int i = 1; i <= s1.length(); ++i) {
		for (int j = 1; j <= s2.length(); ++j) {
			if ((dp[i-1][j]&&s1[i-1]==s3[i+j-1]) || (dp[i][j-1]&&s2[j-1]==s3[i+j-1])) {
				dp[i][j] = true;
			}
		}
	}
	/*for (int i = 0; i <= s1.length(); ++i) {
		for (int j = 0; j <= s2.length(); ++j) {
			cout << dp[i][j] << " ";
		}puts("");
	}*/
	
	return dp[s1.length()][s2.length()];
}

int main() {
	string s1 = "ab";
	string s2 = "bc";
	string s3 = "bbac";
	if (isInterleave(s1, s2, s3)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	return 0;
}
