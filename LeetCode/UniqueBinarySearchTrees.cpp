#include <cstdio>
#include <iostream>

using namespace std;

int numTrees(int n) {
	int dp[n+1];
	
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = 0;
		for (int j = 1; j <= i; ++j) {
			dp[i] += dp[j-1]*dp[i-j];
		}
	}
	
	return dp[n];
}

int main() {
	int n;
	while(1){
		cin >> n;
		cout << numTrees(n) << endl;
	}
	return 0;
}
