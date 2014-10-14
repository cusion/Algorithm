#include <cstdio>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void myFlatten(TreeNode *cur, TreeNode *arr[], int len) {
	if (cur==NULL) return;
	if (len == 0) {
		arr[1] = cur;
		len++;
	} else {
		arr[0] = arr[1];
		arr[1] = cur;
		len = 2;
	}
	if (len == 2) {
		arr[0]->left = cur;
	}
	myFlatten(cur->left, arr, len);
	myFlatten(cur->right, arr, len);
}

void flatten(TreeNode * root) {
	if (root == NULL) return;
	TreeNode * arr[2];
	int len = 0;
	myFlatten(root, arr, len);
	TreeNode * cur = root;
	while (cur->left) {
		TreeNode *next = cur->left;
		cur->right = cur->left;
		cur->left = NULL;
		cur = next;
	}
}

int main() {
	return 0;
}
