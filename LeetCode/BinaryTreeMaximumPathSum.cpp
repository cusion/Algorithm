#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void helper(TreeNode * root, int &maxSum, int &maxBranch) {
	if (root == NULL) {
		maxBranch = 0;
	}
	int leftMax = 0;
	int rightMax = 0;
	if (root->left) {
		helper(root->left, maxSum, leftMax);
	}
	if (root->right) {
		helper(root->right, maxSum, rightMax);
	}
	maxBranch = max(leftMax, rightMax)+root->val;
	maxBranch = max(maxBranch, 0);
	//cout << maxSum << " " << maxBranch << endl;
	maxSum = max(maxSum, leftMax+rightMax+root->val);
}

int maxPathSum(TreeNode * root) {
	if (root==NULL) {
		return 0;
	}
	int maxSum = root->val;
	int maxBranch = 0;
	helper(root, maxSum, maxBranch);
	return maxSum;
}

int main() {
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	cout << maxPathSum(root) << endl;
	return 0;
}
