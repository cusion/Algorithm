#include <cstdio>
#include <iostream>

#define Max(a,b) ((a)>(b)?(a):(b))

using namespace std;

int dp[1005][1005];

int n,v,t;
int vol[1005], val[1005];

int DP()
{
	for(int i = 0; i<1005; ++i){
		for(int j = 0; j<1005; ++j){
			dp[i][j] = 0;
		}
	}
	for(int i = 1; i<=n; ++i){
		for(int j = 0; j<=v; ++j){
			if(j>=vol[i]){
				dp[i][j] = Max(dp[i-1][j], dp[i-1][j-vol[i]]+val[i]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][v];
}

int main()
{
	cin>>t;
	while(t--){
		cin>>n>>v;
		for(int i = 1; i<=n; ++i){
			cin>>val[i];
		}
		for(int i = 1; i<=n; ++i){
			cin>>vol[i];
		}

		cout<<DP()<<endl;
	}

	return 0;
}
