#include <cstdio>
#include <iostream>
using namespace std;

ListNode *deleteDuplicates(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode *pre = head;
	ListNode *cur = head->next;
	while (cur) {
		if (pre->val == cur->val) {
			ListNode *toDelete = cur;
			cur = cur->next;
			pre->next = cur;
			delete toDelete;
		} else {
			pre = cur;
			cur = cur->next;
		}
	}
	
	return head;
}

int main() {
	return 0;
}
