#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(){}
	ListNode(int x):val(x), next(NULL){}
};

ListNode * deleteDuplicates(ListNode * head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode * vhead = new ListNode(0);
	vhead->next = head;
	ListNode * pre = vhead;
	ListNode * cur = head;
	ListNode * next = head->next;
	while (cur) {
		next = cur->next;
		while (next != NULL && next->val == cur->val) {
			next = next->next;
		}
		if (next != cur->next) {
			pre->next = next;
			while (cur != next) {
				ListNode * toDelete = cur;
				cur = cur->next;
				delete toDelete;
			}
		} else {
			pre = cur;
			cur = next;
		}
	}
	head = vhead->next;
	delete vhead;
	return head;
}

int main() {
	return 0;
}
