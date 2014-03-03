#include <iostream>
#include <cstdio>

/*
 * test 1: 3 4 -5 2 6 1 -2 0 -4 -1 4 -5 3 -7
 * test 2: 0 4 -5 2 2 0 -4 -1 -8 -4
 */

using namespace std;

int main()
{
	int f, e;
	bool isFirst = true;
	while (cin>>f>>e) {
		if (e != 0 && f != 0) {
			if(!isFirst){
				cout << " ";
			}
			cout << f*e << " " << e-1;
		
			isFirst = false;
		}
	}
	if (isFirst) cout << "0 0";   // bullshit
	cout << endl;

	return 0;
}
