#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 100005

struct Node {
	int address;
	int key;
	int next;
	Node(){}
	Node(int a, int k, int n):address(a), key(k), next(n){}
};

Node nodes[MAX];
Node seg[MAX];
int reverse[MAX];

void printList(int head) {
	int cur = head;
	while (nodes[cur].next != -1) {
		printf("%05d %d %05d\n", cur, nodes[cur].key, nodes[cur].next);
		cur = nodes[cur].next;
	}
	printf("%05d %d -1\n", cur, nodes[cur].key);
}

int main() {
	int head, n, k;
	cin >> head >> n >> k;
	for (int i = 0; i < n; ++i) {
		int add, key, nextAdd;
		scanf("%d%d%d", &add, &key, &nextAdd);
		nodes[add].address = add;
		nodes[add].key = key;
		nodes[add].next = nextAdd;
	}
	
	int len = 0;
	int cur = head;
	while (cur != -1) {
		++len;
		cur = nodes[cur].next;
	}
	
	cur = head;
	
	if (cur == -1) {
		puts("-1");
	} else if (k <= 1 || k > len) {
		printList(cur);
	} else {
		int ind = 0;
		int revLen = 0;
		while (cur != -1) {
			//puts("test");
			ind = 0;
			while (cur != -1 && ind < k) {
				//cout << "test " << cur << endl;
				seg[ind++] = nodes[cur];
				cur = nodes[cur].next;
			}
			if (ind == k) {
				for (int i = ind - 1; i >= 0; --i) {
					reverse[revLen++] = seg[i].address;
				}
			} else {
				for (int i = 0; i < ind; ++i) {
					reverse[revLen++] = seg[i].address;
				}
			}
		}
		
		for (int i = 0; i < revLen-1; ++i) {
			printf("%05d %d %05d\n", reverse[i], nodes[reverse[i]].key, reverse[i+1]);
		}
		printf("%05d %d -1\n", reverse[revLen-1], nodes[reverse[revLen-1]].key);
	}
	
	return 0;
}
