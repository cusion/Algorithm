#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > ret;
	if (n < k || k <= 0) {
		return ret;
	}
	if (k == 1) {
		for (int i = 1; i <= n; ++i) {
			ret.push_back(vector<int>(1, i));
		}
		return ret;
	}
	if (n == k) {
		vector<int> tmp;
		for (int i = 1; i <= n; ++i) {
			tmp.push_back(i);
		}
		ret.push_back(tmp);
		return ret;
	}
	vector<vector<int> > withN = combine(n-1, k-1);
	for (int i = 0; i < withN.size(); ++i) {
		withN[i].push_back(n);
		ret.push_back(withN[i]);
	}
	vector<vector<int> > withoutN = combine(n-1, k);
	for (int i = 0; i < withoutN.size(); ++i) {
		ret.push_back(withoutN[i]);
	}
	
	return ret;
}

int main() {
	vector<vector<int> > ret = combine(5, 3);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}puts("");
	}
	return 0;
}
