#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(){}
	TreeNode(int v):val(v), left(NULL), right(NULL){}
};

void helper(TreeNode * root, int sum, vector<vector<int> > &ret, vector<int> &tmpPath) {
	if (root->left==NULL && root->right==NULL) {
		if (sum == 0) {
			ret.push_back(tmpPath);
		}
		return;
	}
	
	if (root->left != NULL) {
		tmpPath.push_back(root->left->val);
		helper(root->left, sum-root->left->val, ret, tmpPath);
		tmpPath.pop_back();
	}
	
	if (root->right != NULL) {
		tmpPath.push_back(root->right->val);
		helper(root->right, sum-root->right->val, ret, tmpPath);
		tmpPath.pop_back();
	}
}

vector<vector<int> > pathSum(TreeNode * root, int sum) {
	vector<vector<int> > ret;
	if (root == NULL) {
		return ret;
	}
	
	vector<int> tmpPath;
	tmpPath.push_back(root->val);
	helper(root, sum-root->val, ret, tmpPath);
	
	return ret;
}

int main() {
	return 0;
}
