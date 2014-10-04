#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int min3(int a, int b, int c) {
	return min(min(a,b), c);
}

int minDistance(string word1, string word2) {
	int dp[word1.size()+1][word2.size()+1];
	
	for (int i = 0; i <= word1.size(); ++i) {
		dp[i][0] = i;
	}
	for (int i = 0; i <= word2.size(); ++i) {
		dp[0][i] = i;
	}
	
	for (int i = 1; i <= word1.size(); ++i) {
		for (int j = 1; j <= word2.size(); ++j) {
			//cout << dp[i-1][j] << " " << dp[i][j-1] << " " << dp[i-1][j-1] << endl;
			dp[i][j] = min3(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1));
		}
	}
	
	return dp[word1.size()][word2.size()];
}

int main () {
	string word1("a");
	string word2("b");
	
	cout << minDistance(word1, word2);
	
	return 0;
}
