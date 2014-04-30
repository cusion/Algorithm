#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void helper(map<int,int> &numCntMap, int target, map<int,int>::iterator start,
			vector<int> &tmp, vector<vector<int> > &ret)
{
	if (target == 0 && !tmp.empty()) {
		ret.push_back(tmp);
		return ;
	}
	
	if (start->first > target) {
		return ;
	}
	
	map<int,int>::iterator itr;
	map<int,int>::iterator next;
	for (itr = start; itr != numCntMap.end(); ++itr) {
		int cnt = 0;
		while (target > 0 && cnt < itr->second) {
			++cnt;
			target -= itr->first;
		}
		for (int i = 0; i < cnt; ++i) {
			tmp.push_back(itr->first);
		}
		next = itr;
		++next;
		for (int i = 0; i < cnt; ++i) {
			helper(numCntMap, target, next, tmp, ret);
			target += itr->first;
			tmp.pop_back();
		}
	}
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	vector<vector<int> > ret;
	if (num.empty()) {
		return ret;
	}
	map<int, int> numCntMap;
	for (int i = 0; i < num.size(); ++i) {
		numCntMap[num[i]]++;
	}
	vector<int> tmp;
	helper(numCntMap, target, numCntMap.begin(), tmp, ret);
	
	return ret;
}

int main() {
	//vector<int> num = {10, 1, 2, 7, 6, 1, 5};
	vector<int> num = {1,1,1,1,6,6,6,6};
	vector<vector<int> > ret = combinationSum2(num, 24);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}puts("");
	}
	return 0;
}
