#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int candy(vector <int> &ratings) {
	int assign[ratings.size()];
	for (int i = 0; i < ratings.size(); ++i) {
		assign[i] = 1;
	}
	
	for (int i = 1; i < ratings.size(); ++i) {
		if (ratings[i] > ratings[i-1]) {
			assign[i] = assign[i-1]+1;
		}
	}
	for (int i = ratings.size()-2; i >= 0; --i) {
		if (ratings[i] > ratings[i+1]) {
			assign[i] = max(assign[i], assign[i+1]+1);
		}
	}
	
	int sum = 0;
	for (int i = 0; i < ratings.size(); ++i) {
		sum += assign[i];
	}
	
	return sum;
}

int main() {
	int arr[] = {4,3,2,1,2,3,4,5,6,2,1};
	vector <int> ratings(arr, arr+11);
	cout << candy(ratings)<<endl;
	return 0;
}
