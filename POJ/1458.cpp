#include <cstdio>
#include <iostream>
#include <string>

#define Max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int LCS(string str1, string str2);
int LCSS(string str1, string str2);

int main() {
	string str1, str2;
	while (cin>>str1>>str2) {
		cout<<LCS(str1, str2)<<endl;
	}
	return 0;
}

int LCS(string str1, string str2){
	int **arr = new int * [str1.size()];
	for (int i = 0; i < str1.size(); ++i) {
		arr[i] = new int[str2.size()];
	}
	arr[0][0] = str1[0] == str2[0] ? 1 : 0;
	for (int i = 1; i < str1.size(); ++i) {
		if (str1[i] == str2[0]) {
			arr[i][0] = 1;
		} else {
			arr[i][0] = arr[i-1][0];
		}
	}
	for (int i = 1; i < str2.size(); ++i) {
		if (str2[i] == str1[0]) {
			arr[0][i] = 1;
		} else {
			arr[0][i] = arr[0][i-1];
		}
	}

	for (int i = 1; i < str1.size(); ++i) {
		for (int j = 1; j < str2.size(); ++j) {
			if (str1[i] == str2[j]) {
				arr[i][j] = arr[i-1][j-1] + 1;
			} else {
				arr[i][j] = Max(arr[i-1][j], arr[i][j-1]);
			}
		}
	}
	int ret = arr[str1.size()-1][str2.size()-1];
	delete[] arr;

	return ret;
}

int LCSS(string str1, string str2){
	int **arr = new int * [str1.size()];
	for (int i = 0; i < str1.size(); ++i) {
		arr[i] = new int[str2.size()];
	}
	arr[0][0] = str1[0] == str2[0] ? 1 : 0;
	for (int i = 1; i < str1.size(); ++i) {
		if (str1[i] == str2[0]) {
			arr[i][0] = 1;
		} else {
			arr[i][0] = 0;
		}
	}
	for (int i = 1; i < str2.size(); ++i) {
		if (str2[i] == str1[0]) {
			arr[0][i] = 1;
		} else {
			arr[0][i] = 0;
		}
	}

	int ret = 0;
	for (int i = 1; i < str1.size(); ++i) {
		for (int j = 1; j < str2.size(); ++j) {
			if (str1[i] == str2[j]) {
				arr[i][j] = arr[i-1][j-1] + 1;
				ret = ret >= arr[i][j] ? ret : arr[i][j];
			} else {
				arr[i][j] = 0;
			}
		}
	}

	delete[] arr;

	return ret;
}
