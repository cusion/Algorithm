#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int cur;
	int key;
	//int next;
	Node() {}
	Node(int c, int k):cur(c),key(k){}
	friend bool operator <(Node a, Node b) {
		return a.key < b.key;
	}
};
const int N = 100003;
int nextAdd[N];
int ind[N];
int main() {
	int n, head;
	cin >> n >> head;
	Node nodes[n];
	int nextTmp;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &nodes[i].cur, &nodes[i].key, &nextTmp);
		nextAdd[nodes[i].cur] = nextTmp;
		ind[nodes[i].cur] = i;
	}
	vector<Node> list;
	while (head != -1) {
		list.push_back(nodes[ind[head]]);
		head = nextAdd[head];
	}
	if (list.empty()) {
		puts("0 -1");
	} else {
		sort(list.begin(), list.end());
		printf("%d %05d\n", list.size(), list[0].cur);
		for (int i = 0; i < list.size()-1; ++i) {
			printf("%05d %d %05d\n", list[i].cur, list[i].key, list[i+1].cur);
		}
		printf("%05d %d -1\n", list[list.size()-1].cur, list[list.size()-1].key);
	}
	return 0;
}
