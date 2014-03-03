#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void myMatrixGenerator(vector <vector <int> > &mat, int r, int c, int rCur, int cCur, int start) {
	if (r == 0 && c == 0) return;
	if (r == 1) {
		for (int i = 0; i < c; ++i) {
			mat[rCur][cCur+i] = start++;
		}
		return ;
	}
	
	if (c == 1) {
		for (int i = 0; i < r; ++i) {
			mat[rCur+i][cCur] = start++;
		}
		return ;
	}
	
	// generate top row
	for (int i = 0; i < c-1; ++i) {
		mat[rCur][cCur+i] = start++;
	}
	
	// generate right col
	for (int i = 0; i < r-1; ++i) {
		mat[rCur+i][cCur+c-1] = start++;
	}
	
	// generate buttom row
	for (int i = 0; i < c-1; ++i) {
		mat[rCur+r-1][cCur+c-1-i] = start++;
	}
	
	//generate left col
	for (int i = 0; i < r-1; ++i) {
		mat[rCur+r-1-i][cCur] = start++;
	}
	
	myMatrixGenerator(mat, r-2, c-2, rCur+1, cCur+1, start);
}

vector <vector<int> > generateMatrix(int n) {
	vector <vector<int> > ret(n, vector<int>(n));
	if (n == 0) return ret;
	
	myMatrixGenerator(ret, n, n, 0, 0, 1);
	
	return ret;
}

int main() {
	int n;
	cin >> n;
	vector <vector <int> > ret = generateMatrix(n);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}
		puts("");
	}
	
	return 0;
}
