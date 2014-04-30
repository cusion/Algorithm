#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
	for (int i = 0; i < s.length()/2; ++i) {
		if (s[i] != s[s.length()-i-1]) {
			return false;
		}
	}
	
	return true;
}
/*********************** Runtime Error *******************
struct Node {
	int i, j;
	int cnt;
	Node(int ii, int jj, int c):i(ii), j(jj), cnt(c){}
};

int minCut(string s) {
	if (s.size() <= 1 || isPalindrome(s)) {
		return 0;
	}
	bool dp[s.length()][s.length()+1];
	for (int i = 0; i < s.length(); ++i) {
		dp[i][0] = true;
		dp[i][1] = true;
	}
	
	for (int j = 2; j <= s.length(); ++j) {
		for (int i = 0; i < s.length()-j+1; ++i) {
			dp[i][j] = dp[i+1][j-2] && s[i]==s[i+j-1];
		}
	}
	
	queue<Node> q;
	q.push(Node(0,0,0));
	bool visit[s.length()][s.length()+1];
	for (int i = 0; i < s.length(); ++i) {
		for (int j = 0; j <= s.length(); ++j) {
			visit[i][j] = false;
		}
	}
	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();
		if (visit[tmp.i][tmp.j] == true) {
			continue;
		}
		if (tmp.i+tmp.j == s.length()) {
			return tmp.cnt-1;
		}
		visit[tmp.i][tmp.j] = true;
		for (int j = 1; j + tmp.i + tmp.j <= s.length(); ++j) {
			if (dp[tmp.i+tmp.j][j]) {
				q.push(Node(tmp.i+tmp.j, j, tmp.cnt+1));
			}
		}
	}
}*/
vector<vector<bool> > palin;
int minCut(string s) {
	if (s.size() <= 1 || isPalindrome(s)) {
		return 0;
	}
	int len = s.size();
	int dp[len+1];
	vector<bool> tmp(len, false);
	for (int i = 0; i < len; ++i) {
		palin.push_back(tmp);
	}
	for (int i = 0; i <= len; ++i) {
		dp[i] = len - i;
	}
	
	for (int i = len-1; i >= 0; i--) {
		for (int j = i; j < len; ++j) {
			if (s[i]==s[j] && (j-i<2 || palin[i+1][j-1])) {
				palin[i][j] = true;
				dp[i] = min(dp[i], dp[j+1]+1);
			}
		}
	}
	
	return dp[0]-1;
}


int main() {
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//string s = "abaababbbbabababaaaaaaaaaaab";
	cout << minCut(s) << endl;
	return 0;
}
