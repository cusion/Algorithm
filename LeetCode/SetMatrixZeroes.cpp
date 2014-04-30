#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// common method
/*void setZeroes(vector<vector<int> > &matrix, int row, int col) {
	
	if (row >= 0) {
		for (int i = 0; i < matrix[row].size(); ++i) {
			matrix[row][i] = 0;
		}
	}
	
	if (col >= 0) {
		for (int i = 0; i < matrix.size(); ++i) {
			matrix[i][col] = 0;
		}
	}
}*/
void setZeroes(vector<vector<int> > &matrix, int row, int col, int marker) {
	matrix[row][col] = 0;
	for (int i = 0; i < matrix[row].size(); ++i) {
		if (matrix[row][i] != marker) {
			matrix[row][i] = 0;
		}
	}
	for (int i = 0; i < matrix.size(); ++i) {
		if (matrix[i][col] != marker) {
			matrix[i][col] = 0;
		}
	}
}

/************ O(MN) space solution **********
void setZeroes(vector<vector<int> >&matrix) {
	if (matrix.empty() || matrix[0].empty()) {
		return;
	}
	vector<vector<int> > mask = vector<vector<int> >(matrix.size(), vector<int>(matrix[0].size(), 1));
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (matrix[i][j] == 0) {
				setZeroes(mask, i, j);
			}
		}
	}
	
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			matrix[i][j] = matrix[i][j]*mask[i][j];
		}
	}
}*/

/*********** O(M+N) space solution **********
void setZeroes(vector<vector<int> >&matrix) {
	if (matrix.empty() || matrix[0].empty()) {
		return;
	}
	vector<bool> rows = vector<bool>(matrix.size(), false);
	vector<bool> cols = vector<bool>(matrix[0].size(), false);
	
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (matrix[i][j] == 0) {
				rows[i] = true;
				cols[j] = true;
			}
		}
	}
	
	for (int i = 0; i < rows.size(); ++i) {
		if (rows[i]) {
			setZeroes(matrix, i, -1);
		}
	}
	for (int j = 0; j < cols.size(); ++j) {
		if (cols[j]) {
			setZeroes(matrix, -1, j);
		}
	}
}*/

/************** O(1) space solution *************/
// there is an open question: how could we generate an unique number out
// of an array;
void setZeroes(vector<vector<int> > &matrix) {
	if (matrix.empty() || matrix[0].empty()) {
		return ;
	}
	// make sure this marker is unique from elements in the matrix;
	int marker = 12349215;
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (matrix[i][j] == 0) {
				matrix[i][j] = marker;
			}
		}
	}
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (matrix[i][j] == marker) {
				setZeroes(matrix, i, j, marker);
			}
		}
	}
}

int main() {
	return 0;
}
