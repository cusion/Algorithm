#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#define MAX 10003

double calSimilarity(unordered_set<int> &seta, unordered_set<int> &setb) {
	if (seta.empty() || setb.empty()) {
		return 0;
	}
	
	/*for (auto it = seta.begin(); it != seta.end(); ++it) {
		cout << (*it) << " ";
	}puts("");
	for (auto it = setb.begin(); it != setb.end(); ++it) {
		cout << (*it) << " ";
	}puts("");*/
	
	int nc = 0;
	if (seta.size() < setb.size()) {
		for (auto it = seta.begin(); it != seta.end(); ++it) {
			if (setb.find((*it)) != setb.end()) {
				++nc;
			}
		}
	} else {
		for (auto it = setb.begin(); it != setb.end(); ++it) {
			if (seta.find((*it)) != seta.end()) {
				++nc;
			}
		}
	}
	
	return 1.0*nc/(seta.size()+setb.size()-nc);
}

int main() {
	int n;
	cin >> n;
	vector <unordered_set<int> > sets(n);
	for (int i = 0; i < n; ++i) {
		int m;
		scanf("%d", &m);
		for (int j = 0;  j < m; ++j) {
			int tmp;
			scanf("%d", &tmp);
			if (sets[i].find(tmp) == sets[i].end()) {
				sets[i].insert(tmp);
			}
		}
		
		/*for (auto it = sets[i].begin(); it != sets[i].end(); ++it) {
			cout << (*it) << " ";
		}puts("");*/
	}
	
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%.1f%%\n", 100*calSimilarity(sets[a-1], sets[b-1]));
	}
	
	return 0;
}

/**************** Time Limit Exceeded **************
double calSimilarity(int sets[][MAX], int len[], int sa, int sb) {
	unordered_set<int> mergeSet;
	int nc = 0;
	for (int i = 0; i < len[sa]; ++i) {
		if (mergeSet.find(sets[sa][i]) == mergeSet.end()) {
			mergeSet.insert(sets[sa][i]);
		}
	}
	
	unordered_set<int> setB;
	for (int i = 0; i < len[sb]; ++i) {
		if (setB.find(sets[sb][i]) == setB.end()) {
			setB.insert(sets[sb][i]);
			if (mergeSet.find(sets[sb][i]) == mergeSet.end()) {
				mergeSet.insert(sets[sb][i]);
			} else {
				++nc;
			}
		}
	}
	
	return 1.0*nc/mergeSet.size();
}

int main() {
	int n;
	cin >> n;
	int len[n];
	int sets[n][MAX];
	
	for (int i = 0; i < n; ++i) {
		cin >> len[i];
		for (int j = 0; j < len[i]; ++j) {
			scanf("%d", &sets[i][j]);
		}
	}
	
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%.1f%%\n", 100*calSimilarity(sets, len, a-1, b-1));
	}
	return 0;
}*/
