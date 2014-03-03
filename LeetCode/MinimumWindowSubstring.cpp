#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string S, string T) {
	if (S.empty() || T.empty() || S.length() < T.length()) {
		return "";
	}
	unordered_map<char, int> target;
	unordered_map<char, int>::iterator itr;
	unordered_map<char, int> cur;
	for (int i = 0; i < T.length(); ++i) {
		if (target.find(T[i]) == target.end()) {
			target.insert(pair<char,int>(T[i], 1));
			cur.insert(pair<char,int>(T[i], 0));
		} else {
			target[T[i]]++;
		}
	}
	int left = 0, right = 0;
	int minLeft = 0, minRight = S.length();
	int cnt = 0;
	S.push_back('$');
	bool isFound = false;
	while (right < S.length()) {
		if (cnt < T.length()) {
			itr = cur.find(S[right]);
			if (itr != cur.end()) {
				//cout << right << " " << S[right] << " " << cnt << endl;
				if (itr->second < target[S[right]]) {
					++cnt;
				}
				++itr->second;
			}
		} else {
			isFound = true;
			--right;
			itr = cur.find(S[left]);
			while (itr==cur.end() || itr->second > target[S[left]]) {
				if (itr != cur.end()) {
					--itr->second;
				}
				++left;
				itr = cur.find(S[left]);
			}
			//cout << left << " " << right << " " << S[left] << " " << S[right] << endl;
			if (right-left < minRight-minLeft) {
				minLeft = left;
				minRight = right;
			}
			cur[S[left]]--;
			++left;
			--cnt;
			itr = cur.find(S[left]);
			while (left <= right && (itr==cur.end()||itr->second > target[S[left]])) {
				if (itr != cur.end()) {
					--itr->second;
				}
				++left;
				itr = cur.find(S[left]);
			}
			//cout << left << endl;
		}
		++right;
	}
	if (isFound) {
		return S.substr(minLeft, minRight-minLeft+1);
	} else {
		return "";
	}
}

int main() {
	string S = "aabdidkcgacaagcb";
	string T = "aabc";
	cout << minWindow(S, T) << endl;
	return 0;
}
