#include <cstdio>
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

/****************** TLE Version *************************
struct CacheNode {
	int key;
	int value;
	CacheNode(int k, int v):key(k), value(v){}
	CacheNode(){}
};

class LRUCache {
	int capacity;
	list <CacheNode> cache;
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		cache.clear();
	}
	
	int get(int key) {
		if (capacity <= 0) {
			return -1;
		}
		CacheNode tmp;
		tmp.value = -1;
		for (auto it = cache.begin(); it != cache.end(); ++it) {
			if (it->key == key) {
				tmp = (*it);
				cache.erase(it);
				break;
			}
		}
		if (tmp.value == -1) {
			return -1;
		} else {
			cache.push_front(tmp);
			return tmp.value;
		}
	}
	
	void set(int key, int value) {
		CacheNode tmp;
		tmp.value = -1;
		for (auto it = cache.begin(); it!=cache.end(); ++it) {
			if (it->key == key) {
				tmp = (*it);
				cache.erase(it);
				break;
			}
		}
		if (tmp.value == -1) {
			if (cache.size() >= capacity) {
				cache.pop_back();
			}
			cache.push_front(CacheNode(key, value));
		} else {
			tmp.value = value;
			cache.push_front(tmp);
		}
	}
	
	void print() {
		for (auto it = cache.begin(); it != cache.end(); ++it) {
			cout << it->key << "<->" << it->value << " ";
		}
		puts("");
	}
};*/

/******************** Also TLE Version *****************
struct CacheNode {
	int key;
	int value;
	CacheNode(int k, int v):key(k), value(v){}
	CacheNode(){}
};

class LRUCache {
	int capacity;
	list <CacheNode> cache;
	unordered_set <int> keySet;
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		cache.clear();
		keySet.clear();
	}
	
	int get(int key) {
		if (keySet.find(key) == keySet.end()) {
			return -1;
		}
		
		if (capacity <= 0) {
			return -1;
		}
		CacheNode tmp;
		for (auto it = cache.begin(); it != cache.end(); ++it) {
			if (it->key == key) {
				tmp = (*it);
				cache.erase(it);
				break;
			}
		}
		cache.push_front(tmp);
		return tmp.value;
	}
	
	void set(int key, int value) {
		if (keySet.find(key) == keySet.end()) {
			if (cache.size() >= capacity) {
				keySet.erase(cache.back().key);
				cache.pop_back();
			}
			cache.push_front(CacheNode(key, value));
			keySet.insert(key);
		}
		CacheNode tmp;
		for (auto it = cache.begin(); it!=cache.end(); ++it) {
			if (it->key == key) {
				tmp = (*it);
				cache.erase(it);
				break;
			}
		}
		tmp.value = value;
		cache.push_front(tmp);
	}
	
	void print() {
		for (auto it = cache.begin(); it != cache.end(); ++it) {
			cout << it->key << "<->" << it->value << " ";
		}
		puts("");
	}
};*/


struct QNode {
	int key;
	int value;
	QNode *pre;
	QNode *next;
	QNode(int k, int v):key(k),value(v),pre(NULL),next(NULL){}
	QNode():key(0),value(-1),pre(NULL),next(NULL){}
};

class LRUCache {
	int capacity;
	QNode front, rear;
	unordered_map <int, QNode*> keyAddress;
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		front.next = &rear;
		rear.pre = &front;
		keyAddress.clear();
	}
	
	int get(int key) {
		unordered_map<int,QNode*>:: iterator itr;
		itr = keyAddress.find(key);
		if (itr == keyAddress.end()) {
			return -1;
		}
		
		QNode *cur = itr->second;
		cur->pre->next = cur->next;
		cur->next->pre = cur->pre;
		cur->pre = &front;
		cur->next = front.next;
		front.next->pre = cur;
		front.next = cur;
		
		return cur->value;
	}
	
	void set(int key, int value) {
		if (capacity == 0) {
			return ;
		}
		unordered_map<int,QNode*>::iterator itr;
		QNode *tmp;
		itr = keyAddress.find(key);
		if (itr == keyAddress.end()) {
			tmp = new QNode(key, value);
			keyAddress.insert(pair<int, QNode*>(key, tmp));
		} else {
			tmp = itr->second;
			tmp->value = value;
			tmp->pre->next = tmp->next;
			tmp->next->pre = tmp->pre;
		}
		if (keyAddress.size() > capacity) {
			keyAddress.erase(rear.pre->key);
			rear.next = rear.pre;
			rear.pre = rear.pre->pre;
			rear.pre->next = &rear;
			delete rear.next;
			rear.next = NULL;
		}
		tmp->next = front.next;
		tmp->next->pre = tmp;
		front.next = tmp;
		tmp->pre = &front;
	}
	
	void print() {
		QNode * cur = front.next;
		while (cur->next) {
			cout << cur->key << "<->" << cur->value << " ";
			cur = cur->next;
		}
		puts("");
	}
};

int main() {
	LRUCache cache(5);
	while (1) {
		cout << "choose operation (0 for get, 1 for set) >>";
		int opt;
		cin >> opt;
		if (opt == 0) {
			int key;
			cout << "input the key >>" ;
			cin >> key;
			cout << "result >>" << cache.get(key) << endl;
		} else if (opt == 1) {
			int key, value;
			cout << "intput key and value >>";
			cin >> key >> value;
			cache.set(key, value);
			cout << "result: ";
			cache.print();
			puts("=======================");
		}
	}
	return 0;
}
