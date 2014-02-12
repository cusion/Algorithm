#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int A;
	while((cin>>A) && A != 0){
		int tmp = 0;
		//cout<<(A&(1))<<endl;
		//cout<<(A&(1<<1))<<endl;
		//cout<<(A&(1<<2))<<endl;
		//cout<<(A&(1<<3))<<endl;
		//cout<<(A&(1<<4))<<endl;
		while((A&(1<<tmp))==0){
			//cout<<A<<" "<<(1<<tmp)<<" "<<(A&(1<<tmp))<<endl;
			tmp++;
		}
		cout<< (1<<tmp) <<endl;
	}

	return 0;
}
