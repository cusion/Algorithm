#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

#define MAX 140                       // there is something wrong with the limit in the problem specification, the judgement do not consider this limitation
#define MOD 200003

struct Node {
	int cnt;
	char str[MAX+2];
	Node * next;
}*topic[MOD];

bool isAlphabet(char ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >='0' && ch <= '9')) return true;
	return false;
}

int myhash(char * str) {
	int ret = 0;
	for (int i = 0; str[i]!='\0'; ++i) {
		if (isAlphabet(str[i])) {
			ret = ret*26 + str[i] - 'a';
			ret = ret % MOD;
		}
	}
	return ret;
}

char toLowercase(char ch) {
	if (ch >= 'A' && ch <= 'Z') {
		return ch-'A'+'a';
	}
	return ch;
}

void trim(char * str) {
	int ind = 0;
	for (int i = 0; str[i]!='\0'; ++i) {
		if (isAlphabet(str[i])) {
			str[ind++] = str[i];
		} else {
			if (ind > 0 && str[ind-1]!=' ') {
				str[ind++] = ' ';
			}
		}
	}
	if (str[ind-1] == ' ') str[ind-1] = '\0';
	else str[ind] = '\0';

	return;
}

bool duplicate(char str[][MAX+5], int indx) {
	for (int i = 0; i < indx; ++i) {
		if(!strcmp(str[i], str[indx])) return true;
	}
	return false;
}

void getinput(char * str) {
	int i = 0;
	while ((str[i]=getchar()) == ' ' || (str[i] == '\n'));
	++i;
	while((str[i++] = getchar())!='\n');
	str[i] = '\0';
}

void insert(char str[][MAX+5], int indx) {
	int key = myhash(str[indx]);
	if (topic[key] == NULL) {
		topic[key] = new Node();
		topic[key]->cnt = 1;
		strcpy(topic[key]->str, str[indx]);
		topic[key]->next = NULL;
	} else if(!strcmp(topic[key]->str, str[indx])) {
		topic[key]->cnt++;
	} else {
		Node *pre = topic[key];
		Node *cur = topic[key]->next;
		while (cur && strcmp(cur->str, str[indx])) {
			pre = cur;
			cur = cur->next;
		}
		if (cur) {
			cur->cnt++;
		} else {
			pre->next = new Node();
			cur = pre->next;
			cur->cnt = 1;
			strcpy(cur->str, str[indx]);
			cur->next = NULL;
		}
	}
}

int main()
{
	//unordered_map <int, int> umap;
	char str[150];
	char tstr[140][MAX+5];
	int n;
	int tcnt = 0;
	int tind = 0;
	scanf("%d", &n);
	while (n--) {
		tind = tcnt = 0;
		int flag = 0;          // 0 for # not show up, 1 for waiting for next #
		getinput(str);
		for (int i = 0; str[i] != '\0'; ++i) {
			if (flag == 0) {
				if (str[i] == '#') {
					flag = 1;
				}
			} else {
				if (str[i] == '#') {
					tstr[tcnt][tind] = '\0';
					//puts("===");
					//puts(tstr[tcnt]);
					//puts("===");
					flag = 0;
					tind = 0;
					trim(tstr[tcnt]);
					//puts(tstr[tcnt]);
					if(!duplicate(tstr, tcnt)) {
						insert(tstr, tcnt);
						tcnt++;
					}
				} else {
					if (tind < MAX)
						tstr[tcnt][tind++] = toLowercase(str[i]);
				}
			}
		}
	}
	int max = -1, maxcnt = 0;
	Node * maxindx;
	for (int i = 0; i < MOD; ++i) {
		if (topic[i]) {
			Node * tmp = topic[i];
			int indxtmp = 0;
			while (tmp) {
				//printf("%s %d\n", tmp->str, tmp->cnt);
				if (tmp->cnt > max) {
					maxindx = tmp;
					maxcnt = 0;
					max = tmp->cnt;
				} else if (tmp->cnt == max) {
					maxindx = strcmp(tmp->str, maxindx->str) < 0 ? tmp : maxindx;
					maxcnt++;
				}
				tmp = tmp->next;
			}
		}
	}

	printf("%c%s\n%d\n", maxindx->str[0]-'a'+'A', &(maxindx->str[1]), maxindx->cnt);
	if (maxcnt) {
		printf("And %d more ...\n", maxcnt);
	}

	return 0;
}
