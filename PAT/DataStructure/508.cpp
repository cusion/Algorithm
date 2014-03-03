#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define DOCMAX 105
#define LINEMAX 105
#define WORDMAX 55
#define MOD 500009
#define RADIX 26

struct Document {
	char name[WORDMAX];
	char content[LINEMAX][WORDMAX];
};

struct HashNode {
	char word[WORDMAX];
	vector <int> docind;
	vector <int> lineind;
	HashNode * next;
} *hashIndex[MOD];

struct ResultNode {
	int docind;
	int lineind;

	bool friend operator < (ResultNode a, ResultNode b) {
		if (a.docind < b.docind) return true;
		else if (a.docind > b.docind) return false;
		else {
			if (a.lineind < b.lineind) return true;
			else return false;
		}
	}

	bool friend operator == (ResultNode a, ResultNode b) {
		return a.docind == b.docind && a.lineind == b.lineind;
	}
};

char toLowercase(char ch) {
	if (ch >= 'A' && ch <= 'Z') {
		return ch-'A'+'a';
	}

	return ch;
}

int myhash(char *str, int len) {
	int ret = 0;
	for (int i = 0; i < len; ++i) {
		ret = ret*RADIX + toLowercase(str[i])-'a';
		if (ret < 0) ret = 0;
		else if (ret >= MOD) {
			ret = ret%MOD;
		}
	}

	return ret;
}

bool isAlphaNumerical(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

void mystrcpy(char * dst, char * src, int len) {
	for (int i = 0; i < len; ++i) {
		dst[i] = toLowercase(src[i]);
	}
	dst[len] = '\0';
}

int mystrcmpi(char *str1, char * str2, int len) {
	int i;
	for (i = 0; str1[i]!='\0' && i < len; ++i) {
		if (str1[i] != toLowercase(str2[i])) {
			return str1[i] - toLowercase(str2[i]);
		}
	}
	if (i == len && str1[i] == '\0') return 0;
	else if (i < len) return -1;
	else return 1;
}

void hashWord(char *str, int docind, int lineind) {
	int i = 0;
	int len = 0;
	while (str[i]!='\0') {
		while (str[i]!='\0'&&!isAlphaNumerical(str[i])) {
			++i;
		}
		int len = 0;
		while (str[i+len]!='\0' && isAlphaNumerical(str[i+len])) {
			++len;
		}
		if (len > 0) {
			int key = myhash(&str[i], len);
			if (hashIndex[key] == NULL) {
				hashIndex[key] = new HashNode();
				hashIndex[key]->docind.push_back(docind);
				hashIndex[key]->lineind.push_back(lineind);
				mystrcpy(hashIndex[key]->word, &str[i], len);
				hashIndex[key]->next = NULL;
			} else if (!mystrcmpi(hashIndex[key]->word, &str[i], len)) {
				hashIndex[key]->docind.push_back(docind);
				hashIndex[key]->lineind.push_back(lineind);
			} else {
				HashNode * pre = hashIndex[key];
				HashNode * cur = hashIndex[key]->next;
				while (cur && mystrcmpi(cur->word, &str[i], len)) {
					pre = cur;
					cur = cur->next;
				}

				if (cur) {
					cur->docind.push_back(docind);
					cur->lineind.push_back(lineind);
				} else {
					pre->next = new HashNode();
					cur = pre->next;
					mystrcpy(cur->word, &str[i], len);
					cur->docind.push_back(docind);
					cur->lineind.push_back(lineind);
					cur->next = NULL;
				}
			}
		}
		i += len;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	Document doc[n];
	for (int i = 0; i < n; ++i) {
		scanf("%s", doc[i].name);
		int ind = 0;
		while (gets(doc[i].content[ind]) && doc[i].content[ind][0]!='#') {
			while (doc[i].content[ind][0]=='\0' || doc[i].content[ind][0]=='\n') {
				gets(doc[i].content[ind]);
			}
			
			hashWord(doc[i].content[ind], i, ind);

			ind++;
		}
		/*for (int j = 0; j < ind; ++j) {
			puts(doc[i].content[j]);
		}*/
	}
	for (int i = 0; i < n; ++i) {
		puts(doc[i].name);
		for (int j = 0; doc[i].content[j][0]!='#';++j) {
			puts(doc[i].content[j]);
		}
	}
	cout << "===================" << endl;
	int m;
	scanf("%d", &m);
	char query[150];
	vector <ResultNode> res;
	for (int i = 0; i < m; ++i) {
		gets(query);
		while(query[0] == '\0' || query[0] == '\n')gets(query);
		int indx = 0; int len = 0;
		while (query[indx]!='\0') {
			while (query[indx]!='\0' && !isAlphaNumerical(query[indx])) {
				indx++;
			}
			len = 0;
			while (query[indx+len]!='\0' && isAlphaNumerical(query[indx+len])) {
				len++;
			}

			int key = myhash(&query[indx], len);

			HashNode * tmp = hashIndex[key];
			while (tmp) {
				if (!mystrcmpi(tmp->word, &query[indx], len)) {
					for (int j = 0; j < tmp->docind.size(); ++j) {
						ResultNode tmpNode;
						tmpNode.docind = tmp->docind[i];
						tmpNode.lineind = tmp->lineind[i];
						res.push_back(tmpNode);
					}
					break;
				}
				tmp = tmp->next;
			}
			indx += len;
		}
		if (res.empty()) {
			puts("0\nNot Found");
		} else {
			set <ResultNode> resSet(res.begin(), res.end());
			set <ResultNode>::iterator itr;
			printf("%d\n", resSet.size());
			for (itr = resSet.begin(); itr!=resSet.end();++itr) {
				int docind = (*itr).docind;
				int lineind = (*itr).lineind;
				cout << docind << "  " << lineind << endl;
				puts(doc[i].content[lineind]);
			}
		}
		res.clear();
	}

	return 0;
}
