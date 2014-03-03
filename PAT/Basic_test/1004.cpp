#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Member {
	char name[15];
	char stu[15];
	int score;
} members[2];

int main() {
	int n;
	Member tmp;
	members[0].score = -1;
	members[1].score = 101;
	cin >>n;
	while ( n--) {
		scanf("%s %s %d", &tmp.name, &tmp.stu, &tmp.score);
		if (tmp.score > members[0].score) {
			members[0] = tmp;
		}
		if (tmp.score < members[1].score) {
			members[1] = tmp;
		}
	}

	cout << members[0].name << " " << members[0].stu << endl;
	cout << members[1].name << " " << members[1].stu << endl;

	return 0;
}
