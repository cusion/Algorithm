#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 200000

int prime[10005];
bool isPrime[200005];

void sieve(int M, int N)
{
	int cnt = 0;

	for (int i = 0; i <= MAX; ++i) {
		isPrime[i] = true;
	}

	for (int i = 2; i <= MAX; ++i) {
		if (isPrime[i]) {
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && prime[j]*i <= MAX; ++j) {
			isPrime[prime[j]*i] = false;
			if (i%prime[j]==0){
				break;
			}
		}
		if (cnt >= 10001) break;
	}

	int outCnt = 0;
	bool isFirst = true;
	for (int i = M-1; i < N; ++i){
		if (!isFirst) {
			cout << " ";
		}
		cout << prime[i];
		isFirst = false;

		if (outCnt == 9 || i == N-1) {
			cout << endl;
		}

		outCnt = (outCnt+1)%10;
		if (outCnt == 0) isFirst = true;
	}
}

int main()
{
	int M, N;
	cin >> M >> N;
	sieve(M, N);

	return 0;
}
