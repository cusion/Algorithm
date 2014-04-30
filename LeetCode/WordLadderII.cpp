#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;

/****************** TLE version ***************
// using Bi-BFS to determine the least length, and use the length to 
// find out all path using DFS
int getLen(int start, int end, vector<vector<int> > &adj) {
	if (start == end) {
		return 0;
	}
	
	queue<int> q;
	queue<int> rq;
	vector<bool> visit(adj.size(), false);
	vector<bool> rvisit(adj.size(), false);
	q.push(start);
	rq.push(end);
	visit[start] = true;
	rvisit[end] = true;
	int level = 0;
	int rlevel = 0;
	int lnum = 1;
	int rlnum = 1;
	while (!q.empty() && !rq.empty()) {
		int levelTmpNum = 0;
		if (level < rlevel) {
			while (!q.empty() && lnum--) {
				int tmp = q.front();
				q.pop();
				if (rvisit[tmp]) {
					return rlevel+level;
				}
				
				for (int i = 0; i < adj[tmp].size(); ++i) {
					if (!visit[adj[tmp][i]]) {
						q.push(adj[tmp][i]);
						++levelTmpNum;
						visit[adj[tmp][i]] = true;
					}
				}
			}
			lnum = levelTmpNum;
			++level;
		} else {
			while (!rq.empty() && rlnum--) {
				int tmp = rq.front();
				rq.pop();
				if (visit[tmp]) {
					return rlevel+level;
				}
				
				for (int i = 0; i < adj[tmp].size(); ++i) {
					if (!rvisit[adj[tmp][i]]) {
						rq.push(adj[tmp][i]);
						++levelTmpNum;
						rvisit[adj[tmp][i]] = true;
					}
				}
			}
			rlnum = levelTmpNum;
			++rlevel;
		}
	}
	
	return -1;
}

void getAllPath(int start, int end, vector<vector<int> > &adj, int curlen, int len, vector<vector<string> > &ret, vector<string> &id2str, vector<int> &tmpPath, vector<bool> &visit) {
	//cout << start << " " << curlen << endl;
	//system("pause");
	if (curlen > len) {
		return;
	} else if (curlen == len) {
		if (start == end) {
			//cout << "get" << endl;
			vector <string> tmp;
			for (int i = 0; i < tmpPath.size(); ++i) {
				tmp.push_back(id2str[tmpPath[i]]);
			}
			ret.push_back(tmp);
		}
		return;
	}
	
	for (int i = 0; i < adj[start].size(); ++i) {
		if (!visit[adj[start][i]]) {
			visit[adj[start][i]] = true;
			tmpPath.push_back(adj[start][i]);
			getAllPath(adj[start][i], end, adj, curlen+1, len, ret, id2str, tmpPath, visit);
			visit[adj[start][i]] = false;
			tmpPath.pop_back();
		}
	}
}*/

struct Node {
	int id;
	int dist;
	Node(int i, int d):id(i), dist(d){}
	Node(){}
	friend bool operator < (Node a, Node b) {
		return a.dist > b.dist;
	}
}nod1, nod2;

#define INF 0x3fffffff

void dfs(int end, const vector<vector<int> > &pre, const vector<string> &id2str, vector<vector<string> > &ret, vector<int> &tmp) {
	if (pre[end].empty()) {
		vector<string> tmpPath;
		for (int i = tmp.size()-1; i >= 0; --i) {
			tmpPath.push_back(id2str[tmp[i]]);
		}
		ret.push_back(tmpPath);
	}
	for (int i = 0; i < pre[end].size(); ++i) {
		tmp.push_back(pre[end][i]);
		dfs(pre[end][i], pre, id2str, ret, tmp);
		tmp.pop_back();
	}
}

void getAllPath(int start, int end, vector<vector<int> > &adj, vector<string> &id2str, vector<vector<string> > &ret) {
	vector<int> dist(adj.size(), INF);
	vector<bool> hasMin(adj.size(), false);
	vector<vector<int> > pre(adj.size(), vector<int>());
	
	priority_queue<Node> q;
	dist[start] = 0;
	nod1.id = start;
	nod1.dist = 0;
	q.push(nod1);
	while (!q.empty()) {
		nod1 = q.top();
		q.pop();
		int cur = nod1.id;
		if (hasMin[cur]) {
			continue;
		}
		if (cur == end) {
			break;
		}
		hasMin[cur] = true;
		
		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i];
			if (!hasMin[next]) {
				if (dist[next] > dist[cur] + 1) {
					dist[next] = dist[cur] + 1;
					nod2.id = next;
					nod2.dist = dist[next];
					if (!pre.empty()) {
						pre[next].clear();
					}
					pre[next].push_back(cur);
					q.push(nod2);
				} else if (dist[next] == dist[cur] + 1) {
					pre[next].push_back(cur);
				}
			}
		}
	}
	//cout << dist[end] << endl;
	
	// get pathes
	if (dist[end] != INF) {
		vector<int> tmp;
		tmp.push_back(end);
		dfs(end, pre, id2str, ret, tmp);
	}
}

vector <vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
	vector <vector<string> > ret;
	if (dict.empty()) {
		return ret;
	}
	unordered_map<string, int> str2id;
	vector<string> id2str(dict.size()+2);
	int total = 0;
	if (dict.find(start) == dict.end()) {
		id2str[total] = start;
		str2id[start] = total++;
	}
	for (auto it = dict.begin(); it != dict.end(); ++it) {
		id2str[total] = *it;
		str2id[*it] = total++;
	}
	if (dict.find(end) == dict.end()) {
		id2str[total] = end;
		str2id[end] = total++;
	}
	
	vector<vector<int> > adj(str2id.size(), vector<int>());
	for (int i = 0; i < total; ++i) {
		for (int idx = 0; idx < start.length(); ++idx) {
			string tmp = id2str[i];
			for (int inc = 0; inc < 26; ++inc) {
				char ch = (char)('a' + inc);
				tmp[idx] = ch;
				if (str2id.find(tmp) != str2id.end() && str2id[tmp] != i) {
					adj[i].push_back(str2id[tmp]);
				}
			}
		}
	}
	/*
	int len = getLen(str2id[start], str2id[end], adj);
	//cout << len << endl;
	
	vector <int> tmpPath;
	vector<bool> visit(total, false);
	
	tmpPath.push_back(str2id[start]);
	visit[str2id[start]] = true;
	getAllPath(str2id[start], str2id[end], adj, 0, len, ret, id2str, tmpPath, visit);*/
	
	getAllPath(str2id[start], str2id[end], adj, id2str, ret);
	
	return ret;
}

int main() {
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict = {"hot","dot","dog","lot","log"};
	vector<vector<string> > ret = findLadders(start, end, dict);
	
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}puts("");
	}
	return 0;
}
