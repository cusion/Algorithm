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

int maxDepth(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	int lDepth = maxDepth(root->left);
	int rDepth = maxDepth(root->right);
	
	return max(lDepth, rDepth)+1;
}

int main() {
	return 0;
}
