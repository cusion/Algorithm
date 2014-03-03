#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > ret;
	if (numRows == 0) {
		return ret;
	}
	ret.push_back(vector<int>(1,1));
	if (numRows == 1) {
		return ret;
	}
	ret.push_back(vector<int>(2, 1));
	if (numRows == 2) {
		return ret;
	}
	for (int i = 2; i < numRows; ++i) {
		ret.push_back(vector<int>(i+1));
		ret[i][0] = ret[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
		}
	}
	
	return ret;
}

int main() {
	int n;
	while (1) {
		cin >> n;
		vector<vector<int> > ret = generate(n);
		for (int i = 0; i < ret.size(); ++i) {
			for (int j = 0; j < ret[i].size(); ++j) {
				cout << ret[i][j] << " ";
			}puts("");
		}
		puts("------------------");
	}
	return 0;
}
