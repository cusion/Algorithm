#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*********** TLE Version O(N^3) ************
int maximalRectangle(vector<vector<char> > &matrix) {
	if (matrix.empty() || matrix[0].empty()) {
		return 0;
	}
	vector<vector<int> > rowSum(matrix.size(), vector<int>(matrix[0].size(), 0));
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			rowSum[i][j] = matrix[i][j]-'0';
			if (i > 0) {
				rowSum[i][j] += rowSum[i-1][j];
			}
		}
	}
	
	int ret = 0;
	for (int i = 0; i < rowSum.size(); ++i) {
		for (int j = i; j < rowSum.size(); ++j) {
			int tmpLen = 0, tmpRet = 0;
			for (int k = 0; k < rowSum[0].size(); ++k) {
				if (i == 0) {
					if (rowSum[j][k] == j+1) {
						++tmpLen;
					} else {
						tmpRet = tmpLen > tmpRet ? tmpLen : tmpRet;
						tmpLen = 0;
					}
				} else {
					if (rowSum[j][k]-rowSum[i-1][k] == j-i+1) {
						++tmpLen;
					} else {
						tmpRet = tmpLen > tmpRet ? tmpLen : tmpRet;
						tmpLen = 0;
					}
				}
			}
			tmpRet = tmpLen > tmpRet ? tmpLen : tmpRet;
			ret = tmpRet*(j-i+1) > ret ? tmpRet*(j-i+1) : ret;
		}
	}
	
	return ret;
}*/

int maxRectangleInHistogram(vector<int> &height) {
	int area = 0;
	stack <int> leftIdx;
	height.push_back(0);
	for (int i = 0; i < height.size(); ++i) {
		if (leftIdx.empty() || height[i] >= height[leftIdx.top()]) {
			leftIdx.push(i);
		} else {
			int tmp = 0;
			while (!leftIdx.empty() && height[i] < height[leftIdx.top()]) {
				int h = height[leftIdx.top()];
				//cout << h << endl;
				leftIdx.pop();
				tmp = h * (leftIdx.empty() ? i : (i-leftIdx.top()-1));
				//cout << tmp << " " << i << " " << leftIdx.top() << endl;
				area = area > tmp ? area : tmp;
			}
			leftIdx.push(i);
		}
	}
	
	return area;
}

int maximalRectangle(vector<vector<char> > &matrix) {
	if (matrix.empty() || matrix[0].empty()) {
		return 0;
	}
	vector<vector<int> > height(matrix.size(), vector<int>(matrix[0].size(), 0));
	for (int i = 0; i < matrix[0].size(); ++i) {
		height[0][i] = matrix[0][i] - '0';
	}
	for (int i = 1; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (matrix[i][j] == '0') {
				height[i][j] = 0;
			} else {
				height[i][j] = height[i-1][j] + 1;
			}
		}
	}
	
	/*for (int i = 0; i < height.size(); ++i) {
		for (int j = 0;j < height[0].size(); ++j) {
			cout << height[i][j] << " ";
		}puts("");
	}*/
	
	int ret = 0;
	for (int i = 0; i < matrix.size(); ++i) {
		int tmp = maxRectangleInHistogram(height[i]);
		ret = ret > tmp ? ret : tmp;
	}
	
	return ret;
}

int main() {
	vector <char> tmp = {'0','1'};
	vector<vector<char> > matrix(2, tmp);
	cout << maximalRectangle(matrix) << endl;
	return 0;
}
