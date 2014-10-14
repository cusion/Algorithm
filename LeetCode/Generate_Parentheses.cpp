#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void mygenerate(vector <string> &ret, string &res, string choice, int left, int right) {
	if (choice.size() == 0) {
		ret.push_back(res);
		return ;
	}
	//cout << res << " " << left << " " << right << endl;
	//system("pause");
	for (int i = 0; i < choice.size(); ++i) {
		res.append(1, choice[i]);
		
		if (choice[i] == '(') {
			left--;
		} else {
			right--;
		}
		string newChoice = "";
		if (left>0) {
			newChoice.append(1, '(');
		}
		if (left < right) {
			newChoice.append(1, ')');
		}
		
		mygenerate(ret, res, newChoice, left, right);
		
		if (choice[i] == '(') {
			left++;
		} else {
			right++;
		}
		res.pop_back();
	}
}


vector <string> generateParenthesis(int n) {	
	vector <string> ret;
	
	if (n == 0) return ret;
	
	string res = "(";
	string choice;
	if (n > 1) {
		choice = "()";
	} else {
		choice = ")";
	}
	mygenerate(ret, res, choice, n-1, n);
	
	return ret;
}

int main() {
	int n;
	cin >> n;
	
	vector <string> p = generateParenthesis(n);
	
	for (int i = 0; i < p.size(); ++i) {
		cout << p[i] << endl;
	}
	
	return 0;
}
