#include <cstdio>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode * head) {
	ListNode *cur = head;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}puts("");
	puts("======================");
}

ListNode *merge(ListNode *left, ListNode *right) {
	if (left == NULL) {
		return right;
	}
	if (right == NULL) {
		return left;
	}
	ListNode *mergeList = new ListNode(0);
	ListNode *cur = mergeList;
	while (left && right) {
		if (left->val < right->val) {
			cur->next = left;
			left = left->next;
			cur = cur->next;
		} else if (left->val > right->val) {
			cur->next = right;
			right = right->next;
			cur = cur->next;
		} else {
			cur->next = left;
			cur = cur->next;
			left = left->next;
			cur->next = right;
			cur = cur->next;
			right = right->next;
		}
	}
	if (left) {
		cur->next = left;
	} else {
		cur->next = right;
	}
	cur = mergeList->next;
	delete mergeList;
	return cur;
}

ListNode *sortList(ListNode *head) {
	if (head == NULL) {
		return NULL;
	}
	int len = 0;
	ListNode * cur = head;
	while (cur) {
		++len;
		cur = cur->next;
	}
	if (len == 1) {
		return head;
	}
	int cnt = 1;
	cur = head;
	while(cnt < len/2) {
		cur = cur->next;
		++cnt;
	}
	ListNode *right = sortList(cur->next);
	//cout << "test right "<< endl;
	//printList(right);
	cur->next = NULL;
	ListNode *left = sortList(head);
	//cout << "test left" << endl;
	//printList(left);
	
	return merge(left, right);
}

int main() {
	ListNode *vhead = new ListNode(0);
	int n;
	cin >> n;
	int tmp;
	ListNode *cur = vhead;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		cur->next = new ListNode(tmp);
		cur = cur->next;
	}
	//printList(vhead->next);
	cur = sortList(vhead->next);
	printList(cur);
	
	return 0;
}
