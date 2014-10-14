#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void helper(vector<int>cand, int target, vector<vector<int> > &ret, vector<int> &sol, int minIndx) {
	if (target < 0) {
		return;
	}
	if (target == 0) {
		ret.push_back(sol);
	}
	
	for (int i = minIndx; i < cand.size(); ++i) {
		sol.push_back(cand[i]);
		target -= cand[i];
		helper(cand, target, ret, sol, i);
		sol.pop_back();
		target += cand[i];
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	vector<vector<int> > ret;
	if(candidates.empty()) {
		return ret;
	}
	vector<int> solution;
	sort(candidates.begin(), candidates.end());
	helper(candidates, target, ret, solution, 0);
	
	return ret;
}

int main() {
	int arr[] = {2,3,6,7};
	vector <int> cand(arr, arr+4);
	int target = 7;
	vector<vector<int> > ret = combinationSum(cand, target);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}puts("");
	}
	return 0;
}
