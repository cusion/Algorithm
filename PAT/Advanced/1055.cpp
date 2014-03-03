#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct people
{
        char name[9];
        int age;
        int worth;
}people;

people a[100000];
int N,K;
int agecount[201]={0};
int index1[100000];

int comp(const void *a,const void *b)
{
        people *pa=(people *)a;
        people *pb=(people *)b;
        int r;
        
        if( (r=pb->worth-pa->worth) != 0 ) 
            return r;
            
        if((r=pa->age-pb->age)!=0)
            return r;
            
        return strcmp(pa->name,pb->name);
}

int main()
{
        int i,m,amin,amax,j,count,k,all,n2=0;
        scanf("%d%d",&N,&K);
        for(i = 0; i < N; i++)
        {
                getchar();
                scanf("%s %d%d",a[i].name,&a[i].age,&a[i].worth);
        }
        qsort(a,N,sizeof(people),comp);
        for(i = 0; i < N; i++)
                if(++agecount[a[i].age]<=100)
                        index1[n2++]=i;
                        
        for(i = 0; i < K; i++)
        {
                scanf("%d%d%d",&m,&amin,&amax);
                all=0;
                for(k = amin; k <= amax ; k++)
                        all+=agecount[k];
                printf("Case #%d:\n",i+1);
                count=0;
                m = all < m ? all : m;
                if(all != 0)
                {
                        for(j = 0; j < n2; j++)
                        {
                                if(a[index1[j]].age <= amax && a[index1[j]].age >= amin)
                                {
                                        if(++count <= m)
                                                printf("%s %d %d\n",a[index1[j]].name,a[index1[j]].age,a[index1[j]].worth);
                                        else
                                                break;
                                }
                        }
                }
                if(count == 0)
                        printf("None\n");
        }
        return 0;
}
/*#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct Person {
	char name[10];
	int age;
	int worth;
	Person(){}
	Person(char n[], int a, int w){
		int i = 0;
		for (i = 0; n[i] != '\0'; ++i) {
			name[i] = n[i];
		}
		name[i] = n[i];
		age = a;
		worth = w;
	}
	friend bool operator <(Person a, Person b) {
		if (a.worth > b.worth) {
			return true;
		} else if (a.worth < b.worth) {
			return false;
		} else {
			if (a.age < b.age) {
				return true;
			} else if (a.age > b.age) {
				return false;
			} else {
				if (strcmp(a.name, b.name) < 0) {
					return true;
				} else {
					return false;
				}
			}
		}
	}
};

struct AgeSort {
	int age;
	int id;
	AgeSort(){}
	AgeSort(int a, int i):age(a), id(i){}
	friend bool operator <(AgeSort a, AgeSort b) {
		return a.age < b.age;
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	Person person[n];
	AgeSort agesort[n];
	for (int i = 0; i < n; ++i) {
		scanf("%s%d%d", &person[i].name, &person[i].age, &person[i].worth);
		agesort[i].id = i;
		agesort[i].age = person[i].age;
	}
	sort(agesort, agesort+n);
	int ageIndxLowerBound[201];
	int ageIndxUpperBound[201];
	
	// get the lower bound for each age;
	int indx = 0;
	for (int i = 0; i < 201; ++i) {
		while (indx < n && i > agesort[indx].age) {
			++indx;
		}
		if (indx >= n) {
			ageIndxLowerBound[i] = -1;
		} else {
			ageIndxLowerBound[i] = indx;
		}
	}
	
	// get the upper bound for each age;
	indx = n-1;
	for (int i = 200; i >= 0; --i) {
		while (indx >= 0 && i < agesort[indx].age) {
			--indx;
		}
		ageIndxUpperBound[i] = indx;
	}
	priority_queue<Person> rank;
	//vector <Person> finalRank;
	Person finalRank[n];
	int finalCnt;
	for (int i = 0; i < k; ++i) {
		finalCnt = 0;
		int lower, upper, maximum;
		scanf("%d%d%d", &maximum, &lower, &upper);
		int lowerIndx = ageIndxLowerBound[lower];
		int upperIndx = ageIndxUpperBound[upper];
		//cout << lowerIndx << " " << upperIndx << endl;
		for (int j = lowerIndx; j >= 0 && j <= upperIndx; ++j) {
			if (rank.size() < maximum) {
				rank.push(person[agesort[j].id]);
			} else if (rank.size() >= maximum && person[agesort[j].id] < rank.top()) {
				rank.pop();
				rank.push(person[agesort[j].id]);
			}
		}
		while (!rank.empty()) {
			finalRank[finalCnt++] = rank.top();
			rank.pop();
		}
		printf("Case #%d:\n", i+1);
		if (finalCnt == 0) {
			puts("None");
		} else {
			for (int j = finalCnt-1; j >= 0; --j) {
				printf("%s %d %d\n", finalRank[j].name, finalRank[j].age, finalRank[j].worth);
			}
		}
	}
	
	return 0;
}*/
