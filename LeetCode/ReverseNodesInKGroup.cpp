#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL){}
};

void printList(ListNode * head) {
	ListNode *cur = head;
	while (cur) {
		cout << (cur->val) << " ";
		cur = cur->next;
	}puts("");
}

ListNode *reverseKGroup(ListNode *head, int k) {
	if (head == NULL || k <= 1) {
		return head;
	}
	ListNode * vhead = new ListNode(-1);
	vhead->next = head;
	ListNode * preStart = vhead;
	ListNode * start = head;
	ListNode * end = head;
	
	int len = 0;
	ListNode * cur = head;
	while (cur) {
		++len;
		cur = cur->next;
	}
	if (len < k) {
		return head;
	}
	
	while (start) {
		len = k;
		while (len && end != NULL) {
			--len;
			end = end->next;
		}
		if (len > 0) {
			break;
		}
		ListNode * tmpEnd = end;
		ListNode * tmpPreStart = start;
		while (len < k) {
			++len;
			ListNode * tmp = start->next;
			start->next = tmpEnd;
			tmpEnd = start;
			start = tmp;
		}
		preStart->next = tmpEnd;
		preStart = tmpPreStart;
	}
	
	start = vhead->next;
	delete vhead;
	return start;
}

int main() {
	ListNode *head = new ListNode(1);
	ListNode *cur = head;
	cur->next = new ListNode(2);
	cur = cur->next;
	cur->next = new ListNode(3);
	printList(head);
	puts("================");
	printList(reverseKGroup(head, 2));
	return 0;
}
