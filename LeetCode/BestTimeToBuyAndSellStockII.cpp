#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void getLimits(vector <int> &minPos, vector <int> &maxPos, vector <int> prices, int ind) {
	if (prices[0] < prices[1]) {
		minPos.push_back(prices[0]);
	}
	
	for (int i = 1; i < ind-1; ++i) {
		if (prices[i] > prices[i-1] && prices[i] > prices[i+1]) {
			maxPos.push_back(prices[i]);
		}
		if (prices[i] < prices[i-1] && prices[i] < prices[i+1]) {
			minPos.push_back(prices[i]);
		}
	}
	
	if (prices[ind-1] > prices[ind-2]) {
		maxPos.push_back(prices[ind-1]);
	}
}

int maxProfit(vector <int> &prices) {
	int ret = 0;
	
	int ind = 1;
	for (int i = 1; i < prices.size(); ++i) {
		if (prices[i] != prices[i-1]) {
			prices[ind++] = prices[i];
		}
	}
	
	if(ind < 2) return ret;
	
	vector <int> minVal;
	vector <int> maxVal;
	
	getLimits(minVal, maxVal, prices, ind);
	
	for (int i = 0; i < maxVal.size(); ++i) {
		ret += maxVal[i] - minVal[i];
	}
	
	return ret;
}

int main() {
	int arr[] = {3,3,5,0,0,3,1,4};
	vector <int> prices(arr, arr+8);
	cout << maxProfit(prices);
	return 0;
}
