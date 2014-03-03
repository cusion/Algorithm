#include <cstdio>
#include <iostream>
#include <algorithm>

#define NUM 4

using namespace std;

void num2arr(int *arr, int n) {
	int ind = NUM-1;
	while (n && ind >= 0) {
		arr[ind] = n%10;
		n /= 10;
		ind--;
	}
	while (ind >= 0) {
		arr[ind] = 0;
		ind--;
	}
	return ;
}

int arr2num(int *arr, int flag) {
	int ret = 0;
	if (flag == 0) {
		for (int i = 0; i < NUM; ++i) {
			ret = ret*10 + arr[i];
		}
	} else if (flag == 1) {
		for (int i = NUM-1; i >= 0; --i){
			ret = ret*10 + arr[i];
		}
	}
	return ret;
}

int main ()
{
	int n;
	int numarr[NUM], inc, dec;

	cin >> n;
	
	num2arr(numarr, n);
	
	do {
		sort(numarr, numarr+NUM);

		inc = arr2num(numarr, 0);
		dec = arr2num(numarr, 1);

		//cout << inc << "  " << dec << endl;
		//puts("press to continue...");getchar();getchar();
		for (int i = NUM-1; i >= 0; --i) {
			cout << numarr[i];
		}
		printf(" - ");
		for (int i = 0; i < NUM; ++i) {
			cout << numarr[i];
		}
		printf(" = ");
		n = dec - inc;
		num2arr(numarr, n);
		for (int i = 0; i < NUM; ++i) {
			cout << numarr[i];
		}
		puts("");
	} while (n!=0 && n!=6174);

	/*for (int i = 0; i < NUM; ++i) {
		cout << numarr[i] << " ";
	}puts("");*/

	return 0;
}
