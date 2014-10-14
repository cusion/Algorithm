#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int COLOR = 5;
const int NUM = 5;

int char2int(char ch) {
	if (ch >= '0' && ch <= '9') {
		return ch-'0'-1;
	}
	if (ch == 'R') {
		return 0;
	} else if (ch == 'G') {
		return 1;
	} else if (ch == 'B') {
		return 2;
	} else if (ch == 'Y') {
		return 3;
	} else if (ch == 'W') {
		return 4;
	}
	
	return -1;
}

inline int getOnes(int n) {
	int cnt = 0;
	while (n) {
		++cnt;
		n = n&(n-1);
	}
	return cnt;
}

inline int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	int n;
	int board[COLOR][NUM];
	char card[5];
	cin >> n;
	memset(board, 0, sizeof(board));
	for (int i = 0; i < n; ++i) {
		scanf("%s", card);
		board[char2int(card[0])][char2int(card[1])] = 1;
	}
	
	int ans = 100;
	for (int i = 0; i < (1<<10); ++i) {
		int cnt = getOnes(i);
		
		int colorOnly[COLOR] = {0};
		int numOnly[NUM] = {0};
		int notMarked = 0;
		
		for (int r = 0; r < COLOR; ++r) {
			for (int c = 0; c < NUM; ++c) {
				if (board[r][c] == 1) {
					if (((i&(1<<r))) > 0) {
						if ((i&(1<<(c+5))) > 0) {
							continue;
						} else {
							colorOnly[r]++;
						}
					} else {
						if ((i&(1<<(c+5))) > 0) {
							numOnly[c]++;
						} else {
							notMarked++;
						}
					}
				}
			}
		}
		
		bool isValid = true;
		if (notMarked > 1) isValid = false;
		for (int i = 0; isValid && i < COLOR; ++i) {
			if (colorOnly[i] > 1) {
				isValid = false;
			}
		}
		for (int i = 0; isValid && i < NUM; ++i) {
			if (numOnly[i] > 1) {
				isValid = false;
			}
		}
		
		if (isValid) ans = min(cnt, ans);
	}
	
	cout << ans << endl;
	
	return 0;
}
