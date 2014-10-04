#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void myThreeSum(vector <vector<int> > &ret, vector <int> num, int target) {
	sort(num.begin(), num.end());
	
	for (int i = 0; i < num.size()-2; ++i) {
		if (i > 0 && num[i] == num[i-1]) continue;
		int small = i+1;
		int big = num.size()-1;
		while(small < big) {
			if (num[small] + num[big] == target-num[i]) {
				vector <int> tmp;
				tmp.push_back(num[i]);
				tmp.push_back(num[small]);
				tmp.push_back(num[big]);
				ret.push_back(tmp);
				while (small < big && num[small] == num[small+1]){
					++small;
				}
				++small;
				while (small < big && num[big] == num[big-1]) {
					--big;
				}
				--big;
			}else if (num[small] + num[big] < target-num[i]) {
				++small;
			} else {
				--big;
			}
		} 
	}
}

vector <vector <int> > threeSum(vector <int>&num) {
	vector <vector<int> > ret;
	if (num.size() < 3) return ret;
	
	myThreeSum(ret, num, 0);
	
	return ret;
}

int main() {
	int arr[] = {-1, 0, 1, 2, -1, -4};
	vector <int> s(arr, arr+6);
	vector <vector<int> > ret = threeSum(s);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}puts("");
	}
	return 0;
}
