#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool changePassword(string &str) {
	bool isChanged = false;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '1') {
			str[i] = '@';
			isChanged = true;
		} else if (str[i] == '0') {
			str[i] = '%';
			isChanged = true;
		} else if (str[i] == 'l') {
			str[i] = 'L';
			isChanged = true;
		} else if (str[i] == 'O') {
			str[i] = 'o';
			isChanged = true;
		}
	}
	
	return isChanged;
}

int main() {
	int n;
	cin >> n;
	vector <string> accounts;
	for (int i = 0; i < n; ++i) {
		string name, psw;
		cin >> name >> psw;
		if (changePassword(psw)) {
			accounts.push_back(name);
			accounts.push_back(psw);
		}
	}
	
	if (accounts.size() > 0) {
		cout << accounts.size()/2 << endl;
		for (int i = 0; i < accounts.size(); i+=2) {
			cout << accounts[i] << " " << accounts[i+1] << endl;
		}
	} else {
		if (n > 1) {
			printf("There are %d accounts and no account is modified\n", n);
		} else {
			puts("There is 1 account and no account is modified");
		}
	}
	
	return 0;
}
