#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 100005

int home[MAX], away[MAX], cntHome[MAX], cntAway[MAX], cnt[MAX];

/********** O(N^2) TLE ************
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", home+i, away+i);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (home[i] == away[j]) {
					++cntHome[j];
			} else {
				++cntAway[j];
			}
			++cntHome[i];
				
			if (away[i] == home[j]) {
				++cntHome[i];
			} else {
				++cntAway[i];
			}
			++cntHome[j];
		}
	}
	
	for (int i = 0; i < n; ++i) {
		//cout << cntHome[i] << " " << cntAway[i] << endl;
		printf("%d %d\n",cntHome[i], cntAway[i]);
	}
	return 0;
}*/

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", home+i, away+i);
		cnt[home[i]]++;
	}
	
	for (int i = 0; i < n; ++i) {
		cntHome[i] = n - 1;        // because when the team plays at home, it will always use home kit
		cntHome[i] += cnt[away[i]];    // when the team plays away, it will use home kit when there exists same color with its away kit
		
		cntAway[i] = 2*(n-1) - cntHome[i]; // because each team would only play 2*(n-1) games, it will either wear home kit or away kit
	}
	
	for (int i = 0; i < n; ++i) {
		cout << cntHome[i] << " " << cntAway[i] << endl;
	}
	return 0;
}
