#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int> > &matrix, vector<int> &ret, int r, int c, int sr, int sc) {
	if (r==0 || c == 0) {
		return ;
	}
	if (r == 1) {
		for (int i = 0; i < c; ++i) {
			ret.push_back(matrix[sr][sc+i]);
		}
		return ;
	}
	if (c == 1) {
		for (int i = 0; i < r; ++i) {
			ret.push_back(matrix[sr+i][sc]);
		}
		return ;
	}
	for (int i = 0; i < c-1; ++i) {
		ret.push_back(matrix[sr][sc+i]);
	}
	for (int i = 0; i < r-1; ++i) {
		ret.push_back(matrix[sr+i][sc+c-1]);
	}
	for (int i = 0; i < c-1; ++i) {
		ret.push_back(matrix[sr+r-1][sc+c-1-i]);
	}
	for (int i = 0; i < r-1; ++i) {
		ret.push_back(matrix[sr+r-1-i][sc]);
	}
	
	helper(matrix, ret, r-2, c-2, sr+1, sc+1);
	
	return ;
}

vector<int> spiralOrder(vector<vector<int> > &matrix) {
	vector<int> ret;
	if (matrix.empty()) {
		return ret;
	}
	
	helper(matrix, ret, matrix.size(), matrix[0].size(), 0, 0);
	
	return ret;
}

int main() {
	vector <vector<int> > matrix;
	int r1[] = {1,2,3,4};
	int r2[] = {5,6,7,8};
	int r3[] = {9,10,11,12};
	int r4[] = {13,14,15,16};
	matrix.push_back(vector<int>(r1, r1+4));
	matrix.push_back(vector<int>(r2, r2+4));
	matrix.push_back(vector<int>(r3, r3+4));
	matrix.push_back(vector<int>(r4, r4+4));
	vector<int> ret = spiralOrder(matrix);
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << " ";
	}puts("");
	return 0;
}
