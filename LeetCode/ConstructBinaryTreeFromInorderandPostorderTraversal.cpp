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

TreeNode * myBuildTree(vector <int> &inorder, vector <int> &postorder, int postLeft, int postRight, int inLeft, int inRight) {
	if (postLeft == postRight) {
		return new TreeNode(postorder[postRight]);
	} else if (postLeft > postRight) return NULL;
	
	TreeNode * root = new TreeNode(postorder[postRight]);
	
	int inOrderPos = 0;
	for (int i = inLeft; i <= inRight; ++i) {
		if (inorder[i] == postorder[postRight]) {
			inOrderPos = i;
			break;
		}
	}
	
	int right = postRight-1;
	int left = right-(inRight - inOrderPos)+1;
	
	/**********************************************************
	int left = preLeft+1;
	int right = left;
	// This is a dummy method to determine the boundary of the left part of the preOrder
	bool isFound = false;
	for (; right <= preRight; ++right) {
		isFound = false;
		for (int j = inLeft; j < inOrderPos; ++j) {
			if (inorder[j] == preorder[right]) {
				isFound = true;
				break;
			}
		}
		if (!isFound) {
			--right;
			break;
		}
	}
	
	***********************************************************/
	root->left = myBuildTree(inorder, postorder, postLeft, left-1, inLeft, inOrderPos-1);
	root->right = myBuildTree(inorder, postorder, left, right, inOrderPos+1, inRight);
	
	return root;
}

TreeNode * buildTree(vector <int> &inorder, vector <int> &postorder) {
	if (postorder.empty()) return NULL;
	
	TreeNode * root = myBuildTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
	
	return root;
}

void inTraversal(TreeNode * root) {
	if (root == NULL) {
		return;
	}
	inTraversal(root->left);
	cout << root->val << " ";
	inTraversal(root->right);
	
	return ;
}

int main() {
	
	int pre[] = {5, 3, 1, 4, 9, 6, 7, 10};
	vector <int> preorder(pre, pre+8);
	
	int in[] = {1, 3, 4, 5, 6, 7, 9, 10};
	vector <int> inorder(in, in+8);
	
	inTraversal(buildTree(preorder, inorder));
	
	return 0;
}
