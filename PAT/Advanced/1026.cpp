#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define S 8*60*60
#define E 21*60*60
#define INF 0x7fffffff

#define max(a, b) ((a)>(b)?(a):(b))

struct Person {
	int arrive;          // arrive time in seconds
	int priori;          // priority of that customer, 0 for ordinary, 1 for VIP
	int needTime;        // time to play in seconds
	Person(){}
	Person(int a, int p):arrive(a), priori(p){}
};

struct Result {
	int arrive;
	int start;
	int tableId;
	Result(){}
	Result(int a, int s, int t):arrive(a), start(s), tableId(t){}
};

bool cmpArrTime(const Person &a, const Person &b) {
	return a.arrive < b.arrive;
}

bool cmpStartTime(const Result &a, const Result &b) {
	return a.start < b.start;
}

void formatTime(int time, char arr[]) {
	int h, m, s;
	s = time%60;
	m = (time/60)%60;
	h = (time/3600);
	arr[0] = h/10 + '0';
	arr[1] = h%10 + '0';
	arr[2] = ':';
	arr[3] = m/10 + '0';
	arr[4] = m%10 + '0';
	arr[5] = ':';
	arr[6] = s/10 + '0';
	arr[7] = s%10 + '0';
	arr[8] = '\0';
}

int wait(Result &res) {
	return (int)((res.start-res.arrive)*1.0/60 + 0.5);
}

int main() {
	int n;
	cin >> n;
	Person players[n];
	int needTime[n];
	vector<Result> res;
	for (int i = 0; i < n; ++i) {
		int h, m, s, needTime, priori;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &needTime, &priori);
		players[i].arrive = (h*60+m)*60+s;
		players[i].priori = priori;
		if (needTime > 120) needTime = 120;
		players[i].needTime = needTime*60;
	}
	int m, vip;
	cin >> m >> vip;
	vector<bool> isVip(m, false);
	vector<int> table(m, S);
	for (int i = 0; i < vip; ++i) {
		int tmp;
		scanf("%d", &tmp);
		isVip[tmp-1] = true;
	}
	sort(players, players+n, cmpArrTime);
	vector<bool> isServed(n, false);
	for (int i = 0; i < n; ++i) {
		if (isServed[i]) {
			continue;
		}
		if (players[i].arrive >= E) break;
		int toServe = i;
		int minTime = INF;
		int minInd = -1;
		for (int j = 0; j < m; ++j) {
			// if find the neareast availble table, then choose it
			// otherwise would wait until the earliest table
			if (players[i].arrive >= table[j]) {
				minTime = table[j];
				minInd = j;
				break;
			} else if (minTime > table[j]) {
				minTime = table[j];
				minInd = j;
			}
		}
		
		//cout << minInd << " " << minTime << endl;
		//system("pause");
		// if is vip customer and has vip table
		if (players[i].priori > 0) {
			for (int j = 0; j < m; ++j) {
				if (table[j] <= players[i].arrive && isVip[j]) {
					minInd = j;
					minTime = table[j];
					break;
				}
			}
		}
		//if is non-vip customer and table is vip
		if (players[i].priori==0 && isVip[minInd]) {     // if current table is VIP table
			for (int ts = i+1; ts < n && players[ts].arrive <= minTime; ++ts) {
				if (players[ts].priori > 0 && players[ts].arrive < E) {
					--i;    // draw back the current to be served pair
					toServe = ts;
					break;
				}
			}
		}
		isServed[toServe] = true;
		Result resTmp;
		resTmp.arrive = players[toServe].arrive;
		resTmp.start = max(minTime, resTmp.arrive);
		resTmp.tableId = minInd;
		res.push_back(resTmp);
		table[minInd] = resTmp.start + players[toServe].needTime;
		
		/*puts("=================");
		cout << minInd << " " << toServe << " ";
		char tmpTime[10];
		formatTime(table[minInd], tmpTime);
		puts(tmpTime);
		puts("=================");*/
	}
	
	sort(res.begin(), res.end(), cmpStartTime);
	vector<int> tableUsedCnt(m, 0);
	
	for (int i = 0; i < res.size(); ++i) {
		if (res[i].start < E) {
			char arrStr[10], stStr[10];
			formatTime(res[i].arrive, arrStr);
			formatTime(res[i].start, stStr);
			printf("%s %s %d\n",arrStr, stStr , wait(res[i]));
			++tableUsedCnt[res[i].tableId];
		}
	}
	for (int i = 0; i < m-1; ++i) {
		printf("%d ", tableUsedCnt[i]);
	}
	printf("%d\n", tableUsedCnt[m-1]);
	
	return 0;
}
