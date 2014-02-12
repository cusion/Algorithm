#include <iostream>
#include <cstdio>
using namespace std;

int getNum(string str, int radix)
{
	int ret = 0;
	for(int i = 0; i<str.size(); ++i){
		char ch = str[i];
		ret = ret*radix + str[i]-'0';
	}
	return ret;
}

int main()
{
	int N, radix;
	string input;
	while((cin>>N) != NULL){
		int sum = 0;
		for(int i = 0; i< N; ++i){
			cin>>input;
			string strNum, strRadix;
			int j=0;
			char ch = input[j];
			while(ch!='('){
			//	cout<<ch;
				strNum += ch;
				ch = input[++j];
			}//cout<<endl;
			ch = input[++j];
			while(ch!=')'){
			//	cout<<ch;
				strRadix += ch;
				ch = input[++j];
			}//cout<<endl;
			radix = getNum(strRadix, 10);
			sum += getNum(strNum, radix);
			//cout<<radix<<" "<<sum<<endl;
		}
		cout<<sum<<endl;
	}

	return 0;
}
