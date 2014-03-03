#include <cstdio>
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void sortColors(int A[], int n) {
	if (n == 0) {
		return;
	}
	int indx0 = 0, indx1 = 0, indx2 = n-1;
	while (indx1 <= indx2) {
		if (A[indx1] == 0) {
			if (indx0 < indx1) {
				swap(A[indx0++], A[indx1]);
			} else {
				++indx0;
				++indx1;
			}
		} else if (A[indx1] == 2) {
			if (indx1 < indx2) {
				swap(A[indx1], A[indx2--]);
			} else {
				return ;
			}
		} else {
			++indx1;
		}
	}
	
	return;
}

/**************** two-pass way **************
void sortColors(int A[], int n) {
	if (n == 0) {
		return ;
	}
	int colorCnt[3];
	colorCnt[0] = colorCnt[1] = colorCnt[2] = 0;
	for (int i = 0; i < n; ++i) {
		++colorCnt[A[i]];
	}
	int indx = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < colorCnt[i]; ++j) {
			A[indx++] = i;
		}
	}
	return ;
}*/

int main() {
	return 0;
}
