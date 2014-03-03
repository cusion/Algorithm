#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 0) {
		puts("0");
		return 0;
	}
	int obj;
	int *box = new int[n];
	int boxnum = 1;
	int boxcap = 100;

	cin >> obj;
	box[0] = obj;
	cout << obj << " " << "1" << endl;

	for (int i = 1; i < n; ++i) {
		cin >> obj;
		bool isBoxed = false;
		for (int j = 0; j < boxnum; ++j) {
			if (box[j] + obj <= boxcap) {
				isBoxed = true;
				box[j] += obj;
				cout << obj << " " << j+1 << endl;
				break;
			}
		}
		if (!isBoxed) {
			boxnum++;
			box[boxnum-1] = obj;
			cout << obj << " " << boxnum << endl;
		}
	}
	cout << boxnum << endl;

	delete[] box;
	return 0;
}
