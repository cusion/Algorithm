#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int digit, num;
	scanf("%d%d", &digit, &num);
	if (digit == 0||num == 0){
		puts("0");
		return 0;
	}
	int *res = new int[num+5];

	for (int i = 0; i < num+5; ++i) {
		res[i] = 0;
	}
	for (int i = 0; i < num; ++i) {
		res[i] = digit * (num - i);
	}
	
	for (int i = 0; i < num; ++i) {
		int left = res[i]%10;
		res[i] = res[i]/10;
		int inc = 1;
		while (res[i]) {
			res[i+inc] += res[i]%10;
			res[i] = res[i]/10;
			inc++;
		}
		res[i] = left;
	}
	int ind = num+4;
	while(res[ind] == 0)ind--;
	while (ind >= 0) {
		printf("%d", res[ind--]);
	}
	printf("\n");


	delete[] res;
	return 0;
}
