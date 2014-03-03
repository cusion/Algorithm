#include <iostream>
#include <cstdio>

using namespace std;

bool isDay(char ch)
{
	if (ch >= 'A' && ch <= 'G') return true;

	return false;
}

bool isHour(char ch)
{
	if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'N')) return true;

	return false;
}

bool isCharacter(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return true;

	return false;
}

char Map[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	char str[4][65];
	for (int i = 0; i < 4; ++i) {
		gets(str[i]);
	}
	int secInd = 0; 
	char d = 'X', h;
	int tInd = 0, sameCnt = 0;

	for (int i = 0; str[1][i] != '\0' && str[0][i] != '\0'; ++i) {
		if (str[0][i] == str[1][i]) {
			if (tInd > 0) sameCnt++;
			if (isDay(str[0][i]) && d == 'X'){
				d = str[0][i];
				tInd++;
				sameCnt++;
			}
			if (sameCnt >= 2 && isHour(str[0][i])) {
				h = str[0][i];
				tInd++;
			}
		}

		if (tInd >= 2) break;
	}
	for (int i = 0; str[2][i] != '\0' && str[3][i] != '\0'; ++i) {
		if (str[2][i] == str[3][i] && isCharacter(str[3][i])) {
			secInd = i;
			break;
		}
	}

	cout << Map[d - 'A'] << " ";
	if (h >= '0' && h <= '9') {
		cout << '0' << h;
	} else {
		cout << (h-'A'+10);
	}
	printf(":%02d\n", secInd);

	return 0;
}
