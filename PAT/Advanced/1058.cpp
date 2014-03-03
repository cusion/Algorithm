#include <cstdio>
#include <iostream>
using namespace std;

struct Number {
	int ga;
	int si;
	int kn;
};

Number add(Number a, Number b) {
	Number c;
	c.kn = a.kn + b.kn;
	c.si = a.si + b.si + c.kn/29;
	c.ga = a.ga + b.ga + c.si/17;
	//c.ga %= 10000001;
	c.si %= 17;
	c.kn %= 29;
	return c;
}

int main() {
	Number a, b;
	scanf("%d.%d.%d %d.%d.%d", &a.ga, &a.si, &a.kn, &b.ga, &b.si, &b.kn);
	Number c = add(a, b);
	cout << c.ga << "." << c.si << "." << c.kn << endl;
	return 0;
}
