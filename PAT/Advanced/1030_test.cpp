#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<stack>

using namespace std;

const int N=500;
const int MAX_INT=0xffffff;

int dis[N][N];
int cost[N][N];
int path[N];
int visited[N];

void dijkstra(int n,int s){
	int i,j;
	memset(visited,0,sizeof(visited));
	visited[s]=1;
	for(i=0;i<n;i++){
		if(dis[s][i]<MAX_INT){
			path[i]=s;
		}
	}
	for(i=0;i<n;i++){
		int min_dis=MAX_INT;
		int min_v;
		int min_cost=MAX_INT;
		for(j=0;j<n;j++){
			if(0==visited[j]){
				if(dis[s][j]<min_dis){
					min_v=j;
					min_dis=dis[s][j];
					min_cost=cost[i][j];
				}
			}
		}
		visited[min_v]=1;
		for(j=0;j<n;j++){
			if((dis[s][min_v]+dis[min_v][j]<dis[s][j])||(dis[s][min_v]+dis[min_v][j]==dis[s][j]&&cost[s][min_v]+cost[min_v][j]<cost[s][j])){
				dis[s][j]=dis[s][min_v]+dis[min_v][j];
				path[j]=min_v;
				cost[s][j]=cost[s][min_v]+cost[min_v][j];
			}
		}
	}
}
int main()
{
	int n,m,s,d;
	scanf("%d%d%d%d",&n,&m,&s,&d);
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			dis[i][j]=MAX_INT;
			cost[i][j]=MAX_INT;
			if(i==j){
				dis[i][j]=0;
				cost[i][j]=0;
			}
		}
	}
	for(i=0;i<m;i++){
		int a,b,d,c;
		scanf("%d%d%d%d",&a,&b,&d,&c);
		dis[a][b]=d;
		dis[b][a]=d;
		cost[a][b]=c;
		cost[b][a]=c;
	}
	dijkstra(n,s);
	stack<int> st;
	int p=d;
	while(p!=s){
		st.push(p);
		p=path[p];
	}
	printf("%d",s);
	while(!st.empty()){
		printf(" %d",st.top());
		st.pop();
	}
	printf(" %d %d",dis[s][d],cost[s][d]);
	return 0;
}
