#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode * vhead = new ListNode(0);
	vhead->next = head;
	ListNode * pre = vhead;
	ListNode * cur = head->next;
	head->next = NULL;
	while (cur) {
		pre = vhead;
		while (pre->next && pre->next->val < cur->val) {
			pre = pre->next;
		}
		ListNode *nextTmp = cur->next;
		cur->next = pre->next;
		pre->next = cur;
		cur = nextTmp;		
	}
	
	return vhead->next;
}

int main() {
	return 0;
}
