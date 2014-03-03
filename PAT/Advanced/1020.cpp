#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void helper(vector <int> &postorder, int postLeft, int postRight, vector <int> &inorder, int inLeft, int inRight, vector<vector<int> > &levels, int level) {
	if (postLeft > postRight) {
		return ;
	}
	if (level >= levels.size()) {
		levels.push_back(vector <int>());
	}
	levels[level].push_back(postorder[postRight]);
	
	if (postLeft == postRight) return;
	
	int inPos;
	for (int i = inLeft; i <= inRight; ++i) {
		if (inorder[i] == postorder[postRight]) {
			inPos = i;
			break;
		}
	}
	inPos -= inLeft;
	helper(postorder, postLeft, postLeft+inPos-1, inorder, inLeft, inPos+inLeft-1, levels, level+1);	
	helper(postorder, postLeft+inPos, postRight-1, inorder, inPos+inLeft+1, inRight, levels, level+1);
}

void levelTraversal(vector <int> &postorder, vector <int> &inorder, vector<vector<int> > &levels) {
	if (postorder.empty()) {
		return;
	}
	helper(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, levels, 0);
}

int main() {
	int n;
	cin >> n;
	vector <int> postorder(n);
	vector <int> inorder(n);
	for (int i = 0; i < n; ++i) {
		cin >> postorder[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> inorder[i];
	}
	vector <vector<int> > levels;
	levelTraversal(postorder, inorder, levels);
	
	for (int i = 0; i < levels.size(); ++i) {
		for (int j = 0; j < levels[i].size(); ++j) {
			cout << levels[i][j];
			if (i!=levels.size()-1 || j != levels[i].size()-1) {
				cout << " ";
			}
		}
	}
	return 0;
}
