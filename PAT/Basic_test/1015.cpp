#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Person {
	int stunum;
	int de;
	int cai;
	friend bool operator < (Person a, Person b) {
		if (a.de + a.cai > b.de + b.cai) return true;
		else if (a.de + a.cai < b.de + b.cai) return false;
		else {
			if (a.de > b.de) return true;
			else if (a.de < b.de) return false;
			else {
				if (a.stunum > b.stunum) return false;
				else return true;
			}
		}
	}
} person[100005];

void swap(Person & a, Person & b)
{
	Person tmp = a;
	a = b;
	b = tmp;
}

int partition(Person * p, int start, int end, int st, bool (*pfunc)(Person, int))
{
	int small = start;
	int big = end;
	while(small < big) {
		if (pfunc(p[small], st)) small++;
		else {
			while (small < big) {
				if (!pfunc(p[big], st)) big--;
				else break;
			}
			if (small < big) {
				swap(p[small], p[big]);
			}
		}
	}

	return small-1;
}

bool getQualified(Person p, int st)
{
	if (p.de >= st && p.cai >= st) return true;
	
	return false;
}

bool getSecond(Person p, int st)
{
	if (p.de >= st) return true;

	return false;
}

bool getThird(Person p, int st)
{
	if (p.cai < p.de) return true;
	return false;
}

int main()
{
	int N, L, H;
	cin >> N >> L >> H;
	for (int i = 0; i < N; ++i) {
		cin >> person[i].stunum >> person[i].de >> person[i].cai;
	}

	int start = 0, end = N-1;
	end = partition(person, start, end, L, getQualified);

	cout << (end - start + 1) << endl;

	int border = -1;
	if (end > start) {
		border = partition(person, start, end, H, getQualified);
	}
	if (border >= 0) {
		sort(&person[start], &person[border+1]);
		for (int i = 0; i <= border; ++i) {
			cout << person[i].stunum << " " << person[i].de << " " << person[i].cai << endl;
		}
	}
	start = border + 1;
	border = partition(person, start, end, H, getSecond);
	if (border >= start) {
		sort(&person[start], &person[border+1]);
		for (int i = start; i <= border; ++i) {
			cout << person[i].stunum << " " << person[i].de << " " << person[i].cai << endl;
		}
	}

	start = border + 1;
	border = partition(person, start, end, H, getThird);
	if (border >= start) {
		sort(&person[start], &person[border+1]);
		for (int i = start; i <= border; ++i) {
			cout << person[i].stunum << " " << person[i].de << " " << person[i].cai << endl;
		}
	}

	if (border < end) {
		sort(&person[border+1], &person[end+1]);
		for (int i = border+1; i <= end; ++i) {
			//cout << person[i].stunum << " " << person[i].de << " " << person[i].cai << endl;
			printf("%d %d %d\n", person[i].stunum, person[i].de, person[i].cai);
		}
	}
	
	system("pause");

	return 0;
}
