#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 100005
int arr[MAX], aidx[MAX], swapa[5*MAX], swapb[5*MAX], primes[MAX];
bool isPrime[MAX];

void getPrime() {
	for (int i = 0; i < MAX; ++i) {
		isPrime[i] = true;
	}
	int cnt = 0;
	for (int i = 2; i < MAX; ++i) {
		if (isPrime[i]) {
			primes[cnt++] = i;
		}
		for (int j = 0; j < cnt && primes[j]*i < MAX; ++j) {
			isPrime[primes[j]*i] = false;
			if ((i%primes[j]) == 0) {
				break;
			}
		}
	}
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	getPrime();
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr+i);
		aidx[arr[i]] = i;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		while (arr[i] != i) {
			int pos = aidx[i];
			int j;
			for (j = i; !isPrime[pos-j+1]; ++j);
			swap(arr[pos], arr[j]);
			swapa[cnt] = j;
			swapb[cnt++] = pos;
			pos = arr[pos], j = arr[j];
			swap(aidx[pos], aidx[j]);
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < cnt; ++i) {
		cout << swapa[i] << " " << swapb[i] << endl;
	}
	return 0;
}
