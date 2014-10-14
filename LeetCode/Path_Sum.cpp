#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
	}
};

bool hasPathSum(TreeNode * root, int sum) {
	if (root == NULL) return false;
	
	if (root->val == sum && root->left == NULL && root->right == NULL) return true;
	
	if (root->left && /*sum > root->val &&  we do not assume all input are positive*/hasPathSum(root->left, sum-root->val)) {
		return true;
	} else if (root->right && /*sum > root->val && */hasPathSum(root->right, sum-root->val)) {
		return true;
	} else return false;
}

int main() {
	return 0;
}
