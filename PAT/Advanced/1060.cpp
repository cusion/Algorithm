#include <cstdio>
#include <iostream>
#include <cstring>

struct SciForm {
	char num[105];
	int coef;
	SciForm(){}
	SciForm(char n[]) {
		//puts(n);
		int firstNonZeroIndx = 0;
		int pointIndx = 0;
		while (n[firstNonZeroIndx] != '\0') {
			if (n[firstNonZeroIndx] != '0' && n[firstNonZeroIndx] != '.') {
				break;
			}
			++firstNonZeroIndx;
		}
		while (n[pointIndx] != '\0') {
			if (n[pointIndx] == '.') {
				break;
			}
			++pointIndx;
		}
		//printf("%c\n", n[firstNonZeroIndx]);
		if (n[firstNonZeroIndx] == '\0') {
			coef = 0;
			num[0] = '0';
			num[1] = '.';
			num[2] = '0';
			num[3] = '\0';
		} else {
			if (pointIndx < firstNonZeroIndx) {
				coef = pointIndx - firstNonZeroIndx + 1;
			} else {
				coef = pointIndx - firstNonZeroIndx;
			}
			int ind = firstNonZeroIndx;
			num[0] = '0';
			num[1] = '.';
			int cnt = 2;
			while (n[ind] != '\0') {
				if (n[ind] == '.') {
					++ind;
					continue;
				} else {
					num[cnt++] = n[ind];
				}
				++ind;
			}
			num[cnt] = '\0';
		}
	}
};

bool isEqual(const SciForm &a, const SciForm &b, int sig) {
	for (int i = 0; i < sig+2; ++i) {
		if (a.num[i] == '\0') {
			if (b.num[i] != '\0') {
				return false;
			}
		} else if (b.num[i] == '\0') {
			if (a.num[i] != '\0') {
				return false;
			}
		} else {
			if (a.num[i] != b.num[i]) {
				return false;
			}
		}
	}
	return a.coef == b.coef;
}

void printNum(SciForm a, int sig) {
	int i;
	for (i = 0; i < sig+2 && a.num[i] != '\0'; ++i) {
		printf("%c", a.num[i]);
	}
	while (i < sig+2) {
		printf("0");
		++i;
	}
	printf("*10^%d", a.coef);
}

int main() {
	
	char num[2][105];
	SciForm * A, *B;
	int coef[2];
	int n;
	scanf("%d%s%s", &n, num[0], num[1]);
	A = new SciForm(num[0]);
	//puts("testa");
	B = new SciForm(num[1]);
	//puts("testb");
	if (isEqual(*A, *B, n)) {
		printf("YES ");
		printNum(*A, n);
		puts("");
	} else {
		printf("NO ");
		printNum(*A, n);
		printf(" ");
		printNum(*B, n);
	}
	
	delete A, B;
	return 0;
}
