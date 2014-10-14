#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector <int> preorderTraversal(TreeNode *root) {
	vector <int> preOrder;
	stack <TreeNode *> nodeStack;
	if (!root) {
		nodeStack.push(root);
	}
	
	while (!nodeStack.empty()) {
		TreeNode * tmp = nodeStack.top();
		nodeStack.pop();
		
		preOrder.push_back(tmp->val);
		if (tmp->right) {
			nodeStack.push(tmp->right);
		}
		if (tmp->left) {
			nodeStack.push(tmp->left);
		}
	}
	
	return preOrder;
}

int main() {
	return 0;
}
