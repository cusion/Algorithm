#include <cstdio>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q) {
	if (p == NULL || q == NULL) {
		return p == q;
	}
	if (p->val != q->val) {
		return false;
	}
	
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
	return 0;
}
