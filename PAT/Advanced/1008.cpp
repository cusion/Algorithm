#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int req;
	int cur = 0;
	int time = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &req);
		if (req == cur) {
			time += 5;
		} else if (req < cur) {
			time += (cur-req)*4 + 5;
		} else {
			time += (req-cur)*6 + 5;
		}
		cur = req;
	}
	cout << time << endl;
	return 0;
}
