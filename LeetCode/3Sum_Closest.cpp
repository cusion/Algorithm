#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/************* TLE Version ***********************
int threeSumClosest(vector <int> &num, int target) {
	int delta = 0x7fffffff;
	int ret = 0;
	for (int i = 0; i < num.size(); ++i) {
		int sum = 0;
		for (int j = i+1; j < num.size(); ++j) {
			for (int k = j+1; k < num.size(); ++k) {
				sum = num[i] + num[j] + num[k];
				//cout << "sum " << sum << endl;
				if (abs(sum-target) < delta) {
					ret = sum;
					delta = abs(sum-target);
				}
			}
		}
	}
	
	return ret;
}
*/

int twoSumClosest(int target, int skip, vector <int> num) {
	int small = 0;
	int big = num.size()-1;
	int delta = 0x7fffffff;
	int ret;
	while (small < big) {
		if (small == skip) {
			small ++;
		} else if (big == skip) {
			big--;
		}
		if (small < big) {
			int sum = num[small] + num[big];
			if (abs(sum-target) < delta) {
				ret = sum;
				delta = abs(sum-target);
			}
			if (sum > target) {
				big--;
			} else if (sum < target) {
				small++;
			} else {
				break;
			}
		}
	}
	
	return ret;
}

int threeSumClosest(vector <int> &num, int target) {
	sort(num.begin(), num.end());
	int ret = 0;
	int delta = 0x7fffffff;
	for (int i = 0; i < num.size(); ++i) {
		int sum = num[i] + twoSumClosest(target-num[i], i, num);
		if (abs(sum-target) < delta) {
			ret = sum;
			delta = abs(sum-target);
		}
	}
	
	return ret;
}

int main() {
	int arr[] = {-1, 2, 1, -4};
	vector <int> input(arr, arr+4);
	
	int target;
	cin >> target;
	
	cout << threeSumClosest(input, target) << endl;
	
	return 0;
}
