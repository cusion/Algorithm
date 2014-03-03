#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Player {
	int id;
	int weight;
	Player(){id=0,weight=-1;}
	Player(int i, int w):id(i),weight(w){}
};

void calRank(vector <Player> &players, vector<int> &order, int group) {
	if (players.empty() || group <= 0) {
		return;
	}
	vector <Player> cur(players.size());
	vector <Player> pre;
	
	for (int i = 0; i < order.size(); ++i) {
		cur[i] = players[order[i]];
	}
	
	/*for (int i = 0; i < cur.size(); ++i) {
		cout << cur[i].weight << " ";
	}puts("");
	system("pause");*/
	
	vector <int> rankIndx(players.size());
	vector <int> roundCount;
	
	int maxWeight = -1;
	int maxIndx = 0;
	while (cur.size() > group) {
		maxWeight = -1;
		maxIndx = 0;
		for (int i = 0; i < cur.size(); ++i) {
			rankIndx[cur[i].id] = roundCount.size();
			if (maxWeight < cur[i].weight) {
				maxWeight = cur[i].weight;
				maxIndx = i;
			}
			if ((i%group) == (group-1) || (i == cur.size()-1)) {
				pre.push_back(cur[maxIndx]);
				maxWeight = -1;
				maxIndx = i+1;
			}
		}
		roundCount.push_back(pre.size());
		
		cur = pre;
		pre.clear();
	}
	
	maxWeight = -1;
	maxIndx = 0;
	for (int i = 0; i < cur.size(); ++i) {
		rankIndx[cur[i].id] = roundCount.size();
		if (maxWeight < cur[i].weight) {
			maxWeight = cur[i].weight;
			maxIndx = i;
		}
	}
	roundCount.push_back(1);
	rankIndx[cur[maxIndx].id] = roundCount.size();
	roundCount.push_back(0);
	
	cout << roundCount[rankIndx[0]]+1;
	for (int i = 1; i < players.size(); ++i) {
		cout << " " << roundCount[rankIndx[i]]+1;
	}puts("");
	
	return ;
}

int main() {
	int n,g;
	cin >> n >> g;
	vector <Player> players;
	for (int i = 0; i < n; ++i) {
		int weight;
		cin >> weight;
		players.push_back(Player(i, weight));
	}
	vector <int> order;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		order.push_back(tmp);
	}
	calRank(players, order, g);
	return 0;
}
