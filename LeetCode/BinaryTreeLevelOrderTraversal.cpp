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

void helper(TreeNode * root, int level, vector<vector<int> > &ret) {
	if (root == NULL) {
		return;
	}
	if (level >= ret.size()) {
		ret.push_back(vector<int>());
	}
	ret[level].push_back(root->val);
	if (root->left) {
		helper(root->left, level+1, ret);
	}
	if (root->right) {
		helper(root->right, level+1, ret);
	}
}

vector<vector<int> > levelOrder(TreeNode *root) {
	vector <vector<int> > ret;
	if (root == NULL) {
		return ret;
	}
	helper(root, 0, ret);
	
	return ret;
}

int main() {
	return 0;
}
