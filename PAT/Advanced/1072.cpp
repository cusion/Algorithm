#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
#define INF 0x3fffffff
struct Node {
	int dist;
	int id;
	Node(){}
	Node(int i, int d):id(i),dist(d){}
	
	friend bool operator < (Node a, Node b) {
		return a.dist > b.dist;
	}
}nod1, nod2;

struct Result {
	int id;
	double minimum;
	double avg;
	Result(){}
	Result(int i, double m, double a):id(i), minimum(m), avg(a){}
};

Result dijkstra(int src, int houseNum, vector<vector<Node> > &adj, int range) {
	int dist[adj.size()];
	bool visit[adj.size()];
	for (int i = 0; i < adj.size(); ++i) {
		dist[i] = INF;
		visit[i] = false;
	}
	dist[src] = 0;
	nod1.dist = 0;
	nod1.id = src;
	priority_queue<Node> q;
	q.push(nod1);
	
	while (!q.empty()) {
		nod1 = q.top();
		q.pop();
		int cur = nod1.id;
		if (visit[cur]) {
			continue;
		}
		visit[cur] = true;
		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i].id;
			if (dist[next] > dist[cur] + adj[cur][i].dist) {
				dist[next] = dist[cur] + adj[cur][i].dist;
				nod2.id = next;
				nod2.dist = dist[next];
				q.push(nod2);
			}
		}
	}
	
	/*puts("========================");
	cout << src << endl;
	for (int i = 0; i < adj.size(); ++i) {
		cout << dist[i] << " ";
	}puts("");*/
	
	double minimum = INF, avg = 0;
	for (int i = 0; i < houseNum; ++i) {
		if (dist[i] > range) {
			avg = -1;
			minimum = -1;
			break;
		} else {
			minimum = minimum > dist[i] ? dist[i] : minimum;
			avg += dist[i];
		}
	}
	
	return Result(src, minimum, avg/houseNum);
}

int str2num(char str[], int houseNum) {
	if (str[0] == 'G') {
		return houseNum + str2num(&str[1], houseNum);
	} else {
		int ret = 0;
		for (int i = 0; str[i] != '\0'; ++i) {
			ret = ret*10 + str[i] - '0';
		}
		return ret-1;
	}
}

int main()
{
	int n, m, k, ds;
	cin >> n >> m >> k >> ds;
	vector <vector<Node> > adj(n+m);
	char num1[8], num2[8];
	int dist;
	for (int i = 0; i < k; ++i) {
		scanf("%s%s%d", num1, num2, &dist);
		int a = str2num(num1, n);
		int b = str2num(num2, n);
		//cout << a << " " << b << endl;
		adj[a].push_back(Node(b, dist));
		adj[b].push_back(Node(a, dist));
	}
	/*for (int i = 0; i < adj.size(); ++i) {
		cout << i << " -> ";
		for (int j = 0; j < adj[i].size(); ++j) {
			cout << adj[i][j].id << " " << adj[i][j].dist << " -> ";
		}puts("");
	}*/
	Result final(-1, 0, 0);
	for (int src = 0; src < m; ++src) {
		Result res = dijkstra(src+n, n, adj, ds);
		if (res.minimum > 0 && (final.id == -1 || final.minimum <= res.minimum)) {
			if (final.minimum == res.minimum) {
				if (final.avg > res.avg) {
					final = res;
				}
			} else {
				final = res;
			}
		}
	}
	
	if (final.id == -1) {
		cout << "No Solution" << endl;
	} else {
		cout << "G" << final.id-n+1 << endl;
		printf("%.1f %.1f\n", final.minimum, final.avg);
	}
}
