#include <cstdio>
#include <iostream>
using namespace std;
#define MAX 100005

int fa[MAX];
int arr[MAX];
bool visit[MAX];
int n;

int father(int x)
{
	if (fa[x] != x) {
		fa[x] = father(fa[x]);
	}
	return fa[x];
}

void merge(int x, int y)
{
	if (x != y) {
		int fx = father(x);
		int fy = father(y);
		fa[fy] = fx;
	}
}

int main()
{
	/* method 1
	scanf("%d", &n);
	int pseudo = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		if (i == arr[i])pseudo++;
		fa[i] = i;
		visit[i] = false;
	}
	if (pseudo == n) {
		puts("0");
		return 0;
	}
	int cnt = 0;
	int zero = 1;
	if (arr[0] == 0) {
		zero--;
	}
	for (int i = 0; i < n; ++i) {
		merge(i, arr[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (visit[father(i)] == false) {
			visit[father(i)] = true;
			cnt++;
		}
	}
	//cout << cnt << " " << pseudo << " " << zero << endl;
	printf("%d\n", cnt+n-2*pseudo-2*zero);
	*/
	/////////// method 2 ///////////////
	scanf("%d", &n);
	int pseudo = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		visit[i] = false;
		if (arr[i] == i)pseudo++;
	}
	if (pseudo == n) {
		puts("0");
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int step = 0;
		int detect = i;
		while (visit[detect]==false) {
			visit[detect] = true;
			detect = arr[detect];
			step++;
		}
		if (step > 1) {
			cnt++;
		}
	}
	int zero = 1;
	if (arr[0] == 0)zero--;

	printf("%d\n", cnt+n-pseudo - 2*zero);

	return 0;
}
