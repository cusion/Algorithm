#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <cstring>
using namespace std;

int cnt[1000004];

void countClicks(int n, int *cnt, unordered_set<int> &nums) {
	if (cnt[n] > 0) {
		return;
	}
	if (n < 10 && nums.find(n) != nums.end()) {
		cnt[n] = 1;
		return;
	} else if (n < 3 && nums.find(n) == nums.end()){
		cnt[n] = -1;
		return;
	}
	int tmpN = n;
	int tmpCnt = 0;
	while (tmpN) {
		if (nums.find(tmpN%10) != nums.end()) {
			tmpCnt++;
		} else {
			tmpCnt = -1;
			break;
		}
		tmpN /= 10;
	}
	
	if (tmpCnt > 0) {
		cnt[n] = tmpCnt;
	}
	
	for (int i = n-1; i*i >= n && i > 1; --i) {
		if ((n % i) == 0) {
			countClicks(n/i, cnt, nums);
			countClicks(i, cnt, nums);
			if (cnt[i] > 0 && cnt[n/i] > 0) {
				if (cnt[n] < 0 || cnt[n] > cnt[n/i] + cnt[i]) {
					cnt[n] = cnt[n/i] + cnt[i] + 1;
				}
			}
		}
	}
}

int main() {
	int T, X;
	cin >> T;
	unordered_set<int> nums;
	for (int i = 1; i <= T; ++i) {
		nums.clear();
		for (int j = 0; j < 10; ++j) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 1) {
				nums.insert(j);
			}
		}
		cin >> X;
		if (X < 0) {
			cout << "Case #" << i << ": Impossible" << endl;
			continue;
		}
		memset(cnt, -1, sizeof(int)*(X+1));
		/*for (int k = 0; k <= X; ++k) {
			cnt[k] = -1;
		}*/
		countClicks(X, cnt, nums);
		/*for (int i = 0; i <= X; ++i) {
			printf("%d : %d\n", i, cnt[i]);
		}*/
		if (cnt[X] > 0) {
			cout << "Case #" << i << ": " << cnt[X]+1 << endl;
		} else {
			cout << "Case #" << i << ": Impossible" << endl;
		}
	}
	return 0;
}
