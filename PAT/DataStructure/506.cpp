#include <cstdio>
#include <iostream>
#include <vector>
//#include <map>
using namespace std;

#define MOD 100003

void getInput(long long &n) {
	char ch;
	while ((ch=getchar()) == ' ' || (ch) == '\n');
	n = 0;
	while (ch >= '0' && ch <= '9') {
		n = n*10 + ch-'0';
		ch = getchar();
	}
	if (ch == 'x') {
		n = n*100;
	}

	return ;
}

struct Node {
	long long id;
	long long flight;
	Node * next;
};

Node * accountInfo[MOD+1];

int main()
{
	//map <long long, long long> accountInfo;
//	map <long long, long long>::iterator itr;
	int n, k, m;
	long long id;
	long long flight;

	scanf("%d %d", &n, &k);
	//cout << n << " " << k << endl;
	while (n--) {
		getInput(id);
		getInput(flight);
	//	cout << id << " " << flight << endl;
		flight = flight < k ? k : flight;

		int indx = id%MOD;
		if (accountInfo[indx] == NULL) {
			accountInfo[indx] = new Node();
			accountInfo[indx]->id = id;
			accountInfo[indx]->flight = flight;
			accountInfo[indx]->next = NULL;
		} else if (accountInfo[indx]->id != id) {
			Node * cur = accountInfo[indx]->next;
			Node * pre = accountInfo[indx];
			while (cur!=NULL && cur->id!=id){
				pre = cur;
			   	cur = cur->next;
			}
			if (cur) {
				cur->flight += flight;
			} else {
				pre->next = new Node();
				cur = pre->next;
				cur->id = id;
				cur->flight = flight;
				cur->next = NULL;
			}
		} else {
			accountInfo[indx]->flight += flight;			
		}

		/*itr = accountInfo.find(id);
		if (itr == accountInfo.end()) {
			accountInfo.insert(pair <long long, long long>(id, flight));
		} else {
			itr->second = itr->second + flight;
		}*/
	}

	scanf("%d", &m);
	//cout << m << endl;
	while (m--) {
		getInput(id);

		int indx = id % MOD;

		if (accountInfo[indx] == NULL) {
			puts("No Info");
		} else if (accountInfo[indx]->id == id) {
			printf("%d\n", accountInfo[indx]->flight);
		} else {
			Node *pre = accountInfo[indx];
			Node *cur = accountInfo[indx]->next;
			while (cur && cur->id != id) {
				pre = cur;
				cur = cur->next;
			}

			if (cur) {
				printf("%d\n", cur->flight);
			} else {
				puts("No Info");
			}
		}

		//cout << id << endl;
		/*itr = accountInfo.find(id);
		if (itr == accountInfo.end()) {
			puts("No Info");
		} else {
			printf("%d\n", itr->second);
		}*/
	}

	return 0;
}
