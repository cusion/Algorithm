#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int p = 0, k = 0;
	printf("%d=", n);
	
	if (n == 1){
		puts("1");
		return 0;
	}

	int i;
	for (i = 2; i*i <= n; ++i) {
		if((n%i) == 0) {
			p = i;
			k++;
			n = n / p;
			while((n%p) == 0) {
				k++;
				n = n/p;
			}
			++i;
			break;
		}
	}

	if ((p==0)&&(k==0)){
		printf("%d\n", n);
		return 0;
	}

	printf("%d", p);
	if (k>1) printf("^%d", k);

	if (n>1){
		p = k = 0;
		for (; i*i <= n; ++i) {
			if ((n%i) == 0) {
				p = i;
				k = 1;
				n = n / p;
				while((n%p) == 0) {
					k++;
					n = n/p;
				}
				printf("*%d", p);
				if (k>1) printf("^%d", k);
			}
			if (n == 1) break;
			p = k = 0;
		}
		if ((p==0) && (k==0)) {
			printf("*%d", n);
		}
	}
	puts("");

	return 0;
}
