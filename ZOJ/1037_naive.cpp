#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int visited[55][55];
int m, n;
double dist;

void salesManPath(int i, int j, int step, double dist_tmp, double increment)
{
	if(step == m*n && i ==0 && j == 0){
		dist = dist > dist_tmp + increment ?dist_tmp + increment : dist;
		return ;
	}

	if(visited[i][j] != 0) return ;

	visited[i][j] = 1;

	if(i-1>=0 && j-1 >=0) salesManPath(i-1, j-1, step+1, dist_tmp+increment, sqrt(2));
	if(j-1>=0)salesManPath(i, j-1, step+1, dist_tmp + increment, 1);
	if(i+1<m && j-1>=0) salesManPath(i+1, j-1, step+1, dist_tmp+increment, sqrt(2));
	if(i+1<m ) salesManPath(i+1, j, step+1, dist_tmp+increment, 1);
	if(i+1<m && j+1<n) salesManPath(i+1, j+1, step+1, dist_tmp+increment, sqrt(2));
	if(j+1<n) salesManPath(i, j+1, step+1, dist_tmp+increment, 1);
	if(i-1>=0 && j+1 <n) salesManPath(i-1, j+1, step+1, dist_tmp+increment, sqrt(2));
	if(i-1>=0) salesManPath(i-1, j, step+1, dist_tmp+increment, 1);

	visited[i][j] = 0;
	return ;
}

int main()
{
	int t;
	cin>>t;
	for(int i = 0; i< t; ++i){
		//cin>>m>>n;
		for( m = 1; m< 10; ++m)
			for(n = 1; n<=m; ++n){
		for(int j = 0; j<m; ++j){
			for(int k = 0; k<n; ++k){
				visited[j][k] = 0;
			}
		}
		dist = 1000000000;

		salesManPath(0, 0, 0, 0, 0);

		cout<<m<<" "<<n<<" "<<dist<<endl;}
		//cout<<fixed<<setprecision(2)<<"Scenario #"<<i+1<<":\n"<<dist<<"\n"<<endl;
	}
}
