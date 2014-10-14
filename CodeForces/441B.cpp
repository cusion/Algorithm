#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

inline int min(int a, int b) {
	return a < b ? a : b;
}

inline int max(int a, int b) {
	return a > b ? a : b;
}

struct Node {
	int day, fruits;
	bool friend operator <(Node a, Node b) {
		return a.day < b.day;
	}
};

int main() {
	int n, v;
	cin >> n >> v;
	Node tree[n+1];
	tree[n].fruits = -1;
	tree[n].day = 0x7fffffff;
	for (int i = 0; i < n; ++i) {
		cin >> tree[i].day >> tree[i].fruits;
	}
	sort(tree, tree+n);
	
	int len = 1;
	for (int i = 1; i < n; ++i) {
		if (tree[i-1].day == tree[i].day) {
			tree[len-1].fruits += tree[i].fruits;
		} else {
			tree[len].day = tree[i].day;
			tree[len].fruits = tree[i].fruits;
			++len;
		}
	}
	
	int withering = 0, ripen = 0, preRipenDay = -1, ans = 0;
	for (int i = 0; i < len; ++i) {
		if (preRipenDay == tree[i].day-1) {
			withering = ripen;
		} else {
			ans += min(v, ripen);
			withering = 0;
		}
		
		ripen = tree[i].fruits;
		preRipenDay = tree[i].day;
		
		if (v > withering) {
			ans += withering;
			if (v - withering > ripen) {
				ans += ripen;
				ripen = 0;
			} else {
				ans += v-withering;
				ripen -= (v-withering);
			}
		} else {
			ans += v;
		}
	}
	ans += min(v, ripen);
	
	cout << ans << endl;
	return 0;
}
