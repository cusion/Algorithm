#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


int countOnes1(int i) {
	int ret = 0;
	while (i) {
		if ((i%10) == 1) {
			++ret;
		}
		i /= 10;
	}
	
	return ret;
}

int countTest(int n) {
	if (n <= 1) {
		return n;
	} else {
		int count = 1;
		for (int i = 2; i <= n; ++i) {
			count += countOnes1(i);
		}
		return count;
	}
}/***************  Naive Solution ********************/

int atoi(char str[]) {
	int ret = 0;
	int indx = 0;
	while (str[indx] != '\0') {
		ret = ret*10 + str[indx] - '0';
		++indx;
	}
	
	return ret;
}

int pow(int base, int exp) {
	int ret = 1;
	for (int i = 0; i < exp; ++i) {
		ret *= base;
	}
	
	return ret;
}

int countOnesString(char str[]) {
	int len = strlen(str);
	if (len == 0) {
		return 0;
	}
	if (len == 1) {
		return str[0] == '0' ? 0 : 1;
	}
	
	int firstDigit = str[0] - '0';
	
	int numFirstDigit = 0;
	if (firstDigit == 1) {
		numFirstDigit = atoi(str+1) + 1;
	} else {
		numFirstDigit = (int)pow(10, len-1);
	}
	
	int numOtherDigit = firstDigit * (len-1) * pow(10, len-2);
	
	char *strRest = str+1;
	while ((*strRest) == '0') {
		++strRest;
	}
	// << "test " << numFirstDigit << " " << numOtherDigit << endl;
	return numFirstDigit + numOtherDigit + countOnesString(strRest);
}

int countOnes(int i) {
	char str[50];
	sprintf(str, "%d", i);
	return countOnesString(str);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ans = countOnes(n);
		printf("%d\n", ans);
		//cout << countTest(n) << endl;
		//puts("-------");
	}
	return 0;
}
