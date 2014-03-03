#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval(){}
	Interval(int s, int e):start(s), end(e){}
};

void getPaymentSolution(int arr[], int len, int tar, vector<Interval> &sol, int mini) {
	int start = 0, end = 0;
	int sum = arr[0];
	while (start < len) {
		if (sum < tar) {
			if (end >= len-1) {
				break;
			} else {
				++end;
				sum += arr[end];
			}
		} else if (sum >= tar) {
			//cout << sum << endl;
			if (mini+tar > sum) {
				//puts("min");
				mini = sum - tar;
				if (!sol.empty()){
					sol.clear();
				}
				sol.push_back(Interval(start+1, end+1));
			} else if (mini + tar == sum) {
				//puts("test");
				sol.push_back(Interval(start+1, end+1));
			}
			sum -= arr[start];
			++start;
		}
	}
	
	return ;
}

int main() {
	int n, m;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	vector <Interval> res;
	int minimum = 0x3fffffff;
	getPaymentSolution(arr, n, m, res, minimum);
	
	for (int i = 0; i < res.size(); ++i) {
		//cout << res[i].start << "-" << res[i].end << endl;
		printf("%d-%d\n", res[i].start, res[i].end);
	}
	
	return 0;
}
