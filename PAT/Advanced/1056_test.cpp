#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N=1003;
int mice[N],per[N],ratrank[N];
bool used[N];

int main()
{
    int np,ng;
	scanf("%d%d",&np,&ng);
	memset(used,0,sizeof(used));
	for(int i=0;i<np;i++)
		scanf("%d",mice+i);
	for(int i=0;i<np;i++)
		scanf("%d",per+i);
	int rem=np,groups=np/ng,max=-1,maxf=-1;
	if(np%ng!=0)
		groups++;
	while(rem!=1){
		for(int i=0;i<np;i++){
			if(!used[i]){
				ratrank[i]=groups+1;
				used[i]=true;
			}
		}
		int cnt=0,k=0,tt=0;
		while(k<groups){
			max=-1,maxf=-1;
			for(int j=0;j<ng&&tt<rem;j++){
				cout << per[tt] << " ";
				if(mice[per[tt]]>max)
					max=mice[per[tt]],maxf=per[tt];
				tt++;
			}
			cout << "||";
			used[maxf]=false;
			per[cnt++]=maxf;
			k++;
		}puts("");
		rem=groups;
		groups=rem/ng;
		if(rem%ng!=0)
			groups++;
	}
	if(maxf!=-1)
		ratrank[maxf]=1;
	else
		ratrank[0]=1;
	for(int i=0;i<np;i++){
		if(i!=0)
			printf(" ");
		printf("%d",ratrank[i]);
	}
    return 0;
}
