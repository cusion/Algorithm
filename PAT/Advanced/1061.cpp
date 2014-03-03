#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool isUpperCase(char ch) {
	return ch >= 'A' && ch <= 'Z';
}

bool isValidHour(char ch) {
	return (ch >= 'A' && ch <= 'N') || (ch >= '0' && ch <= '9');
}

bool isValidDay(char ch) {
	return (ch >= 'A' && ch <= 'G');
}

bool isCharacter(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int main() {
	char day[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	string input[4];
	for (int i = 0; i < 4; ++i) {
		cin >> input[i];
	}
	int d, h, m;
	int cnt = 0;
	for (int i = 0; i < input[1].length() && input[0].length(); ++i) {
		if (input[0][i] == input[1][i]) {
			if (cnt == 0 && isValidDay(input[1][i])) {
				//cout << input[1][i] << endl;
				d = input[1][i]-'A';
				++cnt;
			} else if (isValidHour(input[1][i]) && cnt == 1) {
				if (isUpperCase(input[1][i])) {
					h = input[1][i] - 'A' + 10;
				//cout << input[1][i] << endl;
				} else {
					h = input[1][i] - '0';
				}
				break;
			}
		}
	}
	//cout << d << "--" << h << endl; 
	for (int i = 0; i < input[2].length() && i < input[3].length(); ++i) {
		if (isCharacter(input[2][i]) && input[2][i] == input[3][i]) {
			//cout << input[2][i] << endl;
			m = i;
			break;
		}
	}
	
	printf("%s %02d:%02d\n", day[d], h, m);
	
	return 0;
}
