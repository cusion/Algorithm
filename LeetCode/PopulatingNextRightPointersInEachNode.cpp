#include <cstdio>
#include <iostream>
using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**************** TLE Version **************************
void addLinkHelper(TreeLinkNode *root, int level) {
	if(root->left == NULL || root->right == NULL) {
		return ;
	}
	TreeLinkNode *left = root->left;
	for (int i = 0; i < level; ++i) {
		left = left->right;
		if (left == NULL) return;
	}
	TreeLinkNode *right = root->right;
	for (int i = 0; i < level; ++i) {
		right = right->left;
		if (right == NULL) return;
	}
	cout <<"enter root " << root->val << endl;
	left->next = right;
	if (root->left) {
		addLinkHelper(root->left, level);
	}
	if (root->right) {
		addLinkHelper(root->right, level);
	}
}

void connect(TreeLinkNode *root) {
	if (root == NULL) {
		return ;
	}
	TreeLinkNode * levelDetector = root->left;
	int level = 0;
	while(levelDetector) {
		cout << level << endl;
		addLinkHelper(root, level);
		levelDetector = levelDetector->left;
		++level;
	}
	
	return ;
}*/

void printList(TreeLinkNode *root) {
	TreeLinkNode * cur = root;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	puts("");
}

void addLinkHelper(TreeLinkNode * root, int level) {
	if (root->left==NULL || root->right == NULL) {
		return;
	}
	TreeLinkNode * left = root->left;
	TreeLinkNode *right = root->right;
	left->next = right;
	for (int i = 0; i < level; ++i) {
		left = left->right;
		right = right->left;
		left->next = right;
	}
	
	if (root->left) {
		addLinkHelper(root->left, level-1);
	}
	if (root->right) {
		addLinkHelper(root->right, level-1);
	}
}

void connect(TreeLinkNode * root) {
	if (root == NULL || root->left == NULL) {
		return ;
	}
	int level = 0;
	TreeLinkNode * levelDetector = root->left;
	while (levelDetector->left) {
		++level;
		levelDetector = levelDetector->left;
	}
	addLinkHelper(root, level);
}

int main() {
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);
	root->left->left->left = new TreeLinkNode(8);
	root->left->left->right = new TreeLinkNode(9);
	root->left->right->left = new TreeLinkNode(10);
	root->left->right->right = new TreeLinkNode(11);
	root->right->left->left = new TreeLinkNode(12);
	root->right->left->right = new TreeLinkNode(13);
	root->right->right->left = new TreeLinkNode(14);
	root->right->right->right = new TreeLinkNode(15);
	connect(root);
	TreeLinkNode *level = root;
	while (level) {
		printList(level);
		level = level->left;
	}
	return 0;
}
