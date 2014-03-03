#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long T;
    int	A, B, C;
	cin >> T;
	for (long long i = 0; i < T; ++i) {
		cin >> A >> B >> C;
		cout << "Case #" << i+1 << ": ";
		
		if (A > 0 && B > 0){
			if (A + B < 0 || A+B > C){   // the method to handle the over-flow should be different from what we think
				cout << "true";
			} else{
				cout << "false";
			}
		} else if(A < 0 && B < 0) {
			if (A + B < 0 && A + B > C) {
				cout << "true";
			} else {
				cout << "false";
			}
		} else {
			if (A+B > C) {
				cout << "true";
			} else {
				cout << "false";
			}
		}
		/*if (A+B > C) {
			cout << "true";
		} else {
			cout << "false";
		}*/
		cout << endl;
	}

	return 0;
}
