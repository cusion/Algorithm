#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

int hashCode(char name[]) {
	int ret = 0;
	ret = name[0] - 'A' + 10;
	ret = ret*36 + name[1] - 'A' + 10;
	ret = ret*36 + name[2] - 'A' + 10;
	ret = ret*36 + name[3] - '0';
	return ret;
}

int main() {
	int n, k;
	unordered_map<int, vector<int> > students;
	cin >> n >> k;
	char name[5];
	int courseId, num;
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &courseId, &num);
		for (int j = 0; j < num; ++j) {
			scanf("%s", name);
			students[hashCode(name)].push_back(courseId);
		}
	}
	for (auto it = students.begin(); it != students.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", name);
		int hashID = hashCode(name);
		unordered_map<int, vector<int> >::iterator itr;
		if ((itr = students.find(hashID)) == students.end()) {
			printf("%s 0\n", name);
		} else {
			printf("%s %d", name, itr->second.size());
			for (int j = 0; j < itr->second.size(); ++j) {
				printf(" %d", itr->second[j]);
			}puts("");
		}
	}
	
	return 0;
}
