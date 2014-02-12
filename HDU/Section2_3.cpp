#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T, Y, N;
	cin>>T;
	while(T--){
		cin>>Y>>N;
		int nextNLeapY = Y;
		while(!((nextNLeapY%4==0 && nextNLeapY%100!=0) || nextNLeapY%400==0))nextNLeapY++;
		N--;
		
		/*while(N && nextNLeapY%400){
			nextNLeapY += 4;
			if(nextNLeapY%100 || nextNLeapY%400==0)N--;
		}

		if(N == 0){
			cout<<nextNLeapY<<endl;
			continue;
		}

		N++;
		nextNLeapY -= 4;

		nextNLeapY += 400 * (N/97);

		N = N%97;*/

		while(N){
			nextNLeapY += 4;
			if(nextNLeapY%100 || nextNLeapY%400==0) N--;
		}

		cout<<nextNLeapY<<endl;
	}

	return 0;
}
