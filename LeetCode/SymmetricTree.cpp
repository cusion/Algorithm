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
/**********************************************************
/* This is a wrong method, wheter we change the traversal order
/* or not, because when the left child or right child of a root
/* node is missing, there will always be non-mirror case which
/* meets those restrictions within this method.

void leftTraversal(TreeNode * root, vector <int> &aside) {
	if (root == NULL) return;
	aside.push_back(root->val);
	if (root->left) {
		leftTraversal(root->left, aside);
	}
	if (root->right) {
		leftTraversal(root->right, aside);
	}
}

void rightTraversal(TreeNode* root, vector <int> &aside) {
	if (root == NULL) {
		return ;
	}
	if (aside.size() == 0) {
		aside.push_back(root->val-1);
	}
	if (aside[aside.size()-1] == root->val) {
		aside.pop_back();
	} else {
		return;
	}
	if (root->right) {
		rightTraversal(root->right, aside);
	}
	if (root->left) {
		rightTraversal(root->left, aside);
	}
}

bool isSymmetric(TreeNode * root) {
	if (root == NULL) {
		return true;
	}
	vector <int> lside;
	leftTraversal(root->left, lside);
	for (int i = 0; i < lside.size()/2; ++i) {
		int tmp= lside[i];
		lside[i] = lside[lside.size()-1-i];
		lside[lside.size()-1-i] = tmp;
	}
	rightTraversal(root->right, lside);
	
	if (lside.size() == 0) {
		return true;
	} else {
		return false;
	}
}*/

/********************************* Method 1 ***********************
void deleteTree(TreeNode * root) {
	if (root == NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
	return;
}
void copyTree(TreeNode * root, TreeNode * &mroot) {
	if(root == NULL) return;
	mroot = new TreeNode(root->val);
	if (root->left) {
		copyTree(root->left, mroot->left);
	}
	if (root->right) {
		copyTree(root->right, mroot->right);
	}
}

void mirrorTree(TreeNode * root) {
	if (root == NULL) return;
	TreeNode * tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	if (root->left) {
		mirrorTree(root->left);
	}
	if (root->right) {
		mirrorTree(root->right);
	}
}

bool checkMirror(TreeNode * root, TreeNode *mroot) {
	if (root == NULL && mroot == NULL) {
		return true;
	} else if (root != NULL && mroot != NULL) {
		if (root->val != mroot->val) {
			return false;
		} else {
			return checkMirror(root->left, mroot->left) && checkMirror(root->right, mroot->right);
		}
	} else {
		return false;
	}
}

bool isSymmetric(TreeNode * root) {
	if (root == NULL) return true;
	TreeNode * mroot = NULL;
	copyTree(root, mroot);
	mirrorTree(mroot);
	
	if (checkMirror(root, mroot)) {
		deleteTree(mroot);
		return true;
	} else {
		deleteTree(mroot);
		return false;
	}
}*/

/*********** Method 2 **************/
bool checkMirror(TreeNode *root, TreeNode*mroot) {
	if (root == NULL && mroot == NULL) {
		return true;
	} else if (root != NULL && mroot != NULL) {
		if (root->val != mroot->val) {
			return false;
		} else {
			return checkMirror(root->left, mroot->right) && checkMirror(root->right, mroot->left);
		}
	} else {
		return false;
	}
}

bool isSymmetric(TreeNode * root) {
	if (root == NULL) return true;
	TreeNode * mroot = root;
	return checkMirror(root, mroot);
}

int main() {
	return 0;
}
