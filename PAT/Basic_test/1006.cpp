#include <iostream>
#include <cstdio>

using namespace std;

void Print(int n, int level) {
	switch (level) {
		case 1:
			for (int i = 1; i <= n; ++i) {
				cout << i ;
			}
			break;
		case 2:
			for (int i = 0; i < n; ++i) {
				cout << "S" ;
			}
			break;
		case 3:
			for (int i = 0; i < n; ++i) {
				cout << "B";
			}
			break;
	}
	return ;
}

void Format(int n, int level) {
	if (n == 0) {
		return ;
	}
	Format(n/10, level+1);
	Print(n%10, level);
	return ;
}

int main() {
	int n;
	cin>>n;

	Format(n, 1);

	cout<<endl;

	return 0;
}
