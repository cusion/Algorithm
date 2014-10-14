#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

// It occurs to me that this problem could also be solved using union-find method, 
// that whenever we find a consecutive number, we should merge those number clusters. Have a try!!

/**************** This is another method that do not sort the whole array **************/
int longestConsecutive(vector <int> &num) {
	if (num.size() <= 1) {
		return num.size();
	}
	unordered_map <int, int> umap;
	unordered_map <int, int>::iterator itr;
	for (int i = 0; i < num.size(); ++i) {
		umap.insert(pair<int, int>(num[i], 1));
	}
	int maxLen = 1;
	for (itr = umap.begin(); itr != umap.end(); ++itr) {
		if (itr->second != 0) {
			int c = itr->first;
			int maxTmp = 1;
			int step = 1;
			unordered_map <int,int>::iterator itr1;
			while((itr1=umap.find(c-step))!=umap.end()) {
				itr1->second = 0;
				++step;
				++maxTmp;
			}
			step = 1;
			while((itr1=umap.find(c+step))!=umap.end()) {
				itr1->second = 0;
				++step;
				++maxTmp;
			}
			maxLen = maxLen > maxTmp ? maxLen : maxTmp;
		}
	}
	
	return maxLen;
}

/******* This is a nice solution from the web *************
int mergeCons(unordered_map<int, int> &umap, int left, int right) {
	int upper = right + umap[right] - 1;
	int lower = left - umap[left] + 1;
	int len = upper - lower + 1;
	umap[upper] = len;
	umap[lower] = len;
	return len;
	
}

int longestConsecutive(vector <int> &num) {
	if (num.size() <= 1) return num.size();
	unordered_map <int, int> umap;
	unordered_map <int, int>::iterator itr;
	int maxLen = 1;
	for (int i = 0; i < num.size(); ++i) {
		itr = umap.find(num[i]);
		if (itr!=umap.end()) {
			continue;
		} else {
			umap.insert(pair<int, int>(num[i], 1));
			if (umap.find(num[i]-1) != umap.end()) {
				maxLen = max(maxLen, mergeCons(umap, num[i]-1, num[i]));
			}
			if (umap.find(num[i]+1) != umap.end()) {
				maxLen = max(maxLen, mergeCons(umap, num[i], num[i]+1));
			}
		}
	}
	
	return maxLen;
}*/

/******************* This is a method that sort the original array using a O(kN) algorithm*************
int longestConsecutive(vector <int> &num) {
	if (num.size() <= 1) return num.size();
	vector <vector<int> > ppre(10, vector<int>());
	vector <vector<int> > pcur(10, vector<int>());
	vector <vector<int> > npre(10, vector<int>());
	vector <vector<int> > ncur(10, vector<int>());
	int maxPos = num[0], minNeg = num[0];
	for (int i = 1; i < num.size(); ++i) {
		if (maxPos < num[i]) {
			maxPos = num[i];
		} else if (minNeg > num[i]) {
			minNeg = num[i];
		}
	}
	//cout << minNeg << " " << maxPos << endl;
	vector <int> seq;
	if (minNeg < 0) {
		minNeg = -minNeg;
		for (int i = 0; i < num.size(); ++i) {
			if (num[i] < 0) {
				npre[(-num[i])%10].push_back(-num[i]);
			}
		}
		int flag = 1;
		while(minNeg/10) {
			minNeg /= 10;
			flag *= 10;
			for (int i = 0; i < npre.size(); ++i) {
				if (!npre[i].empty()) {
					for (int j = 0; j < npre[i].size(); ++j) {
						ncur[(npre[i][j]/flag)%10].push_back(npre[i][j]);
					}
				}
			}
			npre.swap(ncur);
			for (int i = 0; i < ncur.size(); ++i) {
				ncur[i].clear();
			}
		}
		for (int i = npre.size()-1; i >= 0; --i) {
			if (!npre[i].empty()) {
				for (int j = npre[i].size()-1; j >= 0; --j) {
					seq.push_back(-npre[i][j]);
				}
			}
		}
	}
	
	for (int i = 0; i < num.size(); ++i) {
		if (num[i] >= 0) {
			ppre[num[i]%10].push_back(num[i]);
		}
	}
	int flag = 1;
	while (maxPos/10) {
		//cout << "test " << maxPos << endl;
		maxPos /= 10;
		flag *= 10;
		for (int i = 0; i < ppre.size(); ++i) {
			if (!ppre[i].empty()) {
				for (int j = 0; j < ppre[i].size(); ++j) {
					pcur[(ppre[i][j]/flag)%10].push_back(ppre[i][j]);
				}
			}
		}
		ppre.swap(pcur);
		for (int i = 0; i < pcur.size(); ++i) {
			pcur[i].clear();
		}
	}
	
	for (int i = 0; i < ppre.size(); ++i) {
		for (int j = 0; j < ppre[i].size(); ++j) {
			seq.push_back(ppre[i][j]);
		}
	}
	
	for (int i = 0; i < seq.size(); ++i) {
		cout << seq[i] << " ";
	}puts("");
	int maxConsec = 1;
	int tmpConsec = 1;
	for (int i = 1; i < seq.size(); ++i) {
		if (seq[i] == seq[i-1]) {
			continue;
		}
		if (seq[i] == seq[i-1] + 1) {
			++tmpConsec;
		} else {
			maxConsec = tmpConsec > maxConsec ? tmpConsec : maxConsec;
			tmpConsec = 1;
		}
	}
	maxConsec = tmpConsec > maxConsec ? tmpConsec : maxConsec;
	
	return maxConsec;
}
*/

int main() {
	int arr[] = {1,2,0,1};
	vector <int> num(arr, arr+4);
	cout << longestConsecutive(num) << endl;
	return 0;
}
