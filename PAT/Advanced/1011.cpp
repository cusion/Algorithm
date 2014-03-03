#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

char num2bet(int num) {
	switch(num) {
		case 0:
			return 'W';
		case 1:
			return 'T';
		case 2:
			return 'L';
	}
}

int main() {
	double arr[3] = {0, 0, 0};
	int bet[3] = {0, 0, 0};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			double tmp;
			cin >> tmp;
			if (arr[i] < tmp) {
				arr[i] = tmp;
				bet[i] = j;
			}
		}
	}
	double ans = 1;
	for (int i = 0; i < 3; ++i) {
		//cout << arr[i] << endl;
		ans *= arr[i];
		cout << num2bet(bet[i]) << " ";
	}
	//cout << ans << endl;
	printf("%.2f\n", (ans*0.65-1)*2);
	return 0;
}
