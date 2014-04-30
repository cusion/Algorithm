#include <cstdio>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() {}
	TreeNode(int v):val(v),left(NULL),right(NULL) {}
};

void helper(TreeNode *root, int &minDepth, int depth) {
	if (root->left == NULL && root->right == NULL) {
		if (minDepth > depth) {
			minDepth = depth;
		}
		return;
	}
	if (root->left != NULL) {
		helper(root->left, minDepth, depth+1);
	}
	if (root->right != NULL) {
		helper(root->right, minDepth, depth+1);
	}
}

int minDepth(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	
	int minDepth = 0x7fffffff;
	helper(root, minDepth, 1);
	
	return minDepth;
}

int main() {
	
	return 0;
}
