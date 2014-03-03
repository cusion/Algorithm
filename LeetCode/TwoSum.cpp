#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/******************* Method 1, sort the array and then find **********
struct Node {
	int value;
	int indx;
	Node(int v, int i):value(v), indx(i){}
	Node(){}
	friend bool operator <(Node a, Node b) {
		if (a.value < b.value) {
			return true;
		} else if (a.value == b.value) {
			if (a.indx < b.indx) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
};
vector <int> twoSum(vector<int> &numbers, int target) {
	vector <int> ret;
	if (numbers.empty()) {
		return ret;
	}
	vector <Node> nodes(numbers.size());
	for (int i = 0; i < numbers.size(); ++i) {
		nodes[i].value = numbers[i];
		nodes[i].indx = i+1;
	}
	sort(nodes.begin(), nodes.end());
	int small = 0;
	int big = nodes.size()-1;
	while (small < big) {
		if (nodes[small].value + nodes[big].value == target) {
			if (nodes[small].indx > nodes[big].indx) {
				ret.push_back(nodes[big].indx);
				ret.push_back(nodes[small].indx);
			} else {
				ret.push_back(nodes[small].indx);
				ret.push_back(nodes[big].indx);
			}
			break;
		} else if (nodes[small].value + nodes[big].value > target) {
			--big;
		} else {
			++small;
		}
	}
	
	return ret;
}*/

/********************** Method 2, using hashmap ************/
vector <int> twoSum(vector<int> &numbers, int target) {
	vector<int> ret;
	if (numbers.empty()) {
		return ret;
	}
	unordered_map <int, int> indxMap;
	for (int i = 0; i < numbers.size(); ++i) {
		if (indxMap.find(numbers[i]) == indxMap.end()) {
			if (indxMap.find(target-numbers[i]) != indxMap.end()) {
				ret.push_back(indxMap[target-numbers[i]]);
				ret.push_back(i+1);
				break;
			}
			indxMap.insert(pair<int,int>(numbers[i], i+1));
		} else {
			if (numbers[i] + numbers[i] == target) {
				ret.push_back(indxMap[numbers[i]]);
				ret.push_back(i+1);
				break;
			}
		}
	}
	
	return ret;
}

int main() {
	return 0;
}
