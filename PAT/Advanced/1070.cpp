#include <cstdio>
#include <iostream>
#include <algorithm>

#define eps 1e-10

using namespace std;

struct Product{
	double inventory;
	double price;

	friend bool operator < (Product a, Product b) {
		return a.price/a.inventory > b.price/b.inventory;
	}
};

int main()
{
	int n, amount;
	cin >> n >> amount;
	Product products[n];
	for (int i = 0; i < n; ++i) {
		cin >>products[i].inventory;
	}
	for (int i = 0; i < n; ++i) {
		cin >> products[i].price;
	}
	sort(products, products+n);
	
	double profit = 0;

	for (int i = 0; i < n; ++i) {
		if (products[i].inventory <= amount) {
			profit += products[i].price;
			amount = amount - products[i].inventory;
		} else {
			profit += amount / products[i].inventory * products[i].price;
			amount = 0;
		}
		if (amount <= eps) break;
	}

	printf("%.2lf\n", profit);

	/*for (int i = 0; i < n; ++i) {
		cout << products[i].inventory << " " << products[i].price << endl;
	}*/
	
	return 0;
}
