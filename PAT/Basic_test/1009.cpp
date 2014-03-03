#include <iostream>
#include <cstdio>

using namespace std;

void _print(char * str, int start, int end)
{
	for (int i = start; i <= end; ++i) {
		cout << str[i];
	}
	if (start!=0) {
		cout << " ";
	} else {
		cout << endl;
	}
}

void Print(char * str, int start)
{
	int end = start;
	while(str[end]!=' ' && str[end]!='\0') {
		end++;
	}
	if (str[end] == ' ') {
		Print(str, end+1);
	}

	--end;

	_print(str, start, end);
	
	return 0;
}

int main()
{
	char sen[85];
	gets(sen);
	Print(sen, 0);

	return 0;
}
