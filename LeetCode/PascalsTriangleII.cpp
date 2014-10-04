#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector <int> getRow(int rowIndx) {
	vector <int> pre;
	vector <int> cur;
	if (rowIndx < 0) {
		return cur;
	}
	cur.push_back(1);
	if (rowIndx == 0) {
		return cur;
	}
	for (int i = 0; i < rowIndx; ++i) {
		cur.swap(pre);
		cur.clear();
		cur.push_back(1);
		for (int j = 1; j < pre.size(); ++j) {
			cur.push_back(pre[j]+pre[j-1]);
		}
		cur.push_back(1);
	}
	return cur;
}

int main() {
	while (1) {
		int n;
		cin >> n;
		vector <int> ret = getRow(n);
		for (int i = 0; i < ret.size(); ++i) {
			cout << ret[i] << " ";
		}puts("");
		puts("---------------");
	}
	return 0;
}
