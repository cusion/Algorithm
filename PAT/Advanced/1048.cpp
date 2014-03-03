#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

// there is also a hash solution

int main() {
	int n, m;
	cin >> n >> m;
	int coins[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &coins[i]);
	}
	sort(coins, coins+n);
	
	int small = 0;
	int big = n-1;
	bool isFound = false;
	while (small < big) {
		int val = coins[small] + coins[big];
		if (val == m) {
			cout << coins[small] << " " << coins[big] << endl;
			isFound = true;
			break;
		} else if (val > m) {
			--big;
		} else {
			++small;
		}
	}
	
	if (!isFound) {
		puts("No Solution");
	}
	
	return 0;
}
