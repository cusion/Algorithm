#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
/**************************
This is a misunderstanding of what the problem is.
string convert(string s, int nRows) {
	string ret = "";
	if (s.empty()) return ret;
	
	// int nCols = s.length()/(n + n/2) * 2;
	// nCols += ceil((s.length()%(n+n/2))/n);
	
	int nCols = 0;
	int len = s.length();
	while (len>0) {
		len -= nRows;
		++nCols;
		if (len <= 0) {
			break;
		}
		len -= nRows/2;
		++nCols;
		if (len <= 0) {
			break;
		}
	}
	
	int indx = 0;
	int interval = nRows + nRows/2;
	for (int i = 0; i < nRows; ++i) {
		for (int j = 0; j < nCols; ++j) {
			if (i%2) {
				if (j%2) {
					indx = i + j/2*interval + nRows - 1;
				} else {
					indx = i + j/2*interval;
				}
			} else {
				if (j%2) {
					continue;
				} else {
					indx = i + j/2*interval;
				}
			}
			if (indx < s.length()) {
				ret.append(1, s[indx]);
			}
		}
	}
	
	return ret;
}*/

/***********************************/
/*
/* write some cases down, then you will know the implication behind this method
/*
*/
string convert(string s, int nRows) {
	string ret = "";
	if (s.empty()) return ret;
	if (nRows == 1) return s;
	int maxStep = (nRows-1)*2;
	int indx = 0;
	for (int i = 0; i < nRows; ++i) {
		if (i == 0 || i == nRows-1) {
			indx = i;
			while (indx < s.length()) {
				ret.append(1, s[indx]);
				indx += maxStep;
			}
		} else {
			indx = i;
			bool odd = true;
			while (indx < s.length()) {
				ret.append(1, s[indx]);
				indx += odd ? (maxStep-i*2) : (i*2);
				odd = !odd;
			}
		}
	}
	
	return ret;
}

int main() {
	string s = "PAYPALISHIRING";
	cout << convert(s, 3);
	return 0;
}
