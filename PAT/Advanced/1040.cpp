#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int longestSymmetricString(string str) {
	if (str.length() <= 1) {
		return str.size();
	}
	
	bool dp[str.length()+1][str.length()];
	for (int i = 0; i <= str.length(); ++i) {
		for (int j = 0; j < str.length(); ++j) {
			dp[i][j] = false;
		}
	}
	for (int i = 0;i < str.length(); ++i) {
		dp[0][i] = true;
		dp[1][i] = true;
	}
	
	int len = 1;
	for (int i = 2; i <= str.length(); ++i) {
		for (int j = 0; j <= str.length()-i; ++j) {
			if (str[j] == str[j+i-1] && dp[i-2][j+1]) {
				dp[i][j] = true;
				if (len < i) {
					len = i;
				}
			} else {
				dp[i][j] = false;
			}
		}
	}
	
	/*for (int i = 0; i <= str.length(); ++i) {
		for (int j = 0; j < str.length(); ++j) {
			cout << dp[i][j] << " ";
		}puts("");
	}*/
	
	return len;
}

int main() {
	string str;
	getline(cin, str);
	cout << longestSymmetricString(str) << endl;
	return 0;
}
