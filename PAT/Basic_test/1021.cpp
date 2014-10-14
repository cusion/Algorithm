#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	string num;
	cin >> num;
	int cnt[10];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < num.length(); ++i) {
		cnt[num[i]-'0']++;
	}
	for (int i = 0; i < 10; ++i) {
		if (cnt[i] > 0) {
			cout << i << ":" << cnt[i] << endl;
		}
	}
	return 0;
}
