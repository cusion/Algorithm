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

vector <TreeNode *> generateTrees(int n) {
	vector <TreeNode *> atom;
	vector <vector< TreeNode *> > mole;
	vector <vector< vector<TreeNode *> > > comp;
	atom.push_back(NULL);
	if (n == 0) return atom;
	mole.push_back(atom);
	comp.push_back(mole);
	for (int len = 1; len <= n; ++len) {
		mole.clear();
		for (int start = 1; start <= n-len+1; ++start) {
			atom.clear();
			for (int k = 0; k < len; ++k) {
				int leftlen = k;
				int leftstart = leftlen == 0? 1:start;
				int rightlen = len-k-1;
				int rightstart = rightlen == 0? 1:start+k+1;
				for (int i = 0; i < comp[leftlen][leftstart-1].size(); ++i) {
					for (int j = 0; j < comp[rightlen][rightstart-1].size(); ++j) {
						TreeNode * root = new TreeNode(start+k);
						root->left = comp[leftlen][leftstart-1][i];
						root->right = comp[rightlen][rightstart-1][j];
						atom.push_back(root);
					}
				}
			}
			mole.push_back(atom);
		}
		comp.push_back(mole);
	}
	
	return comp[n][0];
}

void midTraversal(TreeNode * root) {
	if (root == NULL) return;
	midTraversal(root->left);
	cout << root->val << endl;
	midTraversal(root->right);
}

int main() {
	int n;
	while (1) {
		cin >> n;
		vector <TreeNode *> ret = generateTrees(n);
		cout << ret.size() << endl;
		for (int i = 0; i < ret.size(); ++i) {
			midTraversal(ret[i]);
			puts("===================");
		}
	}
	return 0;
}
