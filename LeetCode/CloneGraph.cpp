#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/************** copy on the way *************
UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node) {
	if (node == NULL) {
		return NULL;
	}
	unordered_map <int, UndirectedGraphNode *> visit;
	queue <UndirectedGraphNode *> q;
	queue <UndirectedGraphNode **> cq;
	UndirectedGraphNode * start = NULL;
	q.push(node);
	cq.push(&start);
	while (!q.empty()) {
		UndirectedGraphNode * p = q.front();
		UndirectedGraphNode ** cp = cq.front();
		q.pop(),cq.pop();
		if (visit.find(p->label) != visit.end()) {
			*cp = visit[p->label];
			continue;
		}
		*cp = new UndirectedGraphNode(p->label);
		visit.insert(pair<int, UndirectedGraphNode *>(p->label, *cp));
		(*cp)->neighbors = vector <UndirectedGraphNode *>(p->neighbors.size(), NULL);
		for (int i = 0; i < p->neighbors.size(); ++i) {
			q.push(p->neighbors[i]);
			cq.push(&((*cp)->neighbors[i]));
		}
	}
	
	return start;
}*/

/************* copy afterwards ****************/
UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node) {
	if (node == NULL) {
		return NULL;
	}
	unordered_map <int, UndirectedGraphNode *> nodeMap;
	queue <UndirectedGraphNode*> q;
	q.push(node);
	
	// generate node
	while (!q.empty()) {
		UndirectedGraphNode *p = q.front();
		q.pop();
		
		if (nodeMap.find(p->label) != nodeMap.end()) {
			continue;
		}
		UndirectedGraphNode *tmp = new UndirectedGraphNode(p->label);
		nodeMap.insert(pair<int, UndirectedGraphNode*>(p->label, tmp));
		
		for (int i = 0; i < p->neighbors.size(); ++i) {
			q.push(p->neighbors[i]);
		}
	}
	
	// fill the neighbors
	unordered_set<int> visit;
	q.push(node);
	while (!q.empty()) {
		UndirectedGraphNode *p = q.front();
		q.pop();
		
		if (visit.find(p->label) != visit.end()) {
			continue;
		}
		visit.insert(p->label);
		
		for (int i = 0; i < p->neighbors.size(); ++i) {
			int neighborId = p->neighbors[i]->label;
			nodeMap[p->label]->neighbors.push_back(nodeMap[neighborId]);
			q.push(p->neighbors[i]);
		}
	}
	
	return nodeMap[node->label];
}

int main() {
	UndirectedGraphNode p(0);
	p.neighbors.push_back(&p);
	p.neighbors.push_back(&p);
	UndirectedGraphNode *start = cloneGraph(&p);
	cout << start->label << endl;
	for (int i = 0 ;i < start->neighbors.size(); ++i) {
		cout << start->neighbors[i]->label << endl;
	}
	return 0;
}
