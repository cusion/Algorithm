#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	srand(time(0));
	for (int i = 0; i < 10; ++i) {
		cout << rand()%100000000 << endl;
	}
	
	return 0;
}
