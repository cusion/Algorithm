#include <cstdio>
#include <iostream>
using namespace std;

#define min(a, b) ((a)<(b)?(a):(b))

int main() {
	int n;
	cin >> n;
	
	int dist[n];
	int sumDist[n+1];
	int sum = 0;
	sumDist[0] = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &dist[i]);
		sum += dist[i];
		sumDist[i+1] = sum;
	}
	
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == b) {
			cout << 0 << endl;
			continue;
		}
		--a,--b;
		int small = a > b ? b : a;
		int big = a+b-small;
		
		int s2b = sumDist[big]-sumDist[small];
		cout << min(s2b, sum-s2b) << endl;
	}
	
	return 0;
}
