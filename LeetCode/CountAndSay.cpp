#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

string countAndSay(int n) {
	vector <int> count(1,1);
	vector <int> say;
	for (int i = 0; i < n-1; ++i) {
		int cnt = 1;
		say.clear();
		for (int j = 1; j < count.size();++j) {
			if (count[j-1]!=count[j]) {
				vector <int> res;
				while (cnt) {
					res.push_back(cnt%10);
					cnt /= 10;
				}
				for (int k = res.size()-1; k >= 0; --k) {
					say.push_back(res[k]);
				}
				say.push_back(count[j-1]);
				cnt = 1;
			} else {
				++cnt;
			}
		}
		say.push_back(cnt);
		say.push_back(count[count.size()-1]);
		count.swap(say);;
	}
	
	string ret = "";
	for (int i = 0; i < count.size(); ++i) {
		ret.append(1, '0'+count[i]);
	}
	return ret;
}

int main() {
	int n;
	while (1) {
		cin >> n;
		cout << countAndSay(n) << endl;
	}
	return 0;
}
