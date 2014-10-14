#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Pair {
	int id;
	int coord;
	friend bool operator < (Pair a, Pair b) {
		return a.coord < b.coord;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<Pair> points(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &points[i].coord);
		points[i].id = i;
	}
	for (int i = 0; i < m; ++i) {
		int a,b;
		scanf("%d %d", &a, &b);
	}
	sort(points.begin(), points.end());
	vector<int> colors(n);
	for (int i = 0; i < n; ++i) {
		colors[points[i].id] = i % 2;
	}
	
	for (int i = 0; i < n; ++i) {
		if (i == n-1) {
			printf("%d\n", colors[i]);
		} else {
			printf("%d ", colors[i]);
		}
	}
	return 0;
}
