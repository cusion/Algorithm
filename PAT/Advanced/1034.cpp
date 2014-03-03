#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int father(int x, int fa[]) {
	return x == fa[x] ? x : fa[x] = father(fa[x], fa);
}

void merge(int x, int y, int fa[]) {
	int fx = father(x, fa);
	int fy = father(y, fa);
	if (fx != fy) {
		fa[fy] = fx;
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	int fa[2*n];
	int sum[2*n];
	
	// initialization
	for (int i = 0; i < 2*n; ++i) {
		fa[i] = i;
		sum[i] = 0;
	}
	
	int cnt = 0;
	unordered_map <string, int> name2id;
	string namea, nameb;
	int time;
	for (int i = 0; i < n; ++i) {
		cin >> namea >> nameb >> time;
		int a,b;
		if (name2id.find(namea) == name2id.end()) {
			a = cnt;
			name2id[namea] = cnt++;
		} else {
			a = name2id[namea];
		}
		if (name2id.find(nameb) == name2id.end()) {
			b = cnt;
			name2id[nameb] = cnt++;
		} else {
			b = name2id[nameb];
		}
		sum[a] += time;
		sum[b] += time;
		merge(a, b, fa);
	}
	
	unordered_map <int, int> memberNum;
	unordered_map <int, int> timeSum;
	unordered_map <int, int> gangHead;
	for (int i = 0; i < cnt; ++i) {
		int fi = father(i, fa);
		if (memberNum.find(fi) == memberNum.end()) {
			memberNum[fi] = 0;
			timeSum[fi] = 0;
			gangHead[fi] = -1;
		}
		memberNum[fi]++;
		timeSum[fi] += sum[i];
		if (gangHead[fi] == -1 || sum[i] > sum[gangHead[fi]]) {
			gangHead[fi] = i;
		}
	}
	vector <string> realGang;
	for (auto it1 = memberNum.begin(), it2 = timeSum.begin(); it1 != memberNum.end(); ++it1, ++it2) {
		if (it1->second > 2 && it2->second > 2*k) {
			int head = gangHead[it1->first];
			for (auto it3 = name2id.begin(); it3 != name2id.end(); ++it3) {
				if (it3->second == head) {
					realGang.push_back(it3->first);
					break;
				}
			}
		}
	}
	if (!realGang.empty()) {
		sort(realGang.begin(), realGang.end());
	}
	cout << realGang.size() << endl;
	for (int i = 0; i < realGang.size(); ++i) {
		cout << realGang[i] << " " << memberNum[father(name2id[realGang[i]], fa)] << endl;
	}
	return 0;
}
