#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode * buildRandomList() {
	srand(time(0));
	int num = rand()%10 + 1;
	RandomListNode * pHead = new RandomListNode(0);
	RandomListNode * pCur = pHead;
	for (int i = 1; i < num; ++i) {
		pCur->next = new RandomListNode(i);
		pCur = pCur->next;
	}
	pCur = pHead;
	for (int i = 0; i < num; ++i) {
		int sib = rand()%num - num/3;
		if (sib < 0) {
			pCur->random = NULL;
		} else {
			sib = rand()%num;
			RandomListNode * pSibCur = pHead;
			while (sib--) {
				pSibCur = pSibCur->next;
			}
			pCur->random = pSibCur;
		}
		pCur = pCur->next;
	}
	
	return pHead;
}

void deleteRandomList(RandomListNode *pHead) {
	if (pHead == NULL) return;
	
	deleteRandomList(pHead->next);
	delete pHead;
	
	return;
}

void printList(RandomListNode * pHead) {
	RandomListNode * pCur = pHead;
	while (pCur) {
		cout << pCur->label << " ";
		if (pCur->next) cout << pCur->next->label << " ";
		if (pCur->random) cout << pCur->random->label << " ";
		puts("");
		
		pCur = pCur->next;
	}
}

/*************************  Method 1 **************************
RandomListNode * copyRandomList(RandomListNode * pHead) {
	RandomListNode * pCur = pHead;
	while (pCur) {
		RandomListNode *pCurNext = pCur->next;
		
		pCur->next = new RandomListNode(pCur->label);
		pCur->next->next = pCurNext;
		
		pCur = pCurNext;
	}
	
	pCur = pHead;
	
	while (pCur) {
		pCur->next->random = pCur->random == NULL ? NULL : pCur->random->next;
		pCur = pCur->next->next;
	}
	
	RandomListNode * ret = pHead->next;
	pCur = pHead;
	RandomListNode * rpCur = ret;
	while (rpCur) {
		pCur->next = pCur->next->next;
		if (rpCur->next != NULL) {
			rpCur->next = rpCur->next->next;
		}
		
		pCur = pCur->next;
		rpCur = rpCur->next;
	}
	
	return ret;
}
*/

RandomListNode * copyRandomList(RandomListNode * pHead) {
	unordered_map <RandomListNode *, RandomListNode *> umap;
	
	RandomListNode * ret = NULL;
	
	if (pHead) {
		ret = new RandomListNode(pHead->label);
		umap.insert(pair<RandomListNode *, RandomListNode *>(pHead, ret));
	} else {
		return NULL;
	}
	
	RandomListNode * pCur = pHead->next;
	RandomListNode * rpCur = ret;
	while (pCur) {
		rpCur->next = new RandomListNode(pCur->label);
		umap.insert(pair<RandomListNode *, RandomListNode *>(pCur, rpCur->next));
		
		pCur = pCur->next;
		rpCur = rpCur->next;
	}
	
	rpCur = ret;
	pCur = pHead;
	while (pCur) {
		if (pCur->random == NULL) {
			rpCur->random = NULL;
		} else {
			rpCur->random = umap[pCur->random];
		}
		pCur = pCur->next;
		rpCur = rpCur->next;
	}
	
	return ret;
}

int main () {
	RandomListNode * rdList = buildRandomList();
	printList(rdList);
	puts("====================");
	RandomListNode * cpList = copyRandomList(rdList);
	printList(cpList);
	deleteRandomList(rdList);
	deleteRandomList(cpList);
	
	return 0;
}
