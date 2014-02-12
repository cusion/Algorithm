#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	cin>>T;
	char str[55];
	for(int i = 0; i<T; ++i){
		cin>>str;
		for(int j = 0; str[j]!='\0'; ++j){
			if(str[j]>='A'&&str[j]<='Z'){\
				str[j] = str[j]-'A'+'a';
			}
			switch(str[j]){
				case 'a':
					cout<<'A';
					break;
				case 'e':
					cout<<'E';
					break;
				case 'i':
					cout<<'I';
					break;
				case 'o':
					cout<<'O';
					break;
				case 'u':
					cout<<'U';
					break;
				default:
					printf("%c", str[j]);
					break;
			}
		}
		cout<<endl;
	}

	return 0;
}
