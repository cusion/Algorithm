#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	char * str = new char[105];
	int aLeft=0, aMid=0, aRight=0;
	int n;
	cin >> n;
	while (n--) {
		cin >> str;

		int ind = 0;
		aLeft = aMid = aRight = 0;
		while (str[ind] == 'A') {
			aLeft++;
			ind++;
		}
		if(str[ind] == 'P') {
			ind++;
			while (str[ind] == 'A') {
				aMid++;
				ind++;
			}
			if (str[ind] == 'T') {
				ind++;
				while (str[ind] == 'A') {
					ind++;
					aRight++;
				}
				if (str[ind] != '\0') {
					cout << "NO" << endl;
				} else if(aMid > 0 && aRight == aLeft*aMid) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			} else {
				cout << "NO" << endl;
			}
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
