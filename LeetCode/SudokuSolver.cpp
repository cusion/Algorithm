#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
/***************************************************
/* It is a shame that this solution is a mis-understanding
/* of what sudoku is, I have been assuming the limitation
/* of a sudoku is only that the row and the column should
/* contains 1~9 foreach respectively, however, there is 
/* another restriction that within the non-overlaped 3*3
/* small blocks of each row or column, a unique distribution
/* of 1~9 must still holds. As you will see in the mySudokuSolver()
/* function that I have omitted the last restriction that have
/* enlarge the searching space, so this is why this solution fails.
/* However, the thoughts in this solution should be memorized,
/* that is whenever a DFS method is applied, we should first find out
/* the current state and the current choice, and try those choices one
/* by one and go to the next search state.

struct Position {
	int r;
	int c;
	Position(int rr, int cc) : r(rr), c(cc) {}
};

vector <Position> blank;
bool isUsed[10];
vector <vector <char> > ravail;
vector <vector <char> > cavail;
bool isComplete = false;

void printSudoku(vector <vector <char> > board) {
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			cout << board[i][j] << " ";
		}
		puts("");
	}
}

void printAvail(int r, int c) {
	puts("###########################");
	cout << r << " row has " ;
	for (int i = 0; i < ravail[r].size(); ++i) {
		cout << ravail[r][i] << " ";
	}puts("");
	
	cout << c << " col has " ;
	for (int i = 0; i < cavail[c].size(); ++i) {
		cout << cavail[c][i] << " ";
	}puts("");
	puts("#############################");
}

vector <char> getUnion(int r, int c) {
	int simbol[10];
	vector <char> ret;
	for (int i = 0; i < 10; ++i) {
		simbol[i] = 0;
	}
	for (int i = 0; i < ravail[r].size(); ++i) {
		simbol[ravail[r][i] - '0'] ++;
	}
	for (int i = 0; i < cavail[c].size(); ++i) {
		simbol[cavail[c][i]-'0'] ++;
	}
	for (int i = 1; i < 10; ++i) {
		if (simbol[i] == 2) {
			ret.push_back((char)(i+'0'));
		}
	}
	
	return ret;
}

void eraseAvail(int r, int c, char ch) {
	vector <char>::iterator ritr = find(ravail[r].begin(), ravail[r].end(), ch);
	ravail[r].erase(ritr);
	vector <char>::iterator citr = find(cavail[c].begin(), cavail[c].end(), ch);
	cavail[c].erase(citr);
}

void addAvail(int r, int c, char ch) {
	ravail[r].push_back(ch);
	cavail[c].push_back(ch);
}

void mySudokuSolver(vector <vector <char> >&board, int blankPos) {
	if (blankPos == blank.size()) {
		isComplete = true;
		return;
	}
	
	Position curPos = blank[blankPos];
	//printAvail(curPos.r, curPos.c);
	vector <char> availChar = getUnion(curPos.r, curPos.c);
	if (availChar.empty()) return;
	
	for (int i = 0; i < availChar.size(); ++i) {
		if (!isComplete) {
			board[curPos.r][curPos.c] = availChar[i];
			eraseAvail(curPos.r, curPos.c, availChar[i]);
			mySudokuSolver(board, blankPos+1);
			if (!isComplete) {
				addAvail(curPos.r, curPos.c, availChar[i]);
			}
		}
	}
}

void solveSudoku(vector<vector<char> > &board) {
	blank.clear();
	ravail.clear();
	cavail.clear();
	isComplete = false;
	// find places to fill
	for (int i = 0; i < board.size(); ++i) {		
		for (int j = 0; j < board[i].size(); ++j) {
			if (board[i][j] == '.') {
				Position pb(i, j);
				blank.push_back(pb);
			}
		}
	}
	
	// find available numbers for each row
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 1; j < 10; ++j) {
			isUsed[j] = false;
		}
		
		for (int j = 0; j < board[i].size(); ++j) {
			//cout << board[i][j] << endl;
			if (board[i][j] != '.') {
				//puts("booya");
				isUsed[board[i][j]-'0'] = true;
			}
		}
		vector <char> rtmp;
		for (int j = 1; j < 10; ++j) {
			if (!isUsed[j]) {
				rtmp.push_back((char)(j+'0'));
			}
		}
		ravail.push_back(rtmp);
	}
	
	// find available numbers for each column
	for (int j = 0; j < board[0].size(); ++j) {
		
		for (int i = 1; i < 10; ++i) {
			isUsed[i] = false;
		}
		
		for (int i = 0; i < board.size(); ++i) {
			if (board[i][j] != '.') {
				isUsed[board[i][j]-'0'] = true;
			}
		}
		vector <char> ctmp;
		for (int i = 1; i < 10; ++i) {
			if (!isUsed[i]) {
				ctmp.push_back((char)(i+'0'));
			}
		}
		cavail.push_back(ctmp);
	}
	
	mySudokuSolver(board, 0);
}*/

/******************* TEST PROGRAME ************************/

void printSudoku(vector <vector <char> > board) {
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			cout << board[i][j] << " ";
		}
		puts("");
	}
}

bool getNextEmpty(vector<vector<char> > &board, int &row, int &col) {
    while (row <= 8 && col <= 8) {
        if (board[row][col] == '.') return true;
        row = (col == 8) ? row + 1 : row;
        col = (col == 8) ? 0 : col + 1;
    }
    return false;
}

void getPossibleValues(vector<vector<char> > &board, vector<char> &possible, int row, int col) {
    bool s[9] = { false };
    for (int i = 0; i < 9; i++) {
        if (board[row][i] != '.') s[board[row][i]-'1'] = true;
        if (board[i][col] != '.') s[board[i][col]-'1'] = true;
        char c = board[row/3*3+i/3][col/3*3+i%3];
        if (c!='.') s[c-'1'] = true;
    }
    for (int i = 0; i < 9; i++) {
        if (!s[i]) possible.push_back('1'+i);
    }
}

bool solve(vector<vector<char> > &board, int row, int col) {
    bool res = getNextEmpty(board, row, col);
    if (!res) return true;
    vector<char> possible;
    getPossibleValues(board, possible, row, col);
    if (possible.size() == 0) return false;
    for (size_t i = 0; i < possible.size(); i++) {
        board[row][col] = possible[i];
        if (solve(board, row, col)) return true;
        board[row][col] = '.';
    }
    return false;
}
void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0, 0);
}
int main() {
	
	char arr[9][10] = {".265...9.","5...79..4","3...1....","6.....8.7",".75.2..1.",".1....4..","...3.89.2","7...6..4.",".3.2..1.."};
	vector <vector <char> > board;
	for (int i = 0; i < 9; ++i) {
		vector <char> tmp(arr[i], arr[i]+9);
		board.push_back(tmp);
	}
	printSudoku(board);
	
	solveSudoku(board);
	
	printSudoku(board);
	
	return 0;
}
