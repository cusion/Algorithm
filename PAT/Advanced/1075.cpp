#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Person {
	int id;
	int total;
	int perfect;
	Person(){}
	Person(int i, int t, int p):id(i), total(t), perfect(p){}
	
	friend bool operator <(Person a, Person b) {
		if (a.total > b.total) {
			return true;
		} else if (a.total < b.total) {
			return false;
		} else {
			if (a.perfect > b.perfect) {
				return true;
			} else if (a.perfect < b.perfect) {
				return false;
			} else {
				return a.id < b.id;
			}
		}
	}
};

#define MAX 10004
Person stu[MAX];
int score[MAX][6];

void printOne(const Person &stu, int rank, int k) {
	printf("%d %05d %d", rank, stu.id, stu.total);
	for (int i = 0; i < k; ++i) {
		if (score[stu.id][i] >= -1) {
			if (score[stu.id][i] <= 0) {
				printf(" 0");
			} else {
				printf(" %d", score[stu.id][i]);
			}
		} else {
			printf(" -");
		}
	}
	puts("");
}

/*bool checkValid(const Person &stu, int k) {
	for (int i = 0; i < k; ++i) {
		if (score[stu.id][i] >= 0) {
			return true;
		}
	}
	return false;
}*/

int main() {
	int n, k, sub;
	cin >> n >> k >> sub;
	for (int i = 1; i <= n; ++i) {
		stu[i].id = i;
		stu[i].total = -1000;
		stu[i].perfect = 0;
		for (int j = 0; j < k; ++j) {
			score[i][j] = -1000;             // label for unsubmitted, -1 for compile error
		}
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d", &score[0][i]);
	}
	for (int i = 0; i < sub; ++i) {
		int id, pro, sc;
		scanf("%d%d%d", &id, &pro, &sc);
		if (sc > score[id][pro-1]) {
			score[id][pro-1] = sc;
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < k; ++j) {
			if (score[i][j] >= 0) {
				if (stu[i].total < 0) {
					stu[i].total = 0;
				}
				stu[i].total += score[i][j];
				if (score[i][j] == score[0][j]) {
					stu[i].perfect++;
				}
			}
		}
	}
	sort(stu+1, stu+1+n);
	
	int rank = 1;
	printOne(stu[1], rank, k);
	for (int i = 2; i <= n; ++i) {
		if (stu[i].total != stu[i-1].total) {
			rank = i;
		}
		//if (checkValid(stu[i], k)) {
		if (stu[i].total >= 0) {
			printOne(stu[i], rank, k);
		} else {
			break;
		}
	}
	return 0;
}
