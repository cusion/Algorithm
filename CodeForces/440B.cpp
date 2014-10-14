#include <cstdio>
#include <iostream>
using namespace std;

#define abs(x) ((x)>0 ? (x) : -(x))
#define MAX 50004
long long boxes[MAX];
int main() {
	int n;
	cin >> n;
	long long total = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%I64d ", &boxes[i]);
		total += boxes[i];
	}
	long long avg = total/n;
	long long ans = 0;
	long long income = 0;
	for (int i = 0; i < n; ++i) {
		boxes[i] += income;
		income = boxes[i]-avg;
		ans += abs(income);
	}
	
	cout << ans << endl;
	return 0;
}
