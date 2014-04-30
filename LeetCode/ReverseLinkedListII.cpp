#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x):val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
	if (head == NULL) return NULL;
	if (n <= m) return head;
	ListNode * vhead = new ListNode(-1);
	vhead->next = head;
	ListNode * pre = vhead;
	ListNode * cur = head;
	ListNode * start = NULL;
	ListNode * end = NULL;
	
	int idx = 1;
	while (idx <= n) {
		ListNode * tmp = cur->next;
		if (idx == m) {
			start = pre;
			end = cur;
		} else if (idx > m) {
			cur->next = pre;
		}
		pre = cur;
		cur = tmp;
		++idx;
	}
	
	start->next = pre;
	end->next = cur;
	
	cur = vhead->next;
	delete vhead;
	return cur;
}

int main() {
	return 0;
}
