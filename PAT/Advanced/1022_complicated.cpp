#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Book {
	int id;    // 7-digit
	char title[83];
	char author[82];
	char keywords[5][13];
	char publisher[83];
	int year;
	
	bool operator <(const Book &a) {
		return id < a.id;
	}
};

int main() {
	int id, year;
	char title[100], author[100], keywords[100], publisher[100];
	unordered_map<string, vector<int> > title_hash;
	unordered_map<string, vector<int> > author_hash;
	unordered_map<string, vector<int> > keyword_hash;
	unordered_map<string, vector<int> > publisher_hash;
	unordered_map<int, vector<int> > year_hash;
	int n;
	cin >> n;
	//Book books[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &id);
		getchar();
		gets(title);
		gets(author);
		gets(keywords);
		gets(publisher);
		scanf("%d", &year);
		
		/*cout << id << endl;
		puts(title);
		puts(author);
		puts(keywords);
		puts(publisher);
		cout << year << endl;*/
		
		// hash title
		if (title_hash.find(string(title)) == title_hash.end()) {
			title_hash[string(title)] = vector<int>(1, id);
		} else {
			title_hash[string(title)].push_back(id);
		}
		
		// hash author
		if (author_hash.find(string(author)) == author_hash.end()) {
			author_hash[string(author)] = vector<int>(1, id);
		} else {
			author_hash[string(author)].push_back(id);
		}
		
		// hash keyword
		//puts("=============================");
		int start = 0;
		for (int i = 0; keywords[i] != '\0'; ++i) {
			if (keywords[i] == ' ') {
				keywords[i] = '\0';
				//puts(&keywords[start]);
				if (keyword_hash.find(string(&keywords[start])) == keyword_hash.end()) {
					keyword_hash[string(&keywords[start])] = vector<int>(1, id);
				} else {
					keyword_hash[string(&keywords[start])].push_back(id);
				}
				start = i+1;
			}
		}
		//puts(&keywords[start]);
		if (keyword_hash.find(string(&keywords[start])) == keyword_hash.end()) {
			keyword_hash[string(&keywords[start])] = vector<int>(1, id);
		} else {
			keyword_hash[string(&keywords[start])].push_back(id);
		}
		//puts("++++++++++++++++++++++++++++++");
		
		//hash publisher
		if (publisher_hash.find(string(publisher)) == publisher_hash.end()) {
			publisher_hash[string(publisher)] = vector<int>(1, id);
		} else {
			publisher_hash[string(publisher)].push_back(id);
		}
		
		//hash year
		if (year_hash.find(year) == year_hash.end()) {
			year_hash[year] = vector<int>(1, id);
		} else {
			year_hash[year].push_back(id);
		}
		
	}
	
	for (auto it = title_hash.begin(); it != title_hash.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}
	for (auto it = author_hash.begin(); it != author_hash.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}
	for (auto it = keyword_hash.begin(); it != keyword_hash.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}
	for (auto it = publisher_hash.begin(); it != publisher_hash.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}
	for (auto it = year_hash.begin(); it != year_hash.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}
	
	int query, ytmp;
	char qstr[100];
	cin >> query;
	getchar();
	vector <int> res;
	for (int i = 0; i < query; ++i) {
		bool isFound = true;
		gets(qstr);
		puts(qstr);
		//cout << qstr << endl;
		switch(qstr[0]) {
			case '1':
				if (title_hash.find(string(&qstr[3])) == title_hash.end()) {
					puts("Not Found");
					isFound = false;
				} else {
					res = title_hash[string(&qstr[3])];
				}
				break;
			case '2':
				if (author_hash.find(string(&qstr[3])) == author_hash.end()) {
					puts("Not Found");
					isFound = false;
				} else {
					res = author_hash[string(&qstr[3])];
				}
				break;
			case '3':
				if (keyword_hash.find(string(&qstr[3])) == keyword_hash.end()) {
					puts("Not Found");
					isFound = false;
				} else {
					res = keyword_hash[string(&qstr[3])];
				}
				break;
			case '4':
				if (publisher_hash.find(string(&qstr[3])) == publisher_hash.end()) {
					puts("Not Found");
					isFound = false;
				} else {
					res = publisher_hash[string(&qstr[3])];
				}
				break;
			case '5':
				ytmp = 0;
				for (int i = 3; qstr[i] != '\0'; ++i) {
					ytmp = ytmp*10 + qstr[i] - '0';
				}
				if (year_hash.find(ytmp) == year_hash.end()) {
					puts("Not Found");
					isFound = false;
				} else {
					res = year_hash[ytmp];
				}
				break;
			default:
				break;
		}
		
		if (isFound) {
			for (int i = 0; i < res.size(); ++i) {
				printf("%07d\n", res[i]);
			}
		}
	}
	return 0;
}
