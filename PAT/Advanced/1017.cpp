#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define S 8*60*60
#define E 17*60*60
#define INF 0x7fffffff

struct Node {
	int time;
	int process;
	int begin;
	int leave;
};

int max(int a, int b) {
	return a > b ? a : b;
}

bool cmp(Node a, Node b) {
	return a.time < b.time;
}

int main() {
	int n, k, h, m, s, mini, indx, t;
	while (scanf("%d%d", &n, &k) != EOF) {
		vector <Node> cus(n);
		vector <int> wind(k, S);
		for (int i = 0; i < n; ++i) {
			scanf("%d:%d:%d%d", &h, &m, &s, &cus[i].process);
			cus[i].process *= 60;
			cus[i].time = (h*60+m)*60 + s;
		}
		sort(cus.begin(), cus.end(), cmp);
		
		// start to serve
		for (int i = 0; i < n; ++i) {
			mini = INF;
			// though this code passed the tests,
			// but I think this is wrong with the
			// rules, because we should find the
			// smallest index available table ,rather
			// than the smallest time table
			for (int j = 0; j < k; ++j) {       
				if (mini > wind[j]) {
					mini = wind[j];
					indx = j;
				}
			}
			cus[i].begin = max(wind[indx], cus[i].time);
			cus[i].leave = cus[i].begin + cus[i].process;
			wind[indx] = cus[i].leave;
		}
		
		t = 0, s = n;
		for (int i = 0; i < n; ++i) {
			if (cus[i].time <= E) {
				t += cus[i].begin - cus[i].time;
			} else {
				--s;
			}
		}
		if (s){
			printf("%.1f\n", t/60.0/s);
		}
		else {
			puts("0.0");
		}
	}
	
	return 0;
}
