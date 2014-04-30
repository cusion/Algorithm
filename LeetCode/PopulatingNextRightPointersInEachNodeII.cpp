#include <cstdio>
#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x):val(x), left(NULL), right(NULL), next(NULL) {}
	TreeLinkNode(){}
};

/******* This is a wrong getNextLevel implementation **********
TreeLinkNode * getNextLevel(TreeLinkNode * root, int direct) {
	if (direct == 0) {
		if (root->right != NULL) {
			return root->right;
		} else {
			return root->left;
		}
	} else {
		if (root->left != NULL) {
			return root->left;
		} else {
			return root->right;
		}
	}
}*/

#ifdef RECURSIVE      // recursive version
void connect(TreeLinkNode * root) {
	if (root == NULL || (root->left==NULL && root->right==NULL)) {
		return ;
	}
	
	/*TreeLinkNode * left = root->left;
	TreeLinkNode * right = root->right;
	while (left!=NULL && right!=NULL) {
		left->next = right;
		left = getNextLevel(left, 0);
		right = getNextLevel(right, 1);
	}*/
	if (root->left != NULL) {
		if (root->right != NULL) {
			root->left->next = root->right;
		} else {
			TreeLinkNode * tmp = root->next;
			while (tmp) {
				if (tmp->left != NULL) {
					tmp = tmp->left;
					break;
				} else if (tmp->right != NULL) {
					tmp = tmp->right;
					break;
				}
				tmp = tmp->next;
			}
			root->left->next = tmp;
		}
	}
	if (root->right != NULL) {
		TreeLinkNode * tmp = root->next;
		while (tmp) {
			if (tmp->left != NULL) {
				tmp = tmp->left;
				break;
			} else if (tmp->right != NULL) {
				tmp = tmp->right;
				break;
			}
			tmp = tmp->next;
		}
		root->right->next = tmp;
	}
	
	connect(root->right);
	connect(root->left);
}
#endif

// iterative version
void connect(TreeLinkNode *root) {
	if (root == NULL || (root->left == NULL && root->right == NULL)) {
		return ;
	}
	TreeLinkNode * cur = root;
	TreeLinkNode * nextLevelStart = NULL;
	TreeLinkNode * lastNode = NULL;
	while (cur) {
		if (cur->left != NULL) {
			if (lastNode == NULL) {
				nextLevelStart = cur->left;
				lastNode = nextLevelStart;
			} else {
				lastNode->next = cur->left;
				lastNode = lastNode->next;
			}
		}
		
		if (cur->right != NULL) {
			if (lastNode == NULL) {
				nextLevelStart = cur->right;
				lastNode = nextLevelStart;
			} else {
				lastNode->next = cur->right;
				lastNode = lastNode->next;
			}
		}
		
		cur = cur->next;
		if (cur == NULL) {
			cur = nextLevelStart;
			nextLevelStart = NULL;
			lastNode = NULL;
		}
	}
}

int main(){
	return 0;
}
