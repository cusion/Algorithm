#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * mergeTwoLists(ListNode* l1, ListNode *l2) {
	ListNode * small = NULL;
	ListNode * big = NULL;
	if (l1 == NULL) {
		return l2;
	} else if (l2 == NULL) {
		return l1;
	}
	
	big = l1->val > l2->val ? l1 : l2;
	small = l1->val <= l2->val ? l1 : l2;
	
	//cout << small->val << " " << big->val << endl;
	//system("pause");
	ListNode * cur = small;
	ListNode * pre = NULL;
	while (big)	{
		while (cur && cur->val <= big->val) {
			pre = cur;
			cur = cur->next;
		}
		pre->next = big;
		big = big->next;
		pre = pre->next;
		pre->next = cur;
	}
	
	return small;
}

int main() {
	ListNode * pHead = mergeTwoLists(new ListNode(2), new ListNode(1));
	ListNode * tmp = pHead;
	while (tmp) {
		cout << tmp->val <<endl;
		tmp = tmp->next;
	}
	return 0;
}
