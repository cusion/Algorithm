#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
	if (head == NULL) {
		return NULL;
	}
	
	ListNode *vHead = new ListNode(0);
	vHead->next = head;
	
	ListNode *pre = vHead;
	ListNode *cur = head;
	for (int i = 0; i < n; ++i) {
		cur = cur->next;
	}
	while (cur) {
		pre = pre->next;
		cur = cur->next;
	}
	ListNode *tmp = pre->next;
	pre->next = tmp->next;
	
	return vHead->next;
}

int main() {
	return 0;
}
