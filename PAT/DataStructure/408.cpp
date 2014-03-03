#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
	string name;
	vector <Node *> subdirs;
	vector <Node *> subfiles;
};

vector <string> split(string str, char delim) {
	vector <string> ret;
	int last = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == delim) {
			ret.push_back(str.substr(last, i-last));
			last = i+1;
		}
	}
	if (str[str.size()-1] != delim) {
		ret.push_back(str.substr(last, str.size()-last));
	} else {
		string tmp = "\\";
		ret.push_back(tmp);
	}

	return ret;
}

int binFind(vector <Node *> dirs, string dir) {
	if (dirs.empty()) return -1;
	int low = 0;
	int high = dirs.size()-1;
	int mid;
	while (low < high) {
		mid = (low + high) / 2;
		if (dirs[mid]->name > dir) {
			high = mid;
		} else if (dirs[mid]->name < dir) {
			low = mid+1;
		} else return mid;
	}

		if (dirs[high]->name >= dir) return high;

		return -1;
}

void add(Node * root, vector <string> sp) {
	Node * cur = root;
	for (int i = 0; i < sp.size()-1; ++i) {
		Node * tmp = NULL;
		int next = binFind(cur->subdirs, sp[i]);
		/*cout << next << endl;
		for (int ij = 0; ij < cur->subdirs.size(); ++ij) {
			cout << cur->subdirs[ij]->name << " ";
		}cout << "\\ ";
		cout << sp[i] << endl;*/
		if (next == -1) {
			tmp = new Node();
			tmp->name = sp[i];
			cur->subdirs.push_back(tmp);
			cur = tmp;
		} else {
			if (cur->subdirs[next]->name == sp[i]) {
				cur = cur->subdirs[next];
			} else {
				tmp = new Node();
				tmp->name = sp[i];
				cur->subdirs.insert(cur->subdirs.begin()+next, tmp);
				cur = tmp;
			}
		}
	}
	if (sp[sp.size()-1] != "\\") {
		int next = binFind(cur->subfiles, sp[sp.size()-1]);
		Node *tmp = new Node();
		tmp->name = sp[sp.size()-1];
		if (next == -1) {
			cur->subfiles.push_back(tmp);
		} else {
			cur->subfiles.insert(cur->subfiles.begin()+next, tmp);
		}
	}
}

void preTraverse(Node * root, int depth) {
	if (root == NULL) return ;
	for (int i = 0; i < depth; ++i) {
		printf("  ");
	}
	cout << root->name << endl;
	for (int i = 0; i < root->subdirs.size(); ++i) {
		preTraverse(root->subdirs[i], depth+1);
	}
	for (int i = 0; i < root->subfiles.size(); ++i) {
		preTraverse(root->subfiles[i], depth+1);
	}
}

void deleteDir(Node * root) {
	if (root == NULL) return;
	for (int i = 0; i < root->subdirs.size(); ++i) {
		deleteDir(root->subdirs[i]);
	}
	for (int i = 0; i < root->subfiles.size(); ++i) {
		deleteDir(root->subfiles[i]);
	}

	delete root;

	return ;
}

int main()
{
	int n;
	Node * root = new Node();
	root->name = "root";
	cin >> n;
	string str;
	while (n--) {
		cin >> str;
		vector <string> sp = split(str, '\\');
		add(root, sp);
	}

	preTraverse(root, 0);

	deleteDir(root);

	return 0;
}
