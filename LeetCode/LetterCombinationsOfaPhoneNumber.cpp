#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

string num2char[10] = {" ", "~", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int toNumber(char ch) {
	return ch-'0';
}

void combinations(string digits, int level,  vector <string> &ret, string str) {
	if (level == digits.size()) {
		ret.push_back(str);
		return ;
	}
	
	int ind = toNumber(digits[level]);
	//cout << ind << endl;
	//system("pause");
	for (int i = 0; i < num2char[ind].size(); ++i) {
		str.append(1, num2char[ind][i]);
		combinations(digits, level+1, ret, str);
		str.pop_back();
	}
}

vector <string> letterCombinations(string digits) {
	vector <string> ret;
	string str = "";
	
	combinations(digits, 0, ret, str);
	
	return ret;
}

int main() {
	string digits("23");
	
	vector <string> comb = letterCombinations(digits);
	
	for (int i = 0; i < comb.size(); ++i) {
		cout << comb[i] << " ";
	}puts("");
	
	return 0;
}
