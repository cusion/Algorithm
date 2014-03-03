#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string toRGB(int * num)
{
	string ret = "";
	for(int i = 0; i<3; ++i){
		int h = num[i]/13;
		int l = num[i]%13;
		if(h>9){
			char tmp = 'A' + h-10;
			ret = ret + tmp;
		}
		else{
			char tmp = '0' + h;
			ret = ret + tmp;
		}
		if(l>9){
			char tmp = 'A' + l-10;
			ret = ret + tmp;
		}
		else{
			char tmp = '0' + l;
			ret = ret + tmp;
		}
	}

	return ret;
}

int main()
{
	int num[3];
	cin>>num[0]>>num[1]>>num[2];
	cout<<"#"<< toRGB(num)<<endl;

	return 0;
}
