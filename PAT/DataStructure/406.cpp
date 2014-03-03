#include <cstdio>
#include <iostream>

using namespace std;

struct Node {
	Node * left;
	Node * right;
	int data;
};

bool compare1(int a, int b) {
	if (a > b) return true;
	return false;
}

bool compare2(int a, int b) {
	if (a <= b) return true;
	return false;
}

void postTraverse(Node * p, Node * root) {
	if (p == NULL) return;

	if ((p->left)) postTraverse(p->left, root);
	if ((p->right)) postTraverse(p->right, root);

	if (p==root) {
		printf("%d\n", root->data);
	} else {
		printf("%d ", p->data);
	}
}

bool isValid = true;

Node * buildTree(int * a, int len, bool (*compare)(int , int)) {

	if (len <= 0) return NULL;

	Node * root = new Node();
	root->left = NULL;
	root->right = NULL;
	root->data = a[0];
//	cout << a[0] << endl;
//	cout << "Press to continue..." << endl;getchar();getchar();cout << "go on ..." << endl;
	if (len == 1) return root;

	int leftlen = 0;
	for (int i = 1; i < len; ++i) {
		if (!compare(a[0], a[i])) {
			break;
		}
		leftlen++;
	}
	for (int i = leftlen+1; i < len; ++i) {
		if (compare(a[0],a[i])) {
			isValid = false;
			break;
		}
	}

	root->left = buildTree(&a[1], leftlen, compare);
	root->right = buildTree(&a[leftlen+1], len-leftlen-1, compare);

	if (isValid) return root;
	else return NULL;

}

void deleteTree(Node * root) {
	if (root == NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;

	return;
}

void check(int * a, int len, bool (*compare)(int , int)) {
	Node * root = NULL;
	if (root = buildTree(a, len, compare)) {
		puts("YES");
		postTraverse(root, root);
	} else {
		puts("NO");
	}

	deleteTree(root);

	return;
}

int main()
{
	int arr[1004];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	if (n <= 1) {
		puts("YES");
		cout << arr[0] << endl;
	} else {
		// Note that binary search tree would always be a Balanced Tree
		if (arr[0] > arr[1]) {
			check(arr, n, &compare1);
		} else {
			check(arr, n, &compare2);
		}
	}

	return 0;
}
