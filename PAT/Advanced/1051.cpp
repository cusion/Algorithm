#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

bool isValid(int seq[], int len, int cap) {
	stack <int> s;
	int cur = 1;
	int ind = 0;
	while (ind < len) {
		while (s.empty() || s.top() != seq[ind]) {
			if (cur > seq[ind] || s.size() >= cap) return false;
			s.push(cur++);
		}
		s.pop();
		++ind;
	}
	
	return true;
}

int main() {
	int m, n, k;
	cin >> m >> n >> k;
	int seq[n];
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &seq[j]);
		}
		if (isValid(seq, n, m)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
