#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int coins[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &coins[i]);
	}
	sort(coins, coins+n, greater<int>());
	
	int dp[m+1];
	memset(dp, 0, sizeof(dp));
	vector <int> ans[m+1];
	
	//puts("test");
	for (int i = 0; i < n; ++i) {
		//cout << "coins[" << i << "] = " << coins[i] << endl;
		for (int j = m; j >= coins[i]; --j) {
			if (dp[j] <= dp[j-coins[i]] + coins[i]) {
				dp[j] = dp[j-coins[i]] + coins[i];
				//cout << j << " " << dp[j] << endl;
				ans[j].clear();
				for (auto it = ans[j-coins[i]].begin(); it != ans[j-coins[i]].end(); ++it) {
					ans[j].push_back((*it));
				}
				ans[j].push_back(coins[i]);
			}
		}
	}
	
	if (dp[m] != m) {
		cout << "No Solution" << endl;
	} else {
		cout << ans[m][ans[m].size()-1];
		for (int i = ans[m].size()-2; i >= 0; --i) {
			cout << " " << ans[m][i];
		}puts("");
	}
	
	return 0;
}


/*********************** DFS Time Limit Exceeded *******************
void dfs(int coins[], int len, int start, int sol[], int solIndx, int target, bool &stop) {
	if (stop) {
		return;
	}
	
	//cout << "===========" << target << " " << start << "==============" << endl;
	
	if (target == 0) {
		stop = true;
		if (solIndx > 0) {
			for (int i = 0; i < solIndx-1; ++i) {
				cout << sol[i] << " ";
			}
			cout << sol[solIndx-1] << endl;
		} else {
			puts("No Solution");
		}
		return;
	}
	
	for (int i = start; i < len; ++i) {
		if (!stop && target >= coins[i]) {
			sol[solIndx] = coins[i];
			//cout << "test " << coins[i] << endl;
			dfs(coins, len, i+1, sol, solIndx+1, target-coins[i], stop);
		} else {
			break;
		}
	}
}

void dfsMethod(int coins[], int len, int target) {
	int start = 0;
	int solution[len];
	int solIndx = 0;
	bool stop = false;
	dfs(coins, len, start, solution, solIndx, target, stop);
	if (!stop) {
		cout << "No Solution" << endl;
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	int coins[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &coins[i]);
	}
	sort(coins, coins+n);
	dfsMethod(coins, n, m);
	return 0;
}*/
