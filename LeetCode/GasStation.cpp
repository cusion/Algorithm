#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/*************************  TLE version ****************************
bool checkValid(vector<int> &gas, vector<int> &cost, int start) {
	int sumGas = gas[start]-cost[start];
	int indx = start+1;
	while ((indx%gas.size())!=start) {
		sumGas += gas[indx]-cost[indx];
		if (sumGas < 0) {
			return false;
		}
		++indx;
	}
	return true;
}

int canCompleteCircuit(vector <int> &gas, vector<int> &cost) {
	if (gas.empty()) {
		return -1;
	}
	if (gas.size()==1 && gas[0] < cost[0]) {
		return -1;
	}
	vector <int> potentialStart;
	for (int i = 0; i < gas.size(); ++i) {
		if (gas[i] >= cost[i]) {
			potentialStart.push_back(i);
		}
	}
	
	for (int i = 0; i < potentialStart.size(); ++i) {
		if (checkValid(gas, cost, potentialStart[i])) {
			return i;
		}
	}
	return -1;
}*/

/*************** Here is a solution of mine *****************
// The main diea is to start from an arbitrary point, and presume
// the car has arrived at a next station, when it needs some gas, 
// we should move backwards the start point to find more gas to meet
// the gas demand by current situation. Why don't we move forwards?
// Cause if we could find more gas forwards, then we should not have
// been caught in the situation of lack of gas.
int canCompleteCircuit(vector <int> &gas, vector <int> &cost) {
	if (gas.empty()) {
		return -1;
	}
	if (gas.size()==1 && gas[0] < cost[0]) {
		return -1;
	}
	int start = 0;
	int gasLeft = gas[start] - cost[start];
	int cur = 1;
	while (start != cur) {
		if (gasLeft < 0) {
			int needed = -gasLeft;
			while (start != cur && needed > 0) {
				if (start == 0) {
					start = cost.size()-1;
				} else {
					--start;
				}
				needed -= gas[start] - cost[start];
			}
			if (needed > 0) return -1;
			gasLeft = -needed;
		}
		gasLeft += gas[cur] - cost[cur];
		cur = (cur+1)%(cost.size());
	}
	if (gasLeft >= 0) {
		return start;
	} else {
		return -1;
	}
}*/

// I have find an excellent explanation of this problem, e.g. it is equivalent to finding 
// the location of  maximum continuous summation of a circular sequence. Because in the 
// solution of this problem, we have keep the summation of previousely travelled nodes to
// be positive always (if positive solution exists), this is equivalent to tank of the car 
// always containing gas. On the other hand, having located the maximum summation end point, this means
// we have find the maximum gas that would left among all those travel solutions starting from any
// stations, if this solution still fails, then no solution would exists.
/******************** Original solution of above thoughts **************
int maxSubSeq(vector <int> &arr, int size, int &start, int &end) {
	int maxSum = arr[0]-1, tmpSum = -1, startPos = -1;
	int curPos = 0, curPosInArr = 0;
	while (startPos < size) {
		if (curPosInArr == startPos) break;
		if (tmpSum < 0) {
			startPos = curPos;
			tmpSum = 0;
		}
		tmpSum += arr[curPosInArr];
		if (maxSum < tmpSum) {
			maxSum = tmpSum;
			start = startPos;
			end = curPosInArr;
		}
		++curPos;
		curPosInArr = curPos % size;
	}
	
	return maxSum;
}
int canCompleteCircuit(vector <int> &gas, vector<int> &cost) {
	if (gas.empty() || gas.size() != cost.size()) {
		return -1;
	}
	vector <int> pools;
	for (int i = 0; i < gas.size(); ++i) {
		pools.push_back(gas[i]-cost[i]);
	}
	int startPos, endPos;
	int n = pools.size();
	int maxSub = maxSubSeq(pools, n, startPos, endPos);
	if (maxSum < 0) return -1;
	for (int i = (endPos+1)%n; i != startPos; i=(i+1)%n) {
		maxSub += pools[i];
		if (maxSub < 0) {
			return -1;
		}
	}
	return startPos;
}*/

// A more efficient and direct implementation of the above thought
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	if (gas.empty() || gas.size()!=cost.size()) {
		return -1;
	}
	int total=0, tank = 0;
	int start = 0;
	for (int i = 0; i < gas.size(); ++i) {
		tank += gas[i] - cost[i];
		total += gas[i] - cost[i];
		if (tank < 0) {
			tank = 0;
			start = (i+1)%gas.size();
		}
	}
	if (total < 0) {
		return -1;
	} else {
		return start;
	}
}

int main() {
	
	return 0;
}
