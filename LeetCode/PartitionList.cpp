#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode * head, int x) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	
	ListNode * virHead = new ListNode(0);
	virHead->next = head;
	ListNode * pre = virHead;
	ListNode * cur = virHead->next;
	
	ListNode * virBig = new ListNode(0);
	ListNode * rCur = virBig;
	
	while (cur) {
		if (cur->val >= x) {
			rCur->next = cur;
			pre->next = cur->next;
			cur = cur->next;
			rCur = rCur->next;
			rCur->next = NULL;
		} else {
			pre = cur;
			cur = cur->next;
		}
	}
	
	pre->next = virBig->next;
	head = virHead->next;
	
	delete virHead;
	delete virBig;
	
	return head;
}

int main() {
	return 0;
}
