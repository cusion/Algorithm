#include <cstdio>
#include <iostream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// At first, I was thinking of using KMP algorithm to find all indices in S of each word in
// L, and then try to find out the continuous indices within all words, this could be easily
// done cause indices of each word would be sorted using KMP. Future details should be considered.

// The above method deserves a trial after I have studied KMP algorithm sometime later, but
// the following method comes from a hint of discuss in the problem set, it makes use of 
// method of the Minimum Window Substring. However, it comes out to be TLE.
/*
bool checkValid(string &S, int start, int end, int len, unordered_map<string, int> &target) {
	int num = (end-start+1)/len;
	unordered_map<string, int> current;
	unordered_map<string, int>::iterator itr;
	for (int i = 0; i < num; ++i) {
		string tmp = S.substr(start+i*len, len);
		if (target.find(tmp)==target.end()){
			return false;
		}
		if (current.find(tmp) == current.end()) {
			current.insert(pair<string,int>(tmp, 1));
		} else {
			current[tmp]++;
			if (current[tmp] > target[tmp]) {
				return false;
			}
		}
	}
	return true;
}

vector<int> findSubstring(string S, vector<string> &L) {
	vector <int> ret;
	if (S.empty() || L.empty() || S.length() < L.size()*L[0].size()) {
		return ret;
	}
	int len = L.size()*L[0].size();
	unordered_map<char, int> target;
	unordered_map<char, int>::iterator itr;
	unordered_map<char, int> cur;
	unordered_map<string, int> words;
	for (int i = 0; i < L.size(); ++i) {
		if (words.find(L[i]) != words.end()) {
			words[L[i]]++;
		} else {
			words.insert(pair<string,int>(L[i], 1));
		}
		for (int j = 0; j < L[i].size(); ++j) {
			if (target.find(L[i][j]) == target.end()) {
				target.insert(pair<char,int>(L[i][j], 1));
				cur.insert(pair<char,int>(L[i][j], 0));
			} else {
				target[L[i][j]]++;
			}
		}
	}
	int left = 0, right = 0;
	int cnt = 0;
	S.push_back('$');
	while (right < S.length()) {
		if (cnt < len) {
			itr = cur.find(S[right]);
			if (itr != cur.end()) {
				if (itr->second < target[S[right]]) {
					++cnt;
				}
				++itr->second;
			}
		} else {
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
			if (right == left + len - 1) {
				if (checkValid(S, left, right, L[0].size(), words)) {
					ret.push_back(left);
				}
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
}*/

// A slightly improved version of the above method, because the length of the word is
// fixed, we do not need to find the minimum len, but rather use a window of the fixed
// len to detect wether all words have appeared. Still TLE.
/*bool checkValid(string &S, int start, int end, int len, unordered_map<string, int> &target) {
	int num = (end-start+1)/len;
	unordered_map<string, int> current;
	for (int i = 0; i < num; ++i) {
		string tmp = S.substr(start+i*len, len);
		if (target.find(tmp)==target.end()){
			return false;
		}
		if (current.find(tmp) == current.end()) {
			current.insert(pair<string,int>(tmp, 1));
		} else {
			current[tmp]++;
			if (current[tmp] > target[tmp]) {
				return false;
			}
		}
	}
	return true;
}
vector <int> findSubstring(string S, vector<string> &L) {
	vector <int> ret;
	if (S.empty() || L.empty() || S.length() < L.size()*L[0].size()) {
		return ret;
	}
	int len = L.size()*L[0].size();
	unordered_map<string, int> target;
	for (int i = 0; i < L.size(); ++i) {
		if (target.find(L[i]) == target.end()) {
			target.insert(pair<string,int>(L[i], 1));
		} else {
			target[L[i]]++;
		}
	}
	for (int i = 0; i <= S.size()-len; ++i) {
		if (checkValid(S, i, i+len-1, L[0].size(), target)) {
			ret.push_back(i);
		}
	}
	return ret;
}*/

// Another version though I do not think there are any difference between this one and the
// above one;
/*vector<int> findSubstring(string S, vector<string> &L) {
    //There may be duplicate words in L
    int Ssize = S.size();
    int m = L.size();
    int k = L[0].size();
    unordered_map<string, int> word;
    vector<int> res;
    for(int i = 0; i < m; ++i)
        word[L[i]]++;
    for(int i = 0; i <= Ssize - k * m; ++i) {//if I use i <= S.size() - k * m directly, it is wrong because S.size() is                                      //                                               the type of size_t
        string tmp = S.substr(i,k);
		if(word.find(tmp) == word.end())
            continue;
        else {
            unordered_map<string, int> hm = word;
            int j = i;
            while(true) {
            	string tmp1 = S.substr(j, k);
                if(hm.find(tmp1) == hm.end())
                    break;
                else {
                    if(hm[tmp1] == 1)
                        hm.erase(tmp1);
                    else
                        hm[tmp1]--;
                    j += k;
                    if(hm.size() == 0) {
                        res.push_back(i);
                        break;
                    }
                }
            }
        }
    }
    return res;
}*/

// There is a method which derives from the idea of the second solution, however, it
// uses some tricks to implement it more efficientlly, aproximately O(size(S)*size(L[0])).
// it splits S into size(L[0]) sequences which consists of partickles with length of 
// size(L[0]); and then use Minimum Window Substring method to find substrings consists
// exactly of elements in L; As we see, this problem now turns into another one, in which
// we need to find substring contains all character in L in multiple strings, if we view 
// an item in L as a virtual character.
vector<int> findSubstring(string S, vector<string> &L) {
	vector<int> ret;
	if (S.empty()||L.empty()||S.length()<L.size()*L[0].size()) {
		return ret;
	}
	int len = S.length();
	int num = L.size();
	int elen = L[0].size();
	int begin = 0, cnt = 0;
	unordered_map<string, int> target;
	unordered_map<string, int> cur;
	for (int i = 0; i < L.size(); ++i) {
		target[L[i]]++;
	}
	for (int subseqStart = 0; subseqStart < elen; ++subseqStart) {
		// initial sequence search
		begin = subseqStart;
		cnt = 0;
		cur.clear();
		// start searching in a sequence
		for (int i = subseqStart; i <= len-elen; i+=elen) {
			string eletmp = S.substr(i, elen);
			if (target.find(eletmp) == target.end()) {
				cnt = 0;
				begin = i+elen;
				cur.clear();
			} else {
				if (cur.find(eletmp) == cur.end() || cur[eletmp] < target[eletmp]) {
					cnt++;
				}
				cur[eletmp]++;
				while(cur[eletmp] > target[eletmp]) {
					string remtmp = S.substr(begin, elen);
					cur[remtmp]--;
					if (cur[remtmp] < target[remtmp]) {
						cnt--;
					}
					begin += elen;
				}
				if (cnt == num) {
					ret.push_back(begin);
					cur[S.substr(begin,elen)]--;
					begin += elen;
					cnt--;
				}
			}
		}
	}
	return ret;
}

int main() {
	string S = "barfoothefoobarman";
	vector<string> L;
	L.push_back("foo");
	L.push_back("bar");
	vector<int> ret = findSubstring(S, L);
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << " ";
	}puts("");
	return 0;
}
