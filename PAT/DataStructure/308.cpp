#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

bool isAllRight = true;

class myQueue {
private:
	int headlmt, taillmt;
	stack <int> head;
	stack <int> tail;

public:
	myQueue (int n1, int n2) {
		headlmt = n1 > n2 ? n1 : n2;
		taillmt = n2 + n1 - headlmt;
	}

	void AddQ(int ele) {
		if (head.empty() && (tail.size() >= taillmt)) {
			while (!tail.empty()) {
				head.push(tail.top());
				tail.pop();
			}
			tail.push(ele);
		} else if (tail.size() < taillmt) {
			tail.push(ele);
		} else {
			puts("ERROR:Full");
		}
	}

	int DeleteQ() {
		if (head.empty()) {
			while(!tail.empty()) {
				head.push(tail.top());
				tail.pop();
			}
		}
		if (head.empty()) {
			puts("ERROR:Empty");
			isAllRight = false;
			return 0;
		} else {
			int ret = head.top();
			head.pop();
			return ret;
		}
	}
};

int main()
{
	int n1, n2;
	cin>>n1>>n2;
	myQueue queue(n1, n2);
	char opr;
	while ((cin>>opr)&&(opr!='T')) {
		if ('A' == opr) {
			int ele;
			cin >> ele;
			queue.AddQ(ele);
		} else {
			int d = queue.DeleteQ();
			if (isAllRight) {
				printf("%d\n", d);
			} else {
				isAllRight = true;           // global mark should be reset after it is used
			}
		}
	}
}
