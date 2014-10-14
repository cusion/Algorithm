#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

/******************** Recursive way ***************************
void helper(string S, string T, int &num, int inds, int indt) {
	if (indt == T.size()) {
		++num;
		return;
	}
	for (int i = inds; S.length()-i >= T.length()-indt; ++i) {
		if (S[i] == T[indt]) {
			//cout << i << " " << S[i] << endl;
			helper(S, T, num, i+1, indt+1);
		}
	}
}

int numDistinct(string S, string T) {
	if (S.empty()) {
		return 0;
	}
	if (T.empty())) {
		return 1;
	}
	int num = 0;
	helper(S, T, num, 0, 0);
	
	return num;
} */

// DP solution
// Another beautiful solution : http://yucoding.blogspot.com/2013/01/leetcode-question-27-distinct.html
int numDistinct(string S, string T) {
	if (S.empty()) {
		return 0;
	}
	if (T.empty()) {
		return 1;
	}
	int num[S.length()+1][T.length()+1];
	
	// initialization, note the order should not be changed
	for (int i = 0; i <= T.length(); ++i) {
		num[0][i] = 0;
	}
	for (int i = 0; i <= S.length(); ++i) {
		num[i][0] = 1;
	}
	
	for (int i = 1; i <= T.length(); ++i) {
		for (int j = 1; j <= S.length(); ++j) {
			if (T[i-1] == S[j-1]) {
				num[j][i] = num[j-1][i] + num[j-1][i-1];
			} else {
				num[j][i] = num[j-1][i];
			}
		}
	}
	
	/*for (int i = 0; i <= S.length(); ++i) {
		for (int j = 0; j <= T.length(); ++j) {
			cout << num[i][j] << " ";
		}puts("");
	}*/
	
	return num[S.length()][T.length()];
}

int main() {
	string S = "aaab";
	string T = "aab";
	cout << numDistinct(S, T);
	return 0;
}
