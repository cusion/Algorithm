#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

/***************************** Method 1 ************************
void cbstTraversal1(int arr[], int start, int end, int curLevel, vector<vector<int> > &ind) {
	int len = end - start + 1;
	//cout << "start " << start << " end " << end << endl;
	if (len == 3) {
		ind[curLevel].push_back(arr[(start+end)/2]);
		ind[curLevel+1].push_back(arr[start]);
		ind[curLevel+1].push_back(arr[end]);
		return;
	} else if (len == 2) {
		ind[curLevel].push_back(arr[end]);
		ind[curLevel+1].push_back(arr[start]);
		return;
	} else if (len == 1) {
		ind[curLevel].push_back(arr[start]);
		return;
	}
	
	int level = floor(log2(len+1));
	int rem = len - (1<<level) + 1;
	int leftrem = rem, rightrem = 0;
	if (rem > (1<<(level-1))) {
		leftrem = 1<<(level-1);
		rightrem = rem - leftrem;
	}
	int left = (1<<(level-1)) - 1 + leftrem;
	ind[curLevel].push_back(arr[left]);
	cbstTraversal1(arr, 0, left-1, curLevel+1, ind);
	cbstTraversal1(arr, left+1, end, curLevel+1, ind);
}*/

void cbstTraversal(int arr[], int bfsind, int level, int &ind, int len, vector<vector<int> > &bfs) {
	if (bfsind >= len) {
		return;
	}
	if (bfsind*2+1 < len) {
		cbstTraversal(arr, bfsind*2+1, level+1, ind, len, bfs);
	}
	bfs[level].push_back(arr[ind]);
	++ind;
	if (bfsind*2+2 < len) {
		cbstTraversal(arr, bfsind*2+2, level+1, ind, len, bfs);
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	int level = ceil(log2(n+1));
	//vector <vector <int> > ind(level, vector<int>());
	vector <vector <int> > bfs(level, vector<int>());
	//cbstTraversal1(arr, 0, n-1, 0, ind);
	int indx = 0;
	cbstTraversal(arr, 0, 0, indx, n, bfs);
	
	/*for (int i = 0; i < ind.size(); ++i) {
		for (int j = 0; j < ind[i].size(); ++j) {
			if (i == 0 && j == 0) cout << arr[ind[i][j]];
			else {
				printf(" %d", arr[ind[i][j]]);
			}
		}
	}puts("");*/
	for (int i = 0; i < bfs.size(); ++i) {
		for (int j = 0; j < bfs[i].size(); ++j) {
			if (i == 0 && j == 0) cout << bfs[i][j];
			else {
				printf(" %d", bfs[i][j]);
			}
		}
	}
	return 0;
}
