#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	const double PI = 3.1415927;
	double dia, time;
	int rev;
	int caseNum = 1;
	while(cin>>dia>>rev>>time && rev != 0){
		double dis =  rev*PI*dia/12/5280;
		printf("Trip #%d: %.2lf %.2lf\n", caseNum++, dis, dis/time*3600);
	}

	return 0;
}
