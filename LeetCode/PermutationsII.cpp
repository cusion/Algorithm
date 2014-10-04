#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

int findFirstAscend(vector<int> &num) {
	for (int i = num.size()-2; i >= 0; --i) {
		if (num[i] < num[i+1]) {
			return i;
		}
	}
	return -1;
}

int findLastLarger(vector<int> &num, int target) {
	for (int i = num.size()-1; i >= 0; --i) {
		if (num[i]>target) {
			return i;
		}
	}
}

void revert(vector<int> &num, int start, int end) {
	while (start < end) {
		swap(num[start], num[end]);
		++start;
		--end;
	}
}

vector<vector<int> > permuteUnique(vector<int> &num) {
	vector <vector<int> > ret;
	if (num.empty()){
		return ret;
	}
	if (num.size() == 1) {
		ret.push_back(num);
		return ret;
	}
	sort(num.begin(), num.end());
	ret.push_back(num);
	int flag;
	while((flag = findFirstAscend(num))>=0) {
		int lastLarger = findLastLarger(num, num[flag]);
		swap(num[flag], num[lastLarger]);
		revert(num, flag+1, num.size()-1);
		ret.push_back(num);
	}
	
	return ret;
}

int main() {
	return 0 ;
}
