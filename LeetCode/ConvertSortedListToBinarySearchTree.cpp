#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(){}
	ListNode(int v):val(v), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(){}
	TreeNode(int v):val(v), left(NULL), right(NULL){}
};

TreeNode * helper(ListNode * start, ListNode * end) {
	if (start == end) {
		return NULL;
	}
	
	ListNode * fast = start;
	ListNode * slow = start;
	while (fast != end) {
		fast = fast->next;
		if (fast == end) break;
		fast = fast->next;
		if (fast == end) break;
		slow = slow->next;
	}
	TreeNode * root = new TreeNode(slow->val);
	root->left = helper(start, slow);
	root->right = helper(slow->next, end);
}

TreeNode * sortedListToBST(ListNode *head) {
	if (head == NULL) return NULL;
	
	return helper(head, NULL);
}

int main() {
	return 0;
}
