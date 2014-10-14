#include <cstdio>
#include <iostream>
using namespace std;

int divide(int divident, int divisor) {
	if (divisor == 0) {
		return 0x7fffffff;
	}
	bool isNeg = ((divident>>31)^(divisor>>31));
	long long dividentLL = divident;
	dividentLL = dividentLL > 0 ? dividentLL : -dividentLL;
	long long divisorLL = divisor;
	divisorLL = divisorLL > 0 ? divisorLL : -divisorLL;
	int ret = 0;
	if (divisorLL <= dividentLL) {
		long long tmpDivisor = divisorLL;
		int cnt = 0;
		while (tmpDivisor > 0 && tmpDivisor <= dividentLL) {
			tmpDivisor <<= 1;
		}
		
		while (tmpDivisor >= divisorLL) {
			ret <<= 1;
			if (tmpDivisor <= dividentLL) {
				ret |= 1;
				dividentLL -= tmpDivisor;
			}
			tmpDivisor >>= 1;
		}
	}
	
	return isNeg ? -ret : ret;
}

int main() {
	cout << divide(-1010369383, -2147483648) << endl;
	return 0;
}
