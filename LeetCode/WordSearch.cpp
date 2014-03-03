#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/********************************************************************
I have no word about this problem, the previouse edition of my DFS code
just postpones the visit marking process, which has little affect with
the recursive procedure, refer to the mysubmissions of the leetcode website;
*/

bool compose(vector<vector<char> > &board, int r, int c, string word, int ind, vector<vector<bool> > &visit) {
	if (ind == word.size()) {
		return true;
	}
	if (r>0 && !visit[r-1][c] && board[r-1][c] == word[ind]) {
		visit[r-1][c] = true;
		if (compose(board, r-1, c, word, ind+1, visit)) {
			return true;
		}
		visit[r-1][c] = false;
	}
	if (c>0 && !visit[r][c-1] && board[r][c-1] == word[ind]) {
		visit[r][c-1] = true;
		if (compose(board, r, c-1, word, ind+1, visit)) {
			return true;
		}
		visit[r][c-1] = false;
	}
	if (r < board.size()-1 && !visit[r+1][c] && board[r+1][c] == word[ind]) {
		visit[r+1][c] = true;
		if (compose(board, r+1, c, word, ind+1, visit)) {
			return true;
		}
		visit[r+1][c] = false;
	}
	if (c < board[0].size()-1 && !visit[r][c+1] && board[r][c+1] == word[ind]) {
		visit[r][c+1] = true;
		if (compose(board, r, c+1, word, ind+1, visit)) {
			return true;
		}
		visit[r][c+1] = false;
	}
	return false;
}

bool exist(vector<vector<char> > &board, string word) {
	if (board.empty() || word.empty() || board.size()*board[0].size() < word.length()) return false;
	vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			if (board[i][j] == word[0]) {
				visit[i][j] = true;
				if (compose(board, i, j, word, 1, visit)) return true;
				visit[i][j] = false;
			}
		}
	}
	return false;
}

int main() {
	return 0;
}
