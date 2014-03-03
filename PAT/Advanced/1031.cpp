#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int len = str.length() + 2;
	int ver, hor;
	/* I think this method would result in a most squared U-shape rather than 
	   the way depicted in the problem;
	if (len % 3 == 0) {
		ver = hor = len / 3;
	} else if (len % 3 == 1) {
		ver = len / 3;
		hor = ver + 1;
	} else if (len % 3 == 2) {
		hor = len / 3;
		ver = hor + 1;
	}*/
	if (len % 3 == 0) {
		ver = hor = len/3;
	} else {
		ver = len / 3;
		hor = ver + (len%3);
	}
	
	char arr[ver][hor];
	for (int i = 0; i < ver; ++i) {
		for (int j = 0; j < hor; ++j) {
			arr[i][j] = ' ';
		}
	}
	for (int i = 0; i < ver-1; ++i) {
		arr[i][0] = str[i];
	}
	for (int i = 0; i < hor-1; ++i) {
		arr[ver-1][i] = str[ver-1+i];
	}
	for (int i = 0; i < ver; ++i) {
		arr[ver-1-i][hor-1] = str[ver-1+hor-1+i];
	}
	
	for (int i = 0; i < ver; ++i) {
		for (int j = 0; j < hor; ++j) {
			printf("%c", arr[i][j]);
		}puts("");
	}
	return 0;
}
