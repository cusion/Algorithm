#include <cstdio>
#include <iostream>
#include <stack>
#include <set>
#include <cstdlib>
using namespace std;

const int N = 100003;
int ind[N];
int data[N];
int vol[N];
int ssize;
int lowbit(int x) {
	return x & (-x);
}

void update(int pos, int inc) {
	while (pos <= N) {
		ind[pos] += inc;
		pos += lowbit(pos);
	}
}

int sum(int pos) {
	int ret = 0;
	while (pos > 0) {
		ret += ind[pos];
		pos -= lowbit(pos);
	}
}

int binarySearch(int low, int high, int keyVal) {
	while(low <= high) {
		int mid = (low + high) / 2;
		int tmpSum = sum(mid);
		if (keyVal <= tmpSum) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

int main() {
	int cas;
	scanf("%d", &cas);
	memset(ind, 0, sizeof(ind));
	memset(vol, 0, sizeof(vol));
	char cmd[20];
	ssize = 0;
	while (cas--) {
		scanf("%s", cmd);
		if (cmd[1] == 'u') {
			int tmp;
			scanf("%d", &tmp);
			data[ssize] = tmp;
			vol[tmp]++;
			update(tmp, 1);
			ssize++;
		} else if (cmd[1] == 'o') {
			if (sssize == 0) {
				puts("Invalid");
			} else {
				update(data[--ssize], -1);
				printf("%d\n", data[ssize]);
			}
		} else {
			if (ssize == 0) {
				puts("Invalid");
			} else {
				int keyVal = (ssize & 0x01) ? (ssize + 1)/2 : (ssize/2);
				int ans = binarySearch(1, N, keyVal);
				printf("%d\n", ans);
			}
		}
	}
	
	return 0;
}

/************** multiset version *************
class Stack {
private:
	stack<int> all;
	multiset<int, greater<int> > lowers;
	multiset<int> uppers;
	
	void update() {
		if (lowers.size() > uppers.size() + 1) {
			uppers.insert(*lowers.begin());
			lowers.erase(lowers.begin());
		} else if (uppers.size() > lowers.size()) {
			lowers.insert(*uppers.begin());
			uppers.erase(uppers.begin());
		}
	}

public:
	Stack(){}
	void push(int e) {
		all.push(e);
		if (lowers.empty()) {
			lowers.insert(e);
		} else {
			if (e <= *(lowers.begin())) {
				lowers.insert(e);
			} else {
				uppers.insert(e);
			}
			update();
		}
	}
	
	bool pop(int &val) {
		if (all.empty()) {
			return false;
		}
		int tmp = all.top();
		all.pop();
		if (tmp <= *lowers.begin()) {
			lowers.erase(lowers.find(tmp));
		} else {
			uppers.erase(uppers.find(tmp));
		}
		update();
		val = tmp;
		return true;
	}
	
	bool peekMedian(int &val) {
		if (all.empty()) {
			return false;
		}
		val = *lowers.begin();
		return true;
	}
};

int main() {
	int n;
	cin >> n;
	char command[20];
	Stack st;
	for (int i = 0; i < n; ++i) {
		scanf("%s", command);
		int val;
		if (command[1] == 'o') {
			if (st.pop(val)) {
				printf("%d\n", val);
			} else {
				puts("Invalid");
			}
		} else if (command[1] == 'e') {
			if (st.peekMedian(val)) {
				printf("%d\n", val);
			} else {
				puts("Invalid");
			}
		} else {
			scanf("%d", &val);
			st.push(val);
		}
	}
	return 0;
}*/
