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

struct StateNode {
	TreeNode * pNode;
	int status;    // 0 for visiting child, 1 for visiting itself
	StateNode (TreeNode * p, int stat) : pNode(p), status(stat){}
};

vector<int> inorderTraversal(TreeNode *root) {
	stack <StateNode> nodeStack;
	vector <int> ret;
	if (root == NULL) return ret;
	
	StateNode tmpState(root, 0);
	nodeStack.push(tmpState);
	
	while (!nodeStack.empty()) {
		tmpState = nodeStack.top();
		nodeStack.pop();
		if (tmpState.status == 0) {
			if (tmpState.pNode->right) {
				StateNode tmpRight(tmpState.pNode->right, 0);
				nodeStack.push(tmpRight);
			}
			tmpState.status = 1;
			nodeStack.push(tmpState);
			if (tmpState.pNode->left) {
				StateNode tmpLeft(tmpState.pNode->left, 0);
				nodeStack.push(tmpLeft);
			}
		} else {
			int val = tmpState.pNode->val;
			ret.push_back(val);
		}
	}
	
	return ret;
}

int main() {
	return 0;
}
