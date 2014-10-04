#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
	if (matrix.empty()) {
		return false;
	}
	int len = matrix[0].size();
	int row, col;
	int small = 0, big = matrix.size()-1;
	while (small <= big) {
		row = (small + big) >> 1;
		if (matrix[row][0] <= target && target <= matrix[row][len-1]) {
			break;
		} else if (matrix[row][0] > target) {
			big = row - 1;
		} else if (matrix[row][len-1] < target) {
			small = row + 1;
		}
	}
	
	if (matrix[row][0] > target || matrix[row][len-1] < target) {
		return false;
	}
	
	small = 0, big = len - 1;
	while (small <= big) {
		col = (small + big) >> 1;
		if (matrix[row][col] == target) {
			return true;
		} else if (matrix[row][col] < target) {
			small = col + 1;
		} else {
			big = col - 1;
		}
	}
	
	return false;
}

int main() {
	return 0;
}
