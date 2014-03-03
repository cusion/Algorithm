#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle (ListNode *head) {
	if (head == NULL || head->next == NULL) return false;
	ListNode * fast = head->next;
	ListNode * slow = head;
	
	while (1) {
		if (fast == NULL || fast->next == NULL) return false;
		if (fast == slow) return true;
		slow = slow->next;
		fast = fast->next->next;
	}
}

int main() {
	return 0; 
}
