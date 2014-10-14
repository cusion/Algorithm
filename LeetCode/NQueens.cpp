#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<string> &board, int r, int c, int n) {
	// check row, col, left slash, right slash
	for (int i = 0; i < n; ++i) {
		if (board[r][i] != '.') {
			return false;
		}
		if (board[i][c] != '.') {
			return false;
		} 
		if (i+r<n) {
			if (i+c<n && board[i+r][i+c]!='.') {
				return false;
			}
			if (c-i>=0 && board[i+r][c-i]!='.') {
				return false;
			}
		}
		if (r-i>=0) {
			if (i+c<n && board[r-i][i+c]!='.') {
				return false;
			}
			if (c-i>=0 && board[r-i][c-i]!='.') {
				return false;
			}
		}
	}
	return true;
}

void helper(vector<string> &board, vector<vector<string> > &ret, int n, int r) {
	if (n == r) {
		ret.push_back(board);
		return ;
	}
	for (int i = 0; i < n; ++i) {
		if (isValid(board, r, i, n)) {
			board[r][i] = 'Q';
			helper(board, ret, n, r+1);
			board[r][i] = '.';
		}
	}
}

vector<vector<string> > solveNQueens(int n) {
	vector<vector<string> > ret;
	if (n <= 0) {
		return ret;
	}
	vector<string> board(n, string(n, '.'));
	
	helper(board, ret, n, 0);
	
	return ret;
}

void print(vector<string> board) {
	for (int i = 0; i < board.size(); ++i) {
		cout << board[i] << endl;
	}
}
int main() {
	vector<vector<string> > ret = solveNQueens(4);
	for (int i = 0; i < ret.size(); ++i) {
		print(ret[i]);
		puts("======================");
	}
	return 0;
}
