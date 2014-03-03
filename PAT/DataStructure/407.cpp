#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int cost(priority_queue <int, vector<int>, greater<int> > p) {
	int ret = 0;
	while (p.size() >= 2) {
		int p1 = p.top();
		p.pop();
		int p2 = p.top();
		p.pop();
		ret += p1 + p2;
		p.push(p1+p2);
	}

	return ret;
}

int main()
{
	int N;
	priority_queue <int, vector <int>, greater<int> > parts;
	cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		parts.push(tmp);
	}

	cout << cost(parts) << endl;

	return 0;
}
