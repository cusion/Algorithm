#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
	if (n == 0 || n == 1) {
		return false;
	}
	for (int i = 2; i*i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	
	return true;
}

int getTsize(int tsize) {
	if (tsize == 0 || tsize == 1) {
		return 2;
	}
	while (!isPrime(tsize)) {
		++tsize;
	}
	return tsize;
}

int myhash(vector<bool> &table, int val) {
	if (table.size() <= 0) {
		return -1;
	}
	int inc = 0;
	int idx = val % table.size();
	while (inc < table.size() && table[idx]) {
		++inc;
		idx = (val+inc*inc) % table.size();
	}
	if (inc < table.size()) {
		table[idx] = true;
		return idx;
	}
	return -1;
}

int main() {
	int m,n;
	cin >> m >> n;
	vector<bool> table(getTsize(m), false);
	int tmp;
	if (n > 0) {
		scanf("%d", &tmp);
		printf("%d", myhash(table, tmp));
	}
	for (int i = 0; i < n-1; ++i) {
		scanf("%d", &tmp);
		tmp = myhash(table, tmp);
		if (tmp >= 0) {
			printf(" %d", tmp);
		} else {
			printf(" -");
		}
	}puts("");
	return 0;
}
