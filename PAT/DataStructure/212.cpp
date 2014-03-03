#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> l1;
	vector <int> l2;

	int tmp;
	while((scanf("%d", &tmp)&&(tmp!=-1))){
		l1.push_back(tmp);
	}
	while((scanf("%d", &tmp)&&(tmp!=-1))){
		l2.push_back(tmp);
	}

	int p1=0, p2=0;
	bool isEmpty = true;
	while((p1<l1.size())&&(p2<l2.size())){
		if(l1[p1]<l2[p2])p1++;
		else if(l1[p1]>l2[p2])p2++;
		else{
			if(isEmpty){
				printf("%d", l1[p1]);
				p1++,p2++;
				isEmpty = false;
			}else{
				printf(" %d");
				p1++, p2++;
			}
		}
	}
	if(isEmpty){
		puts("NULL");
	}

	return 0;
}
