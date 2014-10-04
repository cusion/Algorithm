#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * helper(vector<int> &num, int left, int right) {
	if (left > right) {
		return NULL;
	}
	if (left == right) {
		return new TreeNode(num[left]);
	}
	int mid = (left + right) >> 1;
	TreeNode * root = new TreeNode(num[mid]);
	root->left = helper(num, left, mid-1);
	root->right = helper(num, mid+1, right);
	
	return root;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
	TreeNode * root = NULL;
	if (num.empty()) {
		return root;
	}
	root = helper(num, 0, num.size()-1);
	
	return root;
}

int main() {
	return 0;
}
