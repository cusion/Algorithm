#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode *head) {
	if (head == NULL || head->next==NULL || head->next->next==NULL) {
		return ;
	}
	
	stack <ListNode*> pStack;
	
	ListNode *pCur = head;
	while (pCur) {
		pStack.push(pCur);
		pCur = pCur->next;
	}
	
	ListNode* pNext = head->next;
	pCur = head;
	int num = pStack.size();
	while ((pStack.size()-1)*2 >= num) {
		ListNode* pTmp = pStack.top();
		pStack.pop();
		
		pNext = pCur->next;
		pCur->next = pTmp;
		pCur = pCur->next;
		pCur->next = pNext;
		
		pCur = pNext;
	}
	pCur->next = NULL;
	
	return;
}

int main() {
	return 0;
}
