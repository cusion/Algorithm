#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char str[100];
	while(cin.getline(str, 99) && str[0]!='#'){
		for(int i = 0; str[i]!='\0'; ++i){
			char ch = str[i];
			switch(ch){
				case ' ':
					cout<<"%20";
					break;
				case '!':
					cout<<"%21";
					break;
				case '$':
					cout<<"%24";
					break;
				case '%':
					cout<<"%25";
					break;
				case '(':
					cout<<"%28";
					break;
				case ')':
					cout<<"%29";
					break;
				case '*':
					cout<<"%2a";
					break;
				default:
					cout<<ch;
			}
		}
		cout<<endl;
	}

	return 0;
}
