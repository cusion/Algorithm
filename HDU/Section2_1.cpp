#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	int arr[105];
	arr[0]=0;
	while( cin>>n && n != 0){
		for(int i=1; i<=n; ++i){
			cin>>arr[i];
		}
		int timeCost = 0;
		for(int i = 1; i<= n; ++i){
			if(arr[i]>arr[i-1]){
				timeCost += 6*(arr[i]-arr[i-1]);
			}else if(arr[i]<arr[i-1]){
				timeCost += 4*(arr[i-1]-arr[i]);
			}
			timeCost += 5;
		}

		cout<<timeCost<<endl;
	}
}
