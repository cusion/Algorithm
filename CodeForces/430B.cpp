#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int maxLen(vector<int> seq, int x) {
	if (seq.size() <= 1) {
		return 0;
	}
	if (seq.size() == 2) {
		if (seq[0] == seq[1] && seq[0] == x) {
			return 2;
		} else {
			return 0;
		}
	}
	
	vector<int> potentialPos;
	for (int i = 0; i < seq.size()-1; ++i) {
		if (seq[i] == seq[i+1] && seq[i] == x) {
			potentialPos.push_back(i);
		}
	}
	
	int result = 0;
	for (int i = 0; i < potentialPos.size(); ++i) {
		int start = potentialPos[i] - 1;
		int end = potentialPos[i] + 2;
		int tmpRet = 2;
		while (start >= 0 && end < seq.size()) {
			if (seq[start] != seq[end]) {
				break;
			} else {
				bool hasThree = false;
				if (start > 0 && seq[start-1] == seq[start]) {
					hasThree = true;
					while (start > 0 && seq[start-1] == seq[start]) {
						--start;
					}
				}
				if (end < seq.size()-1 && seq[end+1] == seq[end]) {
					hasThree = true;
					while (end < seq.size()-1 && seq[end+1] == seq[end]) {
						++end;
					}
				}
				
				if (hasThree) {
					tmpRet = end - start + 1;
					--start;
					++end;
				} else {
					break;
				}
			} // end if
		} // end while
		result = result < tmpRet ? tmpRet : result;
	} // end for
	
	return result;
}
int main() {
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> seq(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
	}
	cout << maxLen(seq, x) << endl;
	return 0;
}
