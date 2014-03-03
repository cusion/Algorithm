#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void shuffle(int poker[], int order[], int k) {
	vector <int> poker1(poker, poker+54);
	vector <int> poker2(54);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < 54; ++j) {
			poker2[order[j]] = poker1[j];
		}
		poker2.swap(poker1);
	}
	
	for (int i = 0; i < 54; ++i) {
		poker[i] = poker1[i];
	}
}

string num2poker(int num) {
	string ret;
	switch(num/13) {
		case 0:
			ret.append(1, 'S');
			break;
		case 1:
			ret.append(1, 'H');
			break;
		case 2:
			ret.append(1, 'C');
			break;
		case 3:
			ret.append(1, 'D');
			break;
		default:
			ret.append(1, 'J');
	}
	int rem = num % 13;
	if (rem < 9) {
		ret.append(1, '1' + rem);
	} else {
		ret.append(1, '1');
		ret.append(1, '0'+rem-9);
	}
	
	return ret;
}

int main() {
	int k;
	cin >> k;
	int order[54];
	int poker[54];
	for (int i = 0; i < 54; ++i) {
		scanf("%d", &order[i]);
		poker[i] = i;
		order[i] = order[i]-1;
	}
	shuffle(poker, order, k);
	
	for (int i = 0; i < 53; ++i) {
		cout << num2poker(poker[i]) <<" ";
	}
	cout << num2poker(poker[53]) << endl;
	
	return 0;
}
