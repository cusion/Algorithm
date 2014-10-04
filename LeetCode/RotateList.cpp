#include <cstdio>
#include <iostream>
using namespace std;

ListNode * rotateRight(ListNode * head, int k) {
	if (head == NULL) {
		return head;
	}
	ListNode *cur = head;
	ListNode *tail = cur;
	int len = 0;
	while (cur) {
		tail = cur;
		cur = cur->next;
		++len;
	}
	
	k %= len;
	
	if (k == 0) {
		return head;
	}
	
	int cnt = 0;
	cur = head;
	ListNode * pre = cur;
	while (cnt+k < len) {
		++cnt;
		pre = cur;
		cur = cur->next;
	}
	pre->next = NULL;
	tail->next = head;
	
	return cur;
}

int main() {
	return 0;
}
