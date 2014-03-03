#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode * head) {
	ListNode *cur = head;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	puts("");
}

bool hasCycle(ListNode *head, ListNode* &nodeInCycle) {
	if (head == NULL) {
		return false;
	}
	ListNode *slow = head;
	ListNode *fast = head->next;
	while (fast && fast->next) {
		if (fast == slow) {
			nodeInCycle = fast;
			return true;
		} else {
			slow = slow->next;
			fast = fast->next->next;
		}
	}
	
	return false;
}

ListNode * firstCommonNode(ListNode *ahead, ListNode *bhead) {
	if (ahead==NULL || bhead==NULL) {
		return NULL;
	}
	int lena = 0;
	ListNode * acur = ahead;
	while (acur) {
		++lena;
		acur = acur->next;
	}
	int lenb = 0;
	ListNode *bcur = bhead;
	while(bcur) {
		++lenb;
		bcur = bcur->next;
	}
	acur = ahead;
	bcur = bhead;
	//cout << lena << " -> ";
	//printList(acur);
	//cout << lenb << " -> ";
	//printList(bcur);
	if (lena > lenb) {
		for (int i = 0; i < lena-lenb; ++i) {
			acur = acur->next;
		}
	} else if (lenb > lena) {
		for (int i = 0; i < lenb-lena; ++i) {
			bcur = bcur->next;
		}
	}
	
	while (acur != bcur) {
		acur = acur->next;
		bcur = bcur->next;
	}
	
	return acur;
}


ListNode *detectCycle(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return NULL;
	}
	
	ListNode *nodeInCycle = NULL;
	if (!hasCycle(head, nodeInCycle)) {
		return NULL;
	}
	//cout << "returned Node " << nodeInCycle->val << " next " << nodeInCycle->next->val << endl;
	ListNode * chead = nodeInCycle->next;
	nodeInCycle->next = NULL;
	//printList(head);
	//printList(chead);
	
	return firstCommonNode(head, chead);
}

int main() {
	ListNode *vhead = new ListNode(0);
	int n;
	cin >> n;
	ListNode *cur = vhead;
	for (int i = 0; i < n; ++i) {
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	int cycleIndx;
	cin >> cycleIndx;
	ListNode * cycle = vhead->next;
	for (int i = 0; i < cycleIndx; ++i) {
		cycle = cycle->next;
	}
	cout << "Should be " << cycle->val << endl;
	cur->next = cycle;
	if (cur = detectCycle(vhead->next)) {
		cout << "Actually is " << cur->val << endl;
	} else {
		cout << "Not A cycle" << endl;
	}
	return 0;
}
