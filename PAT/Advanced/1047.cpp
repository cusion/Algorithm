#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct Student {
	char name[5];
	
	Student() {}
	Student(char n[]) {
		int i;
		for (i = 0; n[i] != '\0'; ++i) {
			name[i] = n[i];
		}
		name[i] = '\0';
	}
	
	friend bool operator <(Student a, Student b) {
		if (strcmp(a.name, b.name) < 0) {
			return true;
		} else {
			return false;
		}
	}
};

int main() {
	
	int n, k;
	cin >> n >> k;
	vector <vector<Student> > courses(k);
	char name[5];
	int c, cid;
	for (int i = 0; i < n; ++i) {
		scanf("%s%d", name, &c);
		for (int j = 0; j < c; ++j) {
			scanf("%d", &cid);
			courses[cid-1].push_back(Student(name));
		}
	}
	
	for (int i = 0; i < k; ++i) {
		sort(courses[i].begin(), courses[i].end());
		printf("%d %d\n", i+1, courses[i].size());
		for (int j = 0; j < courses[i].size(); ++j) {
			printf("%s\n", courses[i][j].name);
		}
	}
	
	return 0;
}
