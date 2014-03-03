#include <cstdio>
#include <iostream>
using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(a) ((a)>0?(a):-(a))

struct Node {
	int key;
	int height;     // NULL is -1
	Node *left;
	Node *right;
	Node(int k):key(k), height(0), left(NULL), right(NULL){}
};

class AVLTree {
private:
	Node * root;
public:
	AVLTree(Node * r):root(r){}
	AVLTree():root(NULL){}
	
	Node * getRoot() {
		return root;
	}
	
	void setRoot(Node * root) {
		this->root = root;
	}
	
	inline int getHeight(Node * p) {
		if (p == NULL) {
			return -1;
		} else {
			return p->height;
		}
	}
	
	void insert(int key) {
		_insert(key, root);
	}
	
	void _insert(int key, Node *&root) {
		if (root == NULL) {
			root = new Node(key);
		} else {
			if (key < root->key) {
				_insert(key, root->left);
				if (!isBalanced(root->left, root->right)) {
					if (key < root->left->key) {
						LLRotate(root);
					} else {
						LRRotate(root);
					}
				}
			} else {
				_insert(key, root->right);
				if (!isBalanced(root->left, root->right)) {
					if (key > root->right->key) {
						RRRotate(root);
					} else {
						RLRotate(root);
					}
				}
			}
		}
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	}
	
	bool isBalanced(Node * pl, Node * pr) {
		return abs(getHeight(pl) - getHeight(pr)) < 2;
	}
	
	void LLRotate(Node * &root) {
		Node *tmp = root->left;
		root->left = root->left->right;
		tmp->right = root;
		
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
		tmp->height = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;
		
		root = tmp;
	}
	
	void RRRotate(Node * &root) {
		Node * tmp = root->right;
		root->right = tmp->left;
		tmp->left = root;
		
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
		tmp->height = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;
		
		root = tmp;
	}
	
	void LRRotate(Node * &root) {
		RRRotate(root->left);
		LLRotate(root);
	}
	
	void RLRotate(Node * &root) {
		LLRotate(root->right);
		RRRotate(root);
	}
};

int main() {
	int n;
	AVLTree tree;
	cin >> n;
	while (n--) {
		int tmp;
		cin >> tmp;
		tree.insert(tmp);
	}
	
	cout << tree.getRoot()->key << endl;
	return 0;
}
