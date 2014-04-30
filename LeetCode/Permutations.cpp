#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

vector<vector<int> > helper(vector<int> &num, int left, int right) {
	vector<vector<int> > ret;
	if (left > right) {
		return ret;
	}
	if (left == right) {
		ret.push_back(vector<int>(1, num[left]));
	}
	for (int i = left; i <= right; ++i) {
		swap(num[left], num[i]);
		vector<vector<int> > subret = helper(num, left+1, right);
		for (int j = 0; j < subret.size(); ++j) {
			subret[j].push_back(num[left]);
			ret.push_back(subret[j]);
		}
		swap(num[left], num[i]);
	}
	
	return ret;
}

vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> > ret;
	if (num.empty()) {
		return ret;
	}
	
	return helper(num, 0, num.size()-1);
}

int main() {
	vector<int> num = {1,2,3};
	vector<vector<int> > ret = permute(num);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}puts("");
	}
	return 0;
}
