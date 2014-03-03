#include <iostream>
#include <cstdio>

using namespace std;

char table[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
	char *arr = new char[105];
	gets(arr);
	int sum = 0;
	for (int i = 0; arr[i] != '\0'; ++i) {
		sum += arr[i] - '0';
	}
	int cnt = 0;
	int *digits = new int[100];
	while (sum) {
		digits[cnt++] = sum%10;
		sum = sum/10;
	}
	if (cnt == 0) {
		digits[cnt++] = 0;
	}

	for (int i = cnt-1; i >0; --i) {
		cout << table[digits[i]] << " ";
	}
	cout << table[digits[0]] << endl;

	delete[] arr;
	delete[] digits;
	
	return 0;
}
