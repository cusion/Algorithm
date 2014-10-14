#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
#define abs(a) ((a)>0?(a):(-(a)))

int sqrt(int x) {
	if (x <= 1) {
		return x;
	}
	double rold = 1;
	double rnew = rold - (rold*rold-x)/(2*rold);
	//cout << rold << " " << rnew << endl;
	 while(abs(rnew-rold)>1e-3) {
	 	rold = rnew;
		rnew = rold - (rold*rold-x)/(2*rold);
		//cout << "sqrt " << rnew << " " << rold << " " << abs(rnew-rold) << endl;
		//system("pause");
	}
	
	return (int)rnew;
}

int main() {	
	int a;
	cin >> a;
	cout << sqrt(a) << endl;
	return 0;
}
