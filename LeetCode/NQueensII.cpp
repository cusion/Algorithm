#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/********************** Mine ******************
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

void helper(vector<string> &board, int &ret, int n, int r) {
	if (n == r) {
		++ret;
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

int totalNQueens(int n) {
	int ret = 0;
	if (n <= 0) {
		return ret;
	}
	vector<string> board(n, string(n, '.'));
	
	helper(board, ret, n, 0);
	
	return ret;
}*/

// Another great solution use only one vector to record the status
// of the board, with the first element represent the position of 
// one queen on the first row, the second represent the second row etc.
// Then check the board would be readily done with simple math computation.
// Though this method is seemly better than the above one, there still exists
// one excellent bit operation method that perform best as far.
/**************** Bit Operation *************************/

long upperlimit;
long sum;

void compute(long row,long ld,long rd) {
	if (row!=upperlimit) {
		long pos=upperlimit & ~(row | ld | rd);
		while (pos!=0) {
			long p=pos & -pos;
			pos=pos-p;
			compute(row + p, (ld + p)<< 1, (rd + p)>> 1);
		}
	} else {
		sum++;
	}
}

int totalNQueens(int n) {
	sum=0;
	upperlimit=1;
	upperlimit=(upperlimit<<n)-1;
	compute(0,0,0);
	return sum;
}

int main() {
	int ret = totalNQueens(1);
	cout << ret << endl;
	return 0;
}

