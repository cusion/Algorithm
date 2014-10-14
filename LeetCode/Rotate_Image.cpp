#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void rotate(vector <vector <int> > &matrix) {
	vector <vector <int> > matRot;
	for (int i = 0; i < matrix[0].size(); ++i) {
		vector <int> tmp;
		for (int j = matrix.size()-1; j >= 0; --j) {
			tmp.push_back(matrix[j][i]);
		}
		matRot.push_back(tmp);
	}
	matrix = matRot;
}

void printMat (vector < vector <int> > matrix) {
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			cout << matrix[i][j] << " ";
		}
		puts("");
	}
}

int main() {
	int mat[] = {1,2,3,4};
	vector <int> row(mat, mat + 4);
	vector <vector <int> > matrix;
	matrix.push_back(row);
	matrix.push_back(row);
	printMat(matrix);
	rotate(matrix);
	printMat(matrix);
	rotate(matrix);
	printMat(matrix);
	return 0;
}
