#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N, arr[10005];
	cin>>N;
	double mean = 0;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		mean += arr[i];
	}
	mean = mean/N;
	double stde = 0;
	for (int i = 0; i < N; ++i) {
		stde += (arr[i] - mean)*(arr[i] - mean);
	}
	stde = sqrt(stde/N);
	printf("%.5lf\n", stde);

	return 0;
}
