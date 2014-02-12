#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	double avg=0;
	int count=0;
	char ch;
	while((ch=getchar())!=EOF){
		if(ch=='\n'){
			printf("%.2lf\n", avg/count);
			avg = 0;
			count = 0;
		}else if(ch == ' '){
			continue;
		}else{
			count++;
			switch(ch){
				case 'A':
					avg += 4;
					break;
				case 'B':
					avg += 3;
					break;
				case 'C':
					avg += 2;
					break;
				case 'D':
					avg += 1;
					break;
				case 'F':
					avg += 0;
					break;
				default:
					while((ch = getchar())!='\n');
					cout<<"Unknown letter grade in input"<<endl;
					avg = 0;
					count = 0;
					break;
			}
		}
	}

	return 0;
}
