#include <cstdio>
#include <iostream>
#include <map>

using namespace std;
#define MAX 230

struct RankNode {
	int gold;
	int pedal;
	double avgGold;
	double avgPedal;
}rankNode[MAX];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	multimap <int, int, greater<int> > goldRank;
	multimap <int, int, greater<int> > pedalRank;
	multimap <int, int>::iterator itr1;
	multimap <double, int, greater<double> > avgGoldRank;
	multimap <double, int, greater<double> > avgPedalRank;
	multimap <double, int>::iterator itr2;
	for (int i = 0; i < n; ++i) {
		int gold, pedal, person;
		scanf("%d%d%d", &gold, &pedal, &person);
		
		rankNode[i].gold = gold;
		rankNode[i].pedal = pedal;
		rankNode[i].avgGold = 1.0*gold/person;
		rankNode[i].avgPedal = 1.0*pedal/person;
		
		goldRank.insert(pair<double, int>(gold, 0));
		pedalRank.insert(pair<double, int>(pedal, 0));
		avgGoldRank.insert(pair<double, int>(rankNode[i].avgGold, 0));
		avgPedalRank.insert(pair<double, int>(rankNode[i].avgPedal, 0));
	}
	int tmp = 1;
	//puts("gold rank");
	for (itr1 = goldRank.begin(); itr1!=goldRank.end();++itr1) {
		itr1->second = tmp++;
		//cout << itr1->first << "  " << itr1->second << endl;
	}
	
	tmp = 1;
	//puts("pedal rank");
	for (itr1 = pedalRank.begin(); itr1!=pedalRank.end(); ++itr1) {
		itr1->second = tmp++;
		//cout << itr1->first << "  " << itr1->second << endl;
	}
	
	tmp = 1;
	//puts("average gold rank");
	for (itr2 = avgGoldRank.begin();itr2 != avgGoldRank.end(); ++itr2) {
		itr2->second = tmp++;
		//cout << itr2->first << "  " << itr2->second << endl;
	}
	
	tmp = 1;
	//puts("average pedal rank");
	for (itr2 = avgPedalRank.begin(); itr2 != avgPedalRank.end(); ++itr2) {
		itr2->second = tmp++;
		//cout << itr2->first << "  " << itr2->second << endl;
	}
	
	//puts("========== DONE =============");
	
	for (int i = 0; i < m-1; ++i) {
		int query;
		scanf("%d", &query);
		
		int rank = n+1, ranktype;
		
		int tmpRank = goldRank.lower_bound(rankNode[query].gold)->second;
		if (rank > tmpRank) {
			rank = tmpRank;
			ranktype = 1;
		}
		
		tmpRank = pedalRank.lower_bound(rankNode[query].pedal)->second;
		if (rank > tmpRank) {
			rank = tmpRank;
			ranktype = 2;
		}
		
		tmpRank = avgGoldRank.lower_bound(rankNode[query].avgGold)->second;
		if (rank > tmpRank) {
			rank = tmpRank;
			ranktype = 3;
		}
		
		tmpRank = avgPedalRank.lower_bound(rankNode[query].avgPedal)->second;
		if (rank > tmpRank) {
			rank = tmpRank;
			ranktype = 4;
		}
		
		printf("%d:%d ", rank, ranktype);
	}
	
	int query;
	scanf("%d", &query);
	
	int rank = n+1, ranktype;
	
	int tmpRank = goldRank.lower_bound(rankNode[query].gold)->second;
	if (rank > tmpRank) {
		rank = tmpRank;
		ranktype = 1;
	}
	
	tmpRank = pedalRank.lower_bound(rankNode[query].pedal)->second;
	if (rank > tmpRank) {
		rank = tmpRank;
		ranktype = 2;
	}
	
	tmpRank = avgGoldRank.lower_bound(rankNode[query].avgGold)->second;
	if (rank > tmpRank) {
		rank = tmpRank;
		ranktype = 3;
	}
	
	tmpRank = avgPedalRank.lower_bound(rankNode[query].avgPedal)->second;
	if (rank > tmpRank) {
		rank = tmpRank;
		ranktype = 4;
	}
	
	printf("%d:%d\n", rank, ranktype);
	
	return 0;
}
