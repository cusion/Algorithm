#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string A, B;
	char Da, Db;
	long long pa = 0, pb = 0;
	cin >> A >> Da >> B >> Db;
	//cout << A <<" "<< Da<<" " << B << " " << Db << endl;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] == Da) {
			pa = pa*10 + Da - '0';
		}
	}
	for (int i = 0; i < B.size(); ++i) {
		if (B[i] == Db) {
			pb = pb*10 + Db - '0';
		}
	}
	
	cout << pa + pb << endl;
	
	return 0;
}
