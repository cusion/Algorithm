#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
There is another seemly faster method for this problem, which could be O(n*n*lg(n)) complexity, details as below:
1. sort the original array and pick out non-duplicated pairs, attentions must be paid to select those pairs,
   first we could merge those identical numbers, and find out different pairs, and then we should also select 
   pairs from identical numbers, the number of pairs is equal to number of identical numbers divided by 2, but
   there is a problem with this method when there is only 2 numbers are the same, for example, when the instance
   {1, 2, 2, 3} and we want 9 summation, we would get {(2,2), (2, 3)} from method above, which is obvoisly a wrong
   answer, so that we should avoid this case when dealing with groups.
2. after we get all possible non-identical pairs, and sort them w.r.t their sum, then we could use the O(n)
   trick we have already known from 2sum problem.
3. above all, we could conclude the complexity is O(n*n*lg(n)), but there are some tips I need to mention, first,
   keep in mind to use the effectively-implemented STL data structure or algorithm, such as sort, lower_bound,
   (multi-)map, (multi-)set, unorderd_map; second, it is convinient to keep the order of elements in those non-
   identical pairs, for instance, we could keep the first element always be the small one. This kind of method
   may help when we want to compare identical pairs.
*/

vector < vector <int> > fourSum(vector <int> &num, int target) {
	vector <vector<int> > ret;
	if (num.size()<4) return ret;
	
	sort(num.begin(), num.end());
	
	for (int i = 0; i < num.size()-3; ++i) {
		if (i>0 && num[i] == num[i-1]) continue;
		for (int j = i+1; j < num.size()-2; ++j) {
			if (j > i+1 && num[j] == num[j-1])continue;
			int small = j+1;
			int big = num.size()-1;
			while (small < big) {
				int sum = num[small] + num[big];
				if (sum > target - num[i] - num[j]) {
					--big;
				} else if (sum < target - num[i] - num[j]) {
					++small;
				} else {
					vector <int> tmp;
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(num[small]);
					tmp.push_back(num[big]);
					ret.push_back(tmp);
					++small;
					--big;
					while (small < big && num[small] == num[small-1])++small;
					while (small < big && num[big] == num[big+1])--big;
				}
			}
		}
	}
	
	return ret;
}

int main () {
	int arr[] = {-3,-2,-1,0,0,1,2,3};
	vector <int> input(arr, arr+8);
	int target;
	cin >> target;
	vector <vector<int> > ret = fourSum(input, target);
	
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}puts("");
	}
	
	return 0;
}
