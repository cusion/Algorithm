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

void helper(TreeNode * root, int level, vector <vector <int> > &ret) {
	if (root == NULL) {
		return;
	}
	if (level >= ret.size()) {
		ret.push_back(vector <int>());
	}
	ret[level].push_back(root->val);
	if (root->left) {
		helper(root->left, level+1, ret);
	}
	if (root->right) {
		helper(root->right, level+1, ret);
	}
}


vector <vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector <vector <int> > ret;
	if (root == NULL) {
		return ret;
	}
	helper(root, 0, ret);
	
	for (int i = 1; i < ret.size(); i+=2) {
		for (int j = 0; j < ret[i].size()/2; ++j) {
			int tmp = ret[i][j];
			ret[i][j] = ret[i][ret[i].size()-1-j];
			ret[i][ret[i].size()-1-j] = tmp;
		}
	}
	
	return ret;
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	zigzagLevelOrder(root);
	return 0;
}
