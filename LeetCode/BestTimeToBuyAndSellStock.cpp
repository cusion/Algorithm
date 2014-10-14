#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxProfit(vector <int> &prices) {
	int ret = 0;
	if (prices.size() < 2) return ret;
	int min = prices[0];
	
	for (int i = 1; i < prices.size(); ++i) {
		if (prices[i] > min) {
			ret = max(ret, prices[i]-min);
		} else {
			min = prices[i];
		}
	}
	
	return ret;
}

int main() {
	int arr[] = {6,1,3,2,4,7};
	vector <int> prices(arr, arr+6);
	cout << maxProfit(prices);
	return 0;
}
