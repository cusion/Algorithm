#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int id;
	double price;
	Node(int i, double p):id(i), price(p) {
	}
};

double bfs(vector<vector<int> > &adj, double priceUnit, double percentage) {
	if (adj.empty()) {
		return 0;
	}
	queue <Node> q;
	q.push(Node(0, priceUnit));
	double totalSum = 0.0;
	while (!q.empty()) {
		Node nod = q.front();
		q.pop();
		if (adj[nod.id][0] == 0) {
			totalSum += adj[nod.id][1]*nod.price;
		} else {
			for (int i = 1; i < adj[nod.id].size(); ++i) {
				q.push(Node(adj[nod.id][i], nod.price*(1+percentage/100)));
			}
		}
	}
	return totalSum;
}

int main() {
	int n;
	double priceUnit, percentage;
	cin >> n >> priceUnit >> percentage;
	vector<vector<int> > adj(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		int k, tmp;
		scanf("%d", &k);
		adj[i].push_back(k);
		if (k == 0) {
			scanf("%d", &tmp);
			adj[i].push_back(tmp);
		} else {
			for (int j = 0; j < k; ++j) {
				scanf("%d", &tmp);
				adj[i].push_back(tmp);
			}
		}
	}
	printf("%.1f\n", bfs(adj, priceUnit, percentage));
	return 0;
}
