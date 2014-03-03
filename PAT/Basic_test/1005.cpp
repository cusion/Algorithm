#include <iostream>
#include <cstdio>
using namespace std;

void check(int n, int * arr)
{
	//cout << "test for " << n;
	while (n != 1) {
		if ((n&1) == 0) {
			n = n>>1;
		} else {
			n = (3*n + 1) >> 1;
		}
		//cout << n << " ";
		if( n > 100 || arr[n] == 1) break;
		arr[n] = 1;
	}
	//cout << endl;

	return ;
}

int main()
{
	int k, n[105];
	for (int i = 0; i < 101; ++i) {
		n[i] = -1;
	}
	cin>>k;
	int *p = new int[k];
	for (int i = 0; i < k; ++i) {
		cin >> p[i];
		n[p[i]] = 0;
	}

	for (int i = 0; i < k; ++i) {
		check(p[i], n);
	}

	bool isFirst = true;
	for (int i = 100; i > 1; --i) {
		if (n[i] == 0) {
			if (isFirst) {
				cout << i;
				isFirst = false;
			} else {
				cout << " " << i;
			}
		}
	} cout << endl;

	delete[] p;
	return 0;
}
