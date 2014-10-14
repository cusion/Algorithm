#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isNull(ListNode * node) {
	return node == NULL;
}
 
 struct cmp {
 	bool operator ()(const ListNode * a, const ListNode * b) {
 		return a->val > b->val;
 	}
 };
 
ListNode * getMinimum(vector<ListNode*> &lists, priority_queue<ListNode *, vector<ListNode *>, cmp> &q) {
	if (q.empty()) {
		return NULL;
	}
	ListNode * ret = q.top();
	q.pop();
	if (ret->next) {
		q.push(ret->next);
	}
	return ret;
}
 
 ListNode *mergeKLists(vector<ListNode *> &lists) {
 	ListNode * cur = NULL;
 	if (lists.empty()) {
 		return cur;
 	}
 	priority_queue <ListNode *,
	vector<ListNode *>, cmp> q;
 	ListNode * vhead = new ListNode(0);
 	for (int i = 0; i < lists.size(); ++i) {
 		if (lists[i] != NULL) {
 			q.push(lists[i]);
 		}
 	}
 	cur = vhead;
 	while ((cur->next = getMinimum(lists, q)) != NULL) {
 		cur = cur->next;
 	}
 	
 	cur = vhead->next;
 	delete vhead;
 	return cur;
 }
 
 int main() {
 	vector <ListNode *> lists;
 	lists.push_back(new ListNode(1));
 	lists.push_back(new ListNode(2));
 	lists[0]->next = new ListNode(3);
 	lists[1]->next = new ListNode(4);
 	ListNode * ret = mergeKLists(lists);
 	ListNode * cur = ret;
 	while (cur) {
 		cout << cur->val << " ";
 		cur = cur->next;
 	}
 	return 0;
 }
