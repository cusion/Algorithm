#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 105;

inline double max(double a, double b) {
	return a > b ? a : b;
}

/*
3
0.388818 0.399762 0.393874
*/

int main() {
	double pos[MAX], neg[MAX], dp[MAX];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> pos[i];
		neg[i] = 1 - pos[i];
	}
	
	dp[0] = pos[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = max(max(pos[i], dp[i-1]), pos[i]*neg[i-1]+dp[i-1]*neg[i]);
		neg[i] *= neg[i-1];
		//cout << dp[i] << endl;
	}
	
	cout << setprecision(12) << showpoint << dp[n-1] << endl;
	
	return 0;
}
