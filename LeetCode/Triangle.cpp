#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int minimumTotal(vector <vector<int> > &triangle) {
	if (triangle.empty()) return 0;
	vector <int> pre(triangle.size(), 0);
	vector <int> cur(triangle.size(), 0);
	cur[0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); ++i) {
		pre.swap(cur);
		for (int j = 0; j < triangle[i].size(); ++j) {
			if (j == 0) {
				cur[j] = pre[0] + triangle[i][j];
			} else if (j == triangle[i].size()-1) {
				cur[j] = pre[j-1] + triangle[i][j];
			} else {
				cur[j] = min(pre[j-1], pre[j]) + triangle[i][j];
			}
		}
	}
	int ans = cur[0];
	for (int i = 1; i < cur.size(); ++i) {
		if (ans > cur[i]) {
			ans = cur[i];
		}
	}
	return ans;
}

int main() {
	return 0;
}
