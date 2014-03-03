#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, e;
	int A1=0, A2=0, A3=0, A5=-1;
	double A4 = 0;
	int flag = 1;
	int cntA4 = 0;
	bool bA1 = false, bA2 = false, bA3 = false, bA5 = false;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> e;
		if (e % 5 == 0) {
			if((e & 1) == 0) {
				A1 += e;
				bA1 = true;
			}
		} else if (e%5 == 1) {
			bA2 = true;
			A2 += flag*e;
			flag = -1*flag;
		} else if (e%5 == 2) {
			A3++;
			bA3 = true;
		} else if (e%5 == 3) {
			cntA4++;
			A4 += e;
		} else {
			bA5 = true;
			A5 = e > A5 ? e : A5;
		}
	}

	if (bA1) {
		cout << A1 << " ";
	} else {
		cout << "N ";
	}

	if (bA2) {
		cout << A2 << " ";
	} else {
		cout << "N ";
	}

	if (bA3) {
		cout << A3 << " ";
	} else {
		cout << "N ";
	}
	
	if (cntA4) {
		printf("%.1lf ", A4/cntA4);
	} else {
		cout << "N ";
	}

	if (bA5) {
		cout << A5 << endl;
	} else {
		cout << "N" << endl;
	}

	return 0;
}
