#include <cstdio>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(){}
	TreeNode(int v):val(v), left(NULL), right(NULL){}
};

/************ method 1 *****************
bool helper(TreeNode * root, const int &left, const int &right) {
	if (root == NULL) {
		return true;
	}
	if (!(root->val>left && root->val<right)) {
		return false;
	}
	
	if (root->left != NULL) {
		if (!helper(root->left, left, root->val)) {
			return false;
		}
	}
	if (root->right != NULL) {
		if (!helper(root->right, root->val, right)) {
			return false;
		}
	}
	reutrn true;
}

bool isValidBST(TreeNode * root){
	if (root == NULL) {
		return true;
	}
	
	int low = -0x7fffffff;
	int high = 0x7fffffff;
	
	return helper(root, low, high);
}
*/

/*********** method 2 ***********/
bool helper(TreeNode * root, int &pre, int &cur) {
	if (root == NULL) {
		return true;
	}
	if (!helper(root->left, pre, cur)) {
		return false;
	}
	pre = cur;
	cur = root->val;
	if (pre >= cur) return false;
	if (!helper(root->right, pre, cur)) {
		return false;
	}
	
	return true;
}

bool isValidBST(TreeNode * root) {
	if (root == NULL) {
		return true;
	}
	int pre = 0;
	int cur = -0x7fffffff;
	
	return helper(root, pre, cur);
}

int main() {
	return 0;
}
