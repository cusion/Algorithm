#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool isValidSudoku(vector <vector <char> > &board) {
	int rused[10];
	int cused[10];
	int gused[10];
	for (int i = 1; i < 10; ++i) {
		rused[i] = 0;
		cused[i] = 0;
		gused[i] = 0;
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (board[i][j] != '.') {
				rused[board[i][j]-'0']++;
			}
			if (board[j][i] != '.') {
				cused[board[j][i]-'0']++;
			}
			int r = i/3*3 + j/3;
			int c = (i%3)*3 + j%3;
			if (board[r][c] != '.') {
				gused[board[r][c]-'0']++;
			}
		}
		for (int j = 1; j < 10; ++j) {
			if (cused[j] >= 2 || rused[j] >= 2 || gused[j] >= 2) {
				return false;
			} else {
				cused[j] = rused[j] = gused[j] = 0;
			}
		}
	}
	
	return true;
}

int main() {
	return 0;
}
