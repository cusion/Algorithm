#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int tmp;
	queue <int> q[2];
	int alt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		if (q[alt].empty()) {
			q[alt].push(tmp);
		} else {
			if (tmp > q[alt].back()) {
				q[alt].push(tmp);
			} else {
				while (tmp > q[alt].front()) {
					q[(alt+1)%2].push(q[alt].front());
					q[alt].pop();
				}
				q[(alt+1)%2].push(tmp);
				while (!q[alt].empty()) {
					q[(alt+1)%2].push(q[alt].front());
					q[alt].pop();
				}
				alt = (alt+1)%2;
			}
		}
	}
	for (int i = 0; i < n-1; ++i) {
		printf("%d ", q[alt].front());
		q[alt].pop();
	}
	printf("%d\n", q[alt].front());

	return 0;
}
