#include <cstdio>
#include <iostream>

using namespace std;

struct Node {
	int k1;
	int k2;
	int left;
	int right;
}node[1005];

bool compare1(int a, int b) {
	return a < b;
}

bool compare2(int a, int b) {
	return a > b;
}

bool _isCartesian(int root, int &k1lmt, int k2lmt, bool (*comparek1)(int, int), bool (*comparek2)(int, int)) {
	if (root == -1) return true;
	bool left = true;
	if (node[root].left != -1) {
		left = _isCartesian(node[root].left, k1lmt, node[root].k2, comparek1, comparek2);
	}
	if (!comparek1(k1lmt, node[root].k1) || !comparek2(node[root].k2, k2lmt)) {
		return false;
	} else {
		k1lmt = node[root].k1;
	}
	bool right = true;
	if (node[root].right != -1) {
		right = _isCartesian(node[root].right, k1lmt, node[root].k2, comparek1, comparek2);
	}

	return left && right;
}

bool isCartesian(int root, bool (*comparek1)(int, int), bool (*comparek2)(int , int)) {
	if (root == -1) return true;

	int k1lmt = 0x80000000;
	int k2lmt = 0x80000000;
	if (_isCartesian(root, k1lmt, k2lmt, comparek1, comparek2)) {
		return true;
	}
	return false;
}

int main()
{
	int n;
	bool used[1005];
	cin >> n;
	for (int i = 0; i < n; ++i)used[i] = false;
	for (int i = 0; i < n; ++i) {
		cin >> node[i].k1 >> node[i].k2 >> node[i].left >> node[i].right;
		if (node[i].left != -1) used[node[i].left] = true;
		if (node[i].right != -1) used[node[i].right] = true;
	}
	int root = -1;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			root = i;
			break;
		}
	}

	if (isCartesian(root, &compare1, &compare2)) puts("YES");
	else puts("NO");

	return 0;
}
