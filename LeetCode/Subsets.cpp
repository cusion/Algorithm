#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/********************* Iterative Method ******************
vector <vector <int> > subsets (vector <int> &S) {
	vector <vector <int> > subs;
	vector <int> sub;
	subs.push_back(sub);
	if (S.empty()) {
		return subs;
	}
	sort(S.begin(), S.end());
	sub.resize(1);
	for (int i = 0; i < S.size(); ++i) {
		sub[0] = S[i];
		subs.push_back(sub);
	}
	int num = S.size();
	int start = 1;
	for (int i = 2; i <= S.size(); ++i) {
		int cnt = 0;
		for (int j = 0; j < num; ++j) {
			sub = subs[start+j];
			int maxElem = sub[i-2];
			sub.push_back(0);
			for (int k = S.size()-1; S[k] > maxElem; --k) {
				//cout << i << " " << S[k] << " " << maxElem << endl;
				//system("pause");
				++cnt; 
				sub[i-1] = S[k];
				subs.push_back(sub);
			}
		}
		start = start + num;
		num = cnt;
	}
	
	return subs;
}*/

/**************** Recursive Method *************/
void generateSubs(vector <vector <int> > &subs, vector <int> sub, vector <int> S, int len) {
	if (len == 0) {
		subs.push_back(sub);
		return;
	}
	int maxElem = sub.empty() ? S[0]-1 : sub[sub.size()-1];
	sub.push_back(0);
	for (int i = S.size()-1; S[i] > maxElem && i >= 0; --i) {
		sub[sub.size()-1] = S[i];
		generateSubs(subs, sub, S, len-1);
	}
}

vector <vector <int> > subsets (vector <int> &S) {
	vector <vector <int> > subs;
	vector <int> sub;
	subs.push_back(sub);
	if (S.empty()) {
		return subs;
	}
	sort(S.begin(), S.end());
	sub.resize(1);
	for (int i = 0; i < S.size(); ++i) {
		sub[0] = S[i];
		subs.push_back(sub);
	}
	sub.clear();
	for (int i = 2; i <= S.size(); ++i) {
		generateSubs(subs, sub, S, i);
	}
}

int main() {
	int arr[] = {9,0,3,5,7};
	vector <int> S(arr, arr+5);
	vector <vector <int> > subs = subsets(S);
	for (int i = 0; i < subs.size(); ++i) {
		for (int j = 0; j < subs[i].size(); ++j) {
			cout << subs[i][j] << " ";
		}puts("");
	}
	return 0;
}
