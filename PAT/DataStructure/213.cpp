#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> l1;
	vector <int> l2;
	int n;
	cin>>n;

	int tmp;
	int num = 0;
	while((num<n)&&(scanf("%d", &tmp))){
		l1.push_back(tmp);
		num++;
	}
	num = 0;
	while((num < n)&&(scanf("%d", &tmp))){
		l2.push_back(tmp);
		num++;
	}

	int p1=0, p2=0;
	int ind = 0;
	while((p1<l1.size())&&(p2<l2.size())){
		if (ind >= (n-1)) {
			printf("%d\n", l1[p1] < l2[p2] ? l1[p1]:l2[p2]);
			return 0;
		}
		if (l1[p1] < l2[p2]) {
			p1++;
		} else {
			p2++;
		}
		ind++;
	}

	return 0;
}
