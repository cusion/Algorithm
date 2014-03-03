#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int id, year;
	string title, author, keywords, publisher;
	unordered_map<string, vector<int> > strMap[4];
	unordered_map<int, vector<int> > yearMap;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &id);
		getchar();
		//cout << "==================" << endl;
		//cout << id <<endl;
		getline(cin, title);
		strMap[0][title].push_back(id);
		
		getline(cin, author);
		strMap[1][author].push_back(id);
		
		getline(cin, keywords);
		int start = 0;
		for (int i = 0; i < keywords.length(); ++i) {
			if (keywords[i] == ' ') {
				strMap[2][keywords.substr(start, i-start)].push_back(id);
				start = i + 1;
			}
		}
		strMap[2][keywords.substr(start)].push_back(id);
		
		getline(cin, publisher);
		strMap[3][publisher].push_back(id);
		
		scanf("%d", &year);
		yearMap[year].push_back(id);
	}
	
	for (int i = 0; i < 4; ++i) {
		for (auto it = strMap[i].begin(); it != strMap[i].end(); ++it) {
			sort(it->second.begin(), it->second.end());
		}
	}
	for (auto it = yearMap.begin(); it != yearMap.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}
	
	int k;
	cin >> k;
	getchar();
	string qstr;
	vector <int> res;
	for (int i = 0; i < k; ++i) {
		getline(cin, qstr);
		cout << qstr << endl;
		if (qstr[0] == '5') {
			int yTmp = 0;
			for (int i = 3; i < qstr.length(); ++i) {
				yTmp = yTmp*10 + qstr[i]-'0';
			}
			res = yearMap[yTmp];
			if (res.size() > 0) {
				for (int i = 0; i < res.size(); ++i) {
					printf("%07d\n", res[i]);
				}
			} else {
				puts("Not Found");
			}
		} else {
			res = strMap[qstr[0]-'0'-1][qstr.substr(3)];
			if (res.size() > 0) {
				for (int i = 0; i < res.size(); ++i) {
					printf("%07d\n", res[i]);
				}
			} else {
				puts("Not Found");
			}
		}
	}
	
	return 0;
}
