#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

#define RADIX 36

int getHashKey(char *str) {
	int ret = 0;
	for (int i = 0; i < 3; ++i) {
		ret = ret*RADIX + str[i] - 'A';
	}
	ret = ret*RADIX + str[3] - '0';
	
	return ret;
}

int main() {
	unordered_map <int, vector <int> > umap;
	unordered_map <int, vector <int> >::iterator itr;
	char name[5];
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i) {
		int courseId, num;
		scanf("%d%d", &courseId, &num);
		for (int j = 0; j < num; ++j) {
			scanf("%s", name);
			int key = getHashKey(name);
			itr = umap.find(key);
			if (itr == umap.end()) {
				vector <int> course;
				course.push_back(courseId);
				umap.insert(pair<int , vector <int> >(key, course));
			} else {
				(itr->second).push_back(courseId);
			}
		}
	}
	
	for (int i = 0; i < n; ++i) {
		scanf("%s", name);
		int key = getHashKey(name);
		sort(umap[key].begin(), umap[key].end());
		printf("%s %d", name, umap[key].size());
		for (int j = 0; j < umap[key].size(); ++j) {
			printf(" %d", umap[key][j]);
		}
		puts("");
	}	
	
	return 0;
}
