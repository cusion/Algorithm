#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeight(TreeNode * pNode) {
	if (pNode == NULL) {
		return 0;
	}
	
	int lh = getHeight(pNode->left);
	int rh = getHeight(pNode->right);
	
	return max(lh, rh) + 1;
}

bool isBalanced (TreeNode * root) {
	if (root == NULL) return true;
	
	int lh = getHeight(root->left);
	int rh = getHeight(root->right);
	
	if (lh - rh > 1 || lh - rh < -1) {
		return false;
	}
	
	if (isBalanced(root->left) && isBalanced(root->right)) {
		return true;
	}
	
	return false;
}

int main(){
	return 0;
}
