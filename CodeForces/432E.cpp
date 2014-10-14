#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/************ Wrong Greedy Method **********
case : 9, 6
it would be :
AAAAAA
AAAAAA
AAAAAA
AAAAAA
AAAAAA
AAAAAA
BBBCCC
BBBCCC
BBBCCC

While it actually should be:
AAAAAA
AAAAAA
AAAAAA
AAAAAA
AAAAAA
AAAAAA
BBBCBB
BBBABB
BBBCAC

char getMin(vector<vector<char> > &board, int row, int col) {
	char top = row > 0 ? board[row-1][col] : '\0';
	char left = col > 0 ? board[row][col-1] : '\0';
	for (char ch = 'A'; ch <= 'Z'; ++ch) {
		if (ch != top && ch != left) {
			return ch;
		}
	}
}

void solve(vector<vector<char> > &board, int row, int n, int col, int m) {
	if (m == 0 || n == 0) {
		return ;
	}
	if (n == 1) {
		for (int i = col; i < col+m; ++i) {
			board[row][i] = getMin(board, row, i);
		}
		return ;
	}
	if (m == 1) {
		for (int i = row; i < row+n; ++i) {
			board[i][col] = getMin(board, i, col);
		}
	}
	char ch = getMin(board, row, col);
	int squareLen = n < m ? n : m;
	for (int i = row; i < row+squareLen; ++i) {
		for (int j = col; j < col+squareLen; ++j) {
			board[i][j] = ch;
		}
	}
	int left, top;
	if (m == n) {
		return ;
	} else if (m < n) {
		left = col;
		top = row + m;
		n -= m;
	} else {
		left = col + n;
		top = row;
		m -= n;
	}
	solve(board, top, n, left, m);
}*/

char getMin(vector<vector<char> > &board, int x, int y) {
	char ch = board[x][y];
	if (ch == '\0') {
		for (ch= 'A'; ch <= 'Z'; ++ch) {
			if (board[x-1][y] != ch && board[x][y-1] != ch && 
				board[x+1][y] != ch && board[x][y+1] != ch) {
				break;
			}
		}
	}
	return ch;
}

void solve(vector<vector<char> > &board, int n, int m) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char ch = getMin(board, i, j);
			if (board[i][j] != '\0') {
				continue;
			}
			int span = 1;
			while (i+span <= n && j+span <= m && getMin(board, i, j+span) == ch) {
				++span;
			}
			for (int x = 0; x < span; ++x) {
				for (int y = 0; y < span; ++y) {
					board[i+x][j+y] = ch;
				}
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char> > board(n+2, vector<char>(m+2, '\0'));
	solve(board, n, m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%c", board[i][j]);
		}puts("");
	}
	return 0;
}
