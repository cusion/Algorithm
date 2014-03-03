#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include <cstdlib>

using namespace std;
#define MAXCUST 10005
#define MAXWINDOW 1005
#define MAXPROCESS 10
#define MAXPROCESSTIME 60

struct Person {
	int arriveTime;
	int processTime;
	int processedTime;
}person[MAXCUST];

list <int> preWait;      //Person preWait[MAXCUST];
list <int> wait;         //Person wait[MAXCUST];
list <int> process[MAXWINDOW];  //Person process[MAXWINDOW][MAXPROCESS];
int waitTime[MAXCUST];

//int preWaitIndx, waitLen, processLen[MAXWINDOW], preTime, curTime;
int curTime;

bool processedAll(int windows) {
	for (int i = 0; i < windows; ++i) {
		if (process[i].size() > 1) return false;
	}
	return true;
}

void customToWait(int curTime) {
	if (!preWait.empty()){
		int personId = preWait.front();
		while (person[personId].arriveTime <= curTime) {
			wait.push_back(personId);
			preWait.pop_front();
			if (preWait.empty()) {
				break;
			}
			personId = preWait.front();
		}
	}
}

void customChooseWindow(int windows, int maxProcess) {
	vector <int> windowAvail;
	int minNum = maxProcess;
	
	for (int i = 0; i < windows; ++i){
		if (process[i].size() < minNum) {
			minNum = process[i].size();
		}
	}
	
	for (int i = minNum; i < maxProcess && windowAvail.size() <= wait.size(); ++i) {
		for (int j = 0; j < windows; ++j) {
			if (process[j].size() <= i) {
				windowAvail.push_back(j);
			}
		}
	}
	
	int windowInd = 0;
	while (!wait.empty() && windowInd < windowAvail.size()) {
		int personId = wait.front();
		process[windowAvail[windowInd]].push_back(personId);
		wait.pop_front();
		++windowInd;
	}
}

void customToProcess(int curTime, int windows) {
	for (int i = 0; i < windows; ++i) {
		if (!process[i].empty()) {
			int personId = process[i].front();
			if (person[personId].processedTime == 0) {
				waitTime[personId] = curTime - person[personId].arriveTime;
			}
			++person[personId].processedTime;
		}
	}
}

void timeElapse(int &time) {
	++time;
}

void personLeave(int windows) {
	for (int i = 0; i < windows; ++i) {
		if (!process[i].empty()){
			int beingProcessed = process[i].front();
			if (person[beingProcessed].processTime 
			 == person[beingProcessed].processedTime) {
				process[i].pop_front();
			}
		}
	}
}

void printState(int curTime, int n, int windows) {
	
	cout << curTime << endl;
	
	list <int>::iterator itr;
	puts("############## preWait #############");
	for (itr = preWait.begin(); itr != preWait.end(); ++itr) {
		printf("%d ", (*itr));
	}puts("");
	
	puts("############## wait ###############");
	for (itr = wait.begin(); itr != wait.end(); ++itr) {
		printf("%d ", (*itr));
	}puts("");
	
	puts("############## Windows ##############");
	for (int i = 0; i < windows; ++i) {
		if (!process[i].empty()) {
			printf("window %d: ", i);
			for (itr = process[i].begin(); itr != process[i].end(); ++itr) {
				printf("%d ", (*itr));
			}puts("");
		}
	}
	
	puts("############# Wait Time ##############");
	for (int i = 0; i < n; ++i) {
		printf("%d ", waitTime[i]);
	}puts("");
	system("pause");
}

int main() {
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < n; ++i) {
		int arr, pro;
		scanf("%d%d", &arr, &pro);
		if (pro > MAXPROCESSTIME) pro = MAXPROCESSTIME;
		person[i].arriveTime = arr;
		person[i].processTime = pro;
		person[i].processedTime = 0;
		
		preWait.push_back(i);
	}
	
	curTime = 0;
	for (int i = 0; i < n; ++i) {
		waitTime[i] = 0;
	}
	
	while (!preWait.empty() || !wait.empty() || !processedAll(k)) {
		//puts("===================================");
		personLeave(k);
		customToWait(curTime);
		customChooseWindow(k, m);
		customToProcess(curTime, k);               // calculate its wait time until it is being processed
		//printState(curTime, n, k);
		timeElapse(curTime);
		//puts("************************************");
	}
	
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += waitTime[i];
	}
	
	printf("%f\n", 1.0*sum/n);
	
	return 0;
}
