#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void mySumNumbers(TreeNode *root, int &sum, int med) {
	if (root->left == NULL && root->right == NULL) {
		sum += med*10 + root->val;
		return;
	}
	med = med*10 + root->val;
	if (root->left) {
		mySumNumbers(root->left, sum, med);
	}
	if (root->right) {
		mySumNumbers(root->right, sum, med);
	}
}

int sumNumbers(TreeNode *root) {
	int sum = 0;
	if (root == NULL) return sum;
	int med = 0;
	mySumNumbers(root, sum, med);
	
	return sum;
}

int main() {
	return 0;
}
