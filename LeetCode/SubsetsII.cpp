#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector <vector<int> > subsetsWithDup(vector<int> &S) {
	vector<vector<int> > ret(1, vector<int>());
	if (S.empty()) {
		return ret;
	}
	map<int, int> umap;
	for (int i = 0; i < S.size(); ++i) {
		umap[S[i]]++;
	}
	for (auto it = umap.begin(); it != umap.end(); ++it) {
		int preSize = ret.size();
		for (int i = 1; i <= it->second; ++i) {
			for (int j = 0; j < preSize; ++j) {
				vector <int> tmp = ret[j];
				for (int k = 0; k < i; ++k) {
					tmp.push_back(it->first);
				}
				ret.push_back(tmp);
			}
		}
	}
	
	return ret;
}

int main() {
	vector<int> S;
	S.push_back(1);
	S.push_back(1);
	S.push_back(2);
	S.push_back(2);
	S.push_back(2);
	vector<vector<int> > ret = subsetsWithDup(S);
	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}puts("");
	}
	return 0;
}
