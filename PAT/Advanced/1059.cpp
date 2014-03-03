#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Comp {
	int base;
	int exp;
	Comp(){}
	Comp(int b, int e):base(b), exp(e) {}
};

vector <Comp> primeFactors(int n) {
	vector<Comp> ret;
	if (n <= 3) {
		ret.push_back(Comp(n,1));
		return ret;
	}
	
	for (int i = 2; i*i <= n; ++i) {
		if ((n%i) == 0) {
			int base = i;
			int exp = 0;
			while ((n%i)==0) {
				++exp;
				n /= i;
			}
			ret.push_back(Comp(base, exp));
		}
	}
	if (n > 1) {
		ret.push_back(Comp(n, 1));
	}
	
	return ret;
}

int main() {
	int n;
	cin >> n;
	vector<Comp> ret = primeFactors(n);
	
	cout << n << "=" << ret[0].base;
	if (ret[0].exp > 1) {
		cout << "^" << ret[0].exp;
	}
	for (int i = 1; i < ret.size(); ++i) {
		cout << "*" << ret[i].base;
		if (ret[i].exp > 1) {
			cout << "^" << ret[i].exp;
		}
	}
	puts("");
	return 0;
}
