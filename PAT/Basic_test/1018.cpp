#include <cstdio>
#include <iostream>
using namespace std;

int simbol2num(char ch) {
	switch(ch) {
		case 'B':
			return 0;
		case 'C':
			return 1;
		case 'J':
			return 2;
	}
}

char num2simbol(int i) {
	switch(i) {
		case 0:
			return 'B';
		case 1:
			return 'C';
		case 2:
			return 'J';
	}
}

int compete(char a, char b) {
	int anum = simbol2num(a);
	int bnum = simbol2num(b);
	
	if (anum-bnum == -1 || anum-bnum == 2){
		return 1;
	} else if (anum-bnum == 0) {
		return 0;
	} else {
		return -1;
	}
}

int main() {
	int a[3], am[3], b[3], bm[3];  // 0 for win, 1 for tie, 2 for lose;0 for B, 1 for C, 2 for J;
	int n;
	char ap, bp;
	cin >> n;
	for (int i = 0; i < 3; ++i) {
		a[i] = b[i] = am[i] = bm[i] = 0;
	}
	while (n--) {
		getchar();
		scanf("%c %c", &ap, &bp);
		//cout << ap << " " << bp << endl;
		int res = compete(ap, bp);      // -1 for a loses, 0 for tie, 1 for a wins
		switch (res) {
			case -1:
				++b[0];
				++a[2];
				++bm[simbol2num(bp)];
				break;
			case 0:
				++b[1];
				++a[1];
				break;
			case 1:
				++a[0];
				++b[2];
				++am[simbol2num(ap)];
				break;
		}
	}
	int amind = 0, bmind = 0;
	for (int i = 1; i < 3; ++i) {
		if (am[i] > am[amind]) {
			amind = i;
		}
		if (bm[i] > bm[bmind]) {
			bmind = i;
		}
	}
	
	cout << a[0] << " " << a[1] << " " << a[2] << endl;
	cout << b[0] << " " << b[1] << " " << b[2] << endl;
	cout << num2simbol(amind) << " " << num2simbol(bmind) << endl;
	return 0;
}
