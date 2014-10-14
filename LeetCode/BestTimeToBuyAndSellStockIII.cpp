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
	
	/*for (int i = 0; i < ind; ++i) {
		cout << prices[i] << " ";
	}puts("");*/
	
	if(ind < 2) return ret;
	
	vector <int> minVal;
	vector <int> maxVal;
	
	getLimits(minVal, maxVal, prices, ind);
	
	/*for (int i = 0; i < minVal.size(); ++i) {
		cout << minVal[i] << " ";
	}puts("");
	for (int i = 0; i < maxVal.size(); ++i) {
		cout << maxVal[i] << " ";
	}puts("");*/
	
	for (int i = 0; i < maxVal.size(); ++i) {
		int first = 0;
		for (int j = 0; j <= i; ++j) {
			first = max(first, maxVal[i]-minVal[j]);
		}
		int second = 0, minprice = 10000000;
		for (int j = i+1; j < minVal.size(); ++j) {
			minprice = min(minprice, minVal[j]);
			second = max(second, maxVal[j] - minprice);
		}
		//cout << "tried " << first+second << endl;
		ret = max(ret, first + second);
	}
	
	return ret;
}

int main() {
	int arr[] = {3,3,5,0,0,3,1,4};
	vector <int> prices(arr, arr+8);
	cout << maxProfit(prices);
	return 0;
}
