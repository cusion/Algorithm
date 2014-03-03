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

void findSwapped(vector <TreeNode*> &swapped, TreeNode * cur, TreeNode *arr[], int &len) {
	if (cur == NULL) return;
	if (cur->left) {
		findSwapped(swapped, cur->left, arr, len);
	}
	if (len == 0) {
		arr[1] = cur;
		len=1;
	} else {
		arr[0] = arr[1];
		arr[1] = cur;
		len = 2;
	}
	if (len == 2) {
		if (arr[0]->val > arr[1]->val) {
			swapped.push_back(arr[0]);
			swapped.push_back(arr[1]);
		}
	}
	if (cur->right) {
		findSwapped(swapped, cur->right, arr, len);
	}
}

void recoverTree(TreeNode * root) {
	if (root == NULL) return;
	
	vector <TreeNode *> swappedNode;
	TreeNode * pre = NULL;
	TreeNode* arr[2];
	int len = 0;
	findSwapped(swappedNode, root, arr, len);
	
	if (swappedNode.size()>2){
		int tmp = swappedNode[0]->val;
		swappedNode[0]->val = swappedNode[3]->val;
		swappedNode[3]->val = tmp;
	} else if (!swappedNode.empty()) {
		int tmp = swappedNode[0]->val;
		swappedNode[0]->val = swappedNode[1]->val;
		swappedNode[1]->val = tmp;
	}
	
	return;
}

int main() {
	return 0;
}
