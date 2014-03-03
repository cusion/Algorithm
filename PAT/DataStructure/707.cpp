#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define REG 105

struct Node {
	long long id;
	int record;
	int regionId;
	
	bool friend operator < (Node a, Node b) {
		if (a.record > b.record) return true;
		else if (a.record == b.record) {
			return a.id < b.id;
		} else return false;
	}
}node[105*305];

int regRank[REG], regRec[REG], regSameCnt[REG];

int main () {
	int n, total = 0;
	scanf("%d", &n);
	int candCnt = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		total += k;
		for (int j = 0; j < k; ++j) {
			scanf("%lld%d", &node[candCnt].id, &node[candCnt].record);
			node[candCnt].regionId = i+1;
			candCnt++;
		}
	}
	
	sort(node, node+candCnt);
	
	printf("%d\n", total);
	
	int preRecord = -1, preRank = 0, preSameCnt = 1;
	for (int i = 0; i < REG; ++i) {
		regRec[i] = -1;
		regSameCnt[i] = 1;
		regRank[i] = 0;
	}
	for (int i = 0; i < candCnt; ++i) {
		int finalRank, regionRank;
		int regionId = node[i].regionId;
		
		if (regRec[regionId] != node[i].record) {
			regRec[regionId] = node[i].record;
			regRank[regionId] += regSameCnt[regionId];
			regSameCnt[regionId] = 1;
		} else {
			regSameCnt[regionId]++;
		}
		regionRank = regRank[regionId];
		
		if (node[i].record != preRecord) {
			preRank += preSameCnt;
			preSameCnt = 1;
			preRecord = node[i].record;
		} else {
			preSameCnt++;
		}
		finalRank = preRank;
		printf("%013lld %d %d %d\n", node[i].id, finalRank, node[i].regionId, regionRank);
	}
	
	return 0;
}
