#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

char board[304][304];
struct Point{
	int r, c;
	Point():r(0), c(0) {
	}
	Point(int rr, int cc):r(rr), c(cc) {
	}
};

int countMiner(int r, int c, char board[304][304], int n) {
	int cnt = 0;
	//upper left
	if (r > 0 && c > 0 && board[r-1][c-1] == '*') {
		cnt++;
	}
	// above
	if (r > 0 && board[r-1][c] == '*') {
		cnt++;
	}
	// upper right
	if (r > 0 && c < n-1 && board[r-1][c+1] == '*') {
		cnt++;
	}
	// right
	if (c < n-1 && board[r][c+1] == '*') {
		cnt++;
	}
	//bottom right
	if (r < n-1 && c < n-1 && board[r+1][c+1] == '*') {
		cnt++;
	}
	// bottom
	if (r < n-1 && board[r+1][c] == '*') {
		cnt++;
	}
	// bottom left
	if (r < n-1 && c > 0 && board[r+1][c-1] == '*') {
		cnt++;
	}
	// left
	if (c > 0 && board[r][c-1] == '*') {
		cnt++;
	}
	return cnt;
}

void revealBoard(int rr, int cc, char board[304][304], int n) {
	queue<Point> q;
	q.push(Point(rr, cc));
	while (!q.empty()) {
		Point tmp = q.front();
		q.pop();
		if (board[tmp.r][tmp.c] == '.') {
			board[tmp.r][tmp.c] = countMiner(tmp.r, tmp.c, board, n) + '0';
			if (board[tmp.r][tmp.c] == '0') {
				int r = tmp.r;
				int c = tmp.c;
				//upper left
				if (r > 0 && c > 0 && board[r-1][c-1] == '.') {
					q.push(Point(r-1, c-1));
				}
				// above
				if (r > 0 && board[r-1][c] == '.') {
					q.push(Point(r-1, c));
				}
				// upper right
				if (r > 0 && c < n-1 && board[r-1][c+1] == '.') {
					q.push(Point(r-1, c+1));
				}
				// right
				if (c < n-1 && board[r][c+1] == '.') {
					q.push(Point(r, c+1));
				}
				//bottom right
				if (r < n-1 && c < n-1 && board[r+1][c+1] == '.') {
					q.push(Point(r+1, c+1));
				}
				// bottom
				if (r < n-1 && board[r+1][c] == '.') {
					q.push(Point(r+1, c));
				}
				// bottom left
				if (r < n-1 && c > 0 && board[r+1][c-1] == '.') {
					q.push(Point(r+1, c-1));
				}
				// left
				if (c > 0 && board[r][c-1] == '.') {
					q.push(Point(r, c-1));
				}
			}
		}
	}
}

int main() {
	int T, N;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		scanf("%d", &N);
		for (int j = 0; j < N; ++j) {
			scanf("%s", board[j]);
		}
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (board[j][k] == '.' && countMiner(j, k, board, N) == 0) {
					revealBoard(j, k, board, N);
					cnt += 1;
				}
			}
		}
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (board[j][k] == '.') {
					cnt += 1;
				}
			}
		}
		cout << "Case #" << i << ": " << cnt << endl;
	}
	return 0;
}
