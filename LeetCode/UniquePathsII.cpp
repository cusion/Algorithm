#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> >&obstacleGrid) {
	if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
		return 0;
	}
	vector<vector<int> > paths(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
	for (int i = 0; i < paths.size(); ++i) {
		if (obstacleGrid[i][0] != 1) {
			paths[i][0] = 1;
		} else {
			break;
		}
	}
	for (int i = 0; i < paths[0].size(); ++i) {
		if (obstacleGrid[0][i] != 1) {
			paths[0][i] = 1;
		} else {
			break;
		}
	}
	
	for (int i = 1; i < paths.size(); ++i) {
		for (int j = 1; j < paths[0].size(); ++j) {
			if (obstacleGrid[i][j] != 1) {
				if (obstacleGrid[i-1][j] != 1) {
					paths[i][j] += paths[i-1][j];
				}
				if (obstacleGrid[i][j-1] != 1) {
					paths[i][j] += paths[i][j-1];
				}
			}
		}
	}
	
	return paths[paths.size()-1][paths[0].size()-1];
}

int main() {
	return 0;
}
