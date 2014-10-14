#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	
	ListNode * vhead = new ListNode(-1);
	
	ListNode *result = vhead;
	ListNode *cur1 = l1;
	ListNode *cur2 = l2;
	
	int increment = 0;
	while ((l1 != NULL) && (l2 != NULL)) {
		int res = l1->val + l2->val + increment;
		result->next = new ListNode(res%10);
		increment = res/10;
		
		result = result->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1 != NULL) {
		int res = l1->val + increment;
		result->next = new ListNode(res%10);
		increment = res/10;
		
		result = result->next;
		l1 = l1->next;
	}
	while (l2 != NULL) {
		int res = l2->val + increment;
		result->next = new ListNode(res%10);
		increment = res/10;
		
		l2 = l2->next;
		result = result->next;
	}
	
	if (increment > 0) {
		result->next = new ListNode(1);
	}
	
	result = vhead->next;
	delete vhead;
	
	return result;
}

int main () {
	return 0;
}
