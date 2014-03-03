#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
	vector<int> couponsPos;
	vector<int> couponsNeg;
	vector<int> productPos;
	vector<int> productNeg;
	
	int nc,np;
	cin >> nc;
	for (int i = 0; i < nc; ++i) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp > 0) {
			couponsPos.push_back(tmp);
		} else {
			couponsNeg.push_back(tmp);
		}
	}
	sort(couponsPos.begin(), couponsPos.end(), greater<int>());
	sort(couponsNeg.begin(), couponsNeg.end());
	
	cin >> np;
	for (int i = 0; i < np; ++i) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp > 0) {
			productPos.push_back(tmp);
		} else {
			productNeg.push_back(tmp);
		}
	}
	sort(productPos.begin(), productPos.end(), greater<int>());
	sort(productNeg.begin(), productNeg.end());
	
	int sum = 0;
	int indx = 0;
	while (indx < couponsPos.size() && indx < productPos.size()) {
		sum += couponsPos[indx] * productPos[indx];
		++indx;
	}
	
	indx = 0;
	while (indx < couponsNeg.size() && indx < productNeg.size()) {
		sum += couponsNeg[indx] * productNeg[indx];
		++indx;
	}
	
	cout << sum << endl;
	
	return 0;
}
