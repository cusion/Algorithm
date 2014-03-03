#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool isValid = true;

int find_last_k(vector <int> a, int k) {
	if (k<=0 || a.empty() || a.size() < k) {
		isValid = false;
		return -1;
	}
	return a[a.size()-k];
}

int main()
{
	int k, tmp;
	vector <int> arr;
	scanf("%d", &k);
	while ((scanf("%d", &tmp))&&(tmp>=0)) {
		arr.push_back(tmp);
	}
	int ret = find_last_k(arr, k);
	if (isValid) {
		printf("%d\n", ret);
	} else {
		puts("NULL");
	}

	return 0;
}
