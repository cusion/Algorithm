#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int m,n;
	int t;
	cin>>t;
	for(int i = 0; i<t; ++i){
		cin>>m>>n;
		cout<<"Scenario #"<<i+1<<":\n";
		if(m%2 ==0 || n%2 ==0){
			cout<<fixed<<setprecision(2)<<m*n+0.0<<endl;
		}else{
			cout<<fixed<<setprecision(2)<<m*n+0.41<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}
