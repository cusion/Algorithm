#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int str2num(char str[]) {
	int ret = 0;
	int indx = 0;
	while (str[indx] != '\0') {
		ret = ret*10 + str[indx] - '0';
		++indx;
	}
	
	return ret;
}

struct Record {
	int c,m,e,a;
	Record(int cd, int md, int ed, int ad):c(cd), m(md), e(ed), a(ad) {}
};

struct Rank {
	int rank;
	char course;
	Rank(int r, int c):rank(r), course(c){}
};

int main() {
	int n, m;
	cin >> n >> m;
	char stunum[10];
	unordered_map <int, Record> stu;
	unordered_map <int, Rank> rank;
	vector<int> C(n);
	vector<int> M(n);
	vector<int> E(n);
	vector<int> A(n);
	int cc,mc,ec;
	for (int i = 0; i < n; ++i) {
		scanf("%s%d%d%d", stunum, &cc, &mc, &ec);
		C[i] = cc;
		M[i] = mc;
		E[i] = ec;
		A[i] = (C[i] + M[i] + E[i]) / 3;
		stu.insert(pair<int, Record>(str2num(stunum), Record(C[i], M[i], E[i], A[i])));
	}
	sort(C.begin(), C.end());
	sort(M.begin(), M.end());
	sort(E.begin(), E.end());
	sort(A.begin(), A.end());
	
	unordered_map <int, Rank>::iterator itr;
	unordered_map <int, Record>::iterator itr1;
	vector<int>::iterator vecitr;
	for (int i = 0; i < m; ++i) {
		scanf("%s", stunum);
		int stuIntNum = str2num(stunum);
		itr1 = stu.find(stuIntNum);
		if (itr1 == stu.end()) {
			cout << "N/A" <<endl;
			continue;
		}
		
		itr = rank.find(stuIntNum);
		if (itr != rank.end()) {
			cout << itr->second.rank << " "  << itr->second.course << endl;
		} else {
			Rank tmp(-1, 'A');
			vecitr = upper_bound(A.begin(), A.end(), itr1->second.a);
			if (vecitr-A.begin() > tmp.rank) {
				tmp.rank = vecitr-A.begin();
				tmp.course = 'A';
			}
			vecitr = upper_bound(C.begin(), C.end(), itr1->second.c);
			if (vecitr-C.begin() > tmp.rank) {
				tmp.rank = vecitr-C.begin();
				tmp.course = 'C';
			}
			vecitr = upper_bound(M.begin(), M.end(), itr1->second.m);
			if (vecitr-M.begin() > tmp.rank) {
				tmp.rank = vecitr-M.begin();
				tmp.course = 'M';
			}
			vecitr = upper_bound(E.begin(), E.end(), itr1->second.e);
			if (vecitr-E.begin() > tmp.rank) {
				tmp.rank = vecitr-E.begin();
				tmp.course = 'E';
			}
			tmp.rank = n - tmp.rank + 1;
			rank.insert(pair<int, Rank>(stuIntNum, tmp));
			cout << tmp.rank << " " << tmp.course << endl;
		}
	}
	return 0;
}
