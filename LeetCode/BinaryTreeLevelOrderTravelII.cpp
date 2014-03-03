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

void myLevelOrderBottom(TreeNode * root, int level, vector <vector<int> > &ret) {
	if (root == NULL) return;
	if (level > ret.size()) {
		vector <int> tmp;
		tmp.push_back(root->val);
		ret.push_back(tmp);
	} else {
		ret[level-1].push_back(root->val);
	}
	if (root->left) {
		myLevelOrderBottom(root->left, level+1, ret);
	}
	if (root->right) {
		myLevelOrderBottom(root->right, level+1, ret);
	}
}

vector <vector <int> > levelOrderBottom(TreeNode *root) {
	vector <vector<int> > ret;
	if (root == NULL) return ret;
	int level = 1;
	myLevelOrderBottom(root, level, ret);
	
	for (int i = 0; i < ret.size()/2; ++i) {
		ret[i].swap(ret[ret.size()-1-i]);
	}
	
	return ret;
}

int main() {
	return 0;
}
