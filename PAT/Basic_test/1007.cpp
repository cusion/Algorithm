#include <iostream>
#include <cstdio>
#define MAX 100002
using namespace std;

int N;
bool isPrime[MAX+1];
int primeCnt, prime[MAX+1];

void sieve(){
	for(int i = 0; i <= N; ++i) {
		isPrime[i] = true;
	}
	primeCnt = 0;
	for (int i = 2; i <= N; ++i) {
		if (isPrime[i]) {
			prime[primeCnt++] = i;
		}
		for (int j = 0; (j < primeCnt) && (i*prime[j] <= N); ++j) {
			isPrime[i*prime[j]] = false;
			if ((i%prime[j]) == 0) break;
		}
	}
}

int main() {
	cin>>N;
	sieve();
	int cnt = 0;
	for (int i = 1; i < primeCnt; ++i) {
		//cout << prime[i] << " ";
		if(prime[i] - prime[i-1] == 2)cnt++;
	}
	//cout << endl;
	cout << cnt <<endl;

	return 0;
}
