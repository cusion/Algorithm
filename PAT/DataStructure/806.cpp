#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define MAX 104

struct Node {
	int a, b;
	int cost;
	
	bool friend operator < (Node a, Node b) {
		return a.cost > b.cost;
	}
};

int fa[MAX];

int father(int x) {
	return fa[x] == x ? fa[x] : (fa[x]=father(fa[x]));
}

int merge(int x, int y) {
	int fx = father(x);
	int fy = father(y);
	if (fx != fy) {
		fa[fy] = fx;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	priority_queue <Node> q;
	for (int i = 0; i < n*(n-1)/2; ++i) {
		int a, b, cost, status;
		scanf("%d%d%d%d", &a, &b, &cost, &status);
		Node tmp;
		tmp.a = a-1;
		tmp.b = b-1;
		tmp.cost = status ? 0 : cost;
		
		q.push(tmp);
	}
	
	for(int i = 0; i < n; ++i) {
		fa[i] = i;
	}
	
	int sum = 0;
	
	for (int i = 0; i < n-1; ++i) {
		Node tmp = q.top();
		q.pop();
		int x = tmp.a;
		int y = tmp.b;
		int fx = father(x);
		int fy = father(y);
		while (fx == fy) {
			tmp = q.top();
			q.pop();
			x = tmp.a;
			y = tmp.b;
			fx = father(x);
			fy = father(y);
		}
		sum += tmp.cost;
		merge(x, y);
	}
	
	printf("%d\n", sum);
	
	return 0;
}
