#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode * vhead = new ListNode(0);
	ListNode * pre = vhead;
	ListNode * cur = head;
	ListNode * nxt = cur->next;
	
	while (1) {
		pre->next = nxt;
		cur->next =nxt->next;
		nxt->next = cur;
		
		pre = cur;
		cur = cur->next;
		if (cur && cur->next) {
			nxt = cur->next;
		} else {
			break;
		}
	}
	
	ListNode * ret = vhead->next;
	delete vhead;
	return ret;
}

int main() {
	return 0;
}
