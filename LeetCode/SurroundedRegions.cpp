#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

/*************** Method 1, using Union-Find set, TLE *************
struct Position {
	int x;
	int y;
	Position(int xx, int yy):x(xx), y(yy) {}
};

int father(int x, vector<int> &fa) {
	return fa[x] == x? x : fa[x]=father(fa[x], fa);
}

void merge(int x, int y, vector<int> &fa) {
	int fx = father(x, fa);
	int fy = father(y, fa);
	if (fx != fy) {
		fa[fy] = fx;
	}
}

struct KeyHash {
	std::size_t operator()(const Position &k) const{
		long long kx = k.x;
		kx <<= 32;
		long long ky = k.y;
		return kx+ky;
	}
};

struct KeyEqual {
	bool operator()(const Position &lhs, const Position &rhs) const {
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}
};

bool isAtBorder(Position pos, int size) {
	return pos.x == 0 || pos.x == size-1 || pos.y == 0 || pos.y == size-1;
}

void solve(vector<vector<char> >&board) {
	if (board.empty()) {
		return;
	}
	unordered_map <Position,int, KeyHash, KeyEqual> oIndx;
	//vector <Position> oCluster;
	int cnt = 0;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			if (board[i][j] == 'O') {
				oIndx.insert(pair<Position, int>(Position(i, j), cnt++));
				//oCluster.push_back(Position(i, j));
			}
		}
	}
	
	vector <int> fa(oIndx.size());
	for (int i = 0; i < fa.size(); ++i) {
		fa[i] = i;
	}
	
	for (auto it = oIndx.begin(); it != oIndx.end(); ++it) {
		Position tmp = it->first;
		// Considering only the left forward and top forward connection should be enough
		auto it1 = oIndx.find(Position(tmp.x-1, tmp.y));
		if (it1 != oIndx.end()) {
			merge(it->second, it1->second, fa);
		}
		
		it1 = oIndx.find(Position(tmp.x, tmp.y-1));
		if (it1 != oIndx.end()) {
			merge(it->second, it1->second, fa);
		}
	}
	
	unordered_set <int> isSurrounded;
	for (auto it = oIndx.begin(); it!=oIndx.end(); ++it) {
		int indx = it->second;
		if (father(indx, fa)==indx) {
			isSurrounded.insert(indx);
		}
	}
	
	for (auto it = oIndx.begin(); it!=oIndx.end(); ++it) {
		if (isAtBorder(it->first, board.size())) {
			int indx = it->second;
			if (isSurrounded.find(indx) != isSurrounded.end()) {
				isSurrounded.erase(indx);
			}
		}
	}
	
	for (auto it = oIndx.begin(); it != oIndx.end(); ++it) {
		if (isSurrounded.find(father(it->second, fa)) != isSurrounded.end()) {
			board[it->first.x][it->first.y] = 'X';
		}
	}
	
	return;
}*/

/********************* Method 2, Direct Search, RE *************/
bool isValid(vector<vector<char> > &board, int x, int y, vector<vector<bool> > &visit) {
	if (x>=0 && x < board.size() && y>=0 && y < board[0].size() && board[x][y] == 'O' && !visit[x][y]) {
		return true;
	}
	return false;
}

struct Position {
	int x;
	int y;
	Position(int xx, int yy):x(xx), y(yy){}
};

/**************** DFS causes Runtime Error, resorting to BFS
void mark(vector<vector<char> > &board, int x, int y, vector<vector<bool> > &visit) {
	visit[x][y] = true;
	if (isValid(board, x-1, y, visit)) {
		mark(board, x-1, y, visit);
	}
	if (isValid(board, x, y-1, visit)) {
		mark(board, x, y-1, visit);
	}
	if (isValid(board, x+1, y, visit)) {
		mark(board, x+1, y, visit);
	}
	if (isValid(board, x, y+1, visit)) {
		mark(board, x, y+1, visit);
	}
}*/

void mark(vector<vector<char> >&board, int x, int y, vector<vector<bool> >&visit) {
	queue <Position> q;
	q.push(Position(x, y));
	vector<vector<bool> > inQueue(board.size(), vector<bool>(board[0].size(), false));
	inQueue[x][y] = true;
	while (!q.empty()) {
		Position tmp = q.front();
		q.pop();
		visit[tmp.x][tmp.y] = true;
		if (isValid(board, tmp.x-1, tmp.y, visit) && !inQueue[tmp.x-1][tmp.y]) {
			q.push(Position(tmp.x-1, tmp.y));
			inQueue[tmp.x-1][tmp.y] = true;
		}
		if (isValid(board, tmp.x, tmp.y-1, visit)&&!inQueue[tmp.x][tmp.y-1]) {
			q.push(Position(tmp.x, tmp.y-1));
			inQueue[tmp.x][tmp.y-1] = true;
		}
		if (isValid(board, tmp.x+1, tmp.y, visit)&&!inQueue[tmp.x+1][tmp.y]) {
			q.push(Position(tmp.x+1, tmp.y));
			inQueue[tmp.x+1][tmp.y] = true;
		}
		if (isValid(board, tmp.x, tmp.y+1, visit)&&!inQueue[tmp.x][tmp.y+1]) {
			q.push(Position(tmp.x, tmp.y+1));
			inQueue[tmp.x][tmp.y+1] = true;
		}
	}
}

void solve(vector<vector<char> > &board) {
	if (board.empty()) {
		return;
	}
	int rsize = board.size();
	int csize = board[0].size();
	vector <vector<bool> > visit(rsize, vector<bool>(csize));
	for (int i = 0; i < rsize; ++i) {
		if (board[i][0] == 'O' && !visit[i][0]) {
			mark(board, i, 0, visit);
		}
		if (board[i][csize-1] == 'O' && !visit[i][csize-1]) {
			mark(board, i, csize-1, visit);
		}
	}
	for (int i = 0; i < csize; ++i) {
		if (board[0][i] == 'O' && !visit[0][i]) {
			mark(board, 0, i, visit);
		}
		if (board[rsize-1][i]=='O' && !visit[rsize-1][i]) {
			mark(board, rsize-1, i, visit);
		}
	}
	
	for (int i = 0; i < rsize; ++i) {
		for (int j = 0; j < csize; ++j) {
			//cout << visit[i][j];
			if (board[i][j] == 'O' && !visit[i][j]) {
				board[i][j] = 'X';
			}
		}//puts("");
	}
	
	return ;
}

int main() {
	int n;
	while (1) {
		cin >> n;
		vector <vector<char> > board(n, vector<char>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				char ch;
				cin >> ch;
				while (ch != 'X' && ch != 'O') {
					cin >> ch;
				}
				//board[i][j] = 'O';
				board[i][j] = ch;
			}
		}
		puts("----------------------");
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << board[i][j];
			}puts("");
		}
		puts("=======================");
		solve(board);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << board[i][j];
			}puts("");
		}
		puts("########################");
	}
	return 0;
}
