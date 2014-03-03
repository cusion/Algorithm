#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Person {
	string name;
	int parent;
	int depth;
	vector <int> descendants;
};

int getDepth(string name) {
	int ret = 0;
	while (name[ret] == ' ') {
		ret += 2;
	}

	return ret/2;
}

int findLCA(Person * tree, int p1, int p2) {
	int shorter = tree[p1].depth < tree[p2].depth ? p1 : p2;
	int longer  = p1 + p2 - shorter;

	//cout <<"In LCA " << shorter << " " << longer << endl;

	while (tree[shorter].depth < tree[longer].depth) {
		//cout << "depth " << tree[shorter].depth << " " << tree[longer].depth << endl;
		//getchar();
		longer = tree[longer].parent;
	}

	while (shorter != longer) {
		shorter = tree[shorter].parent;
		longer  = tree[longer].parent;
	}

	return shorter;
}

bool isRelValid(Person * tree, int ch1, int ch2, int anc, string rel) {
	if ("child" == rel) {
		return tree[ch1].parent == ch2;
	} else if ("parent" == rel) {
		return tree[ch2].parent == ch1;
	} else if ("sibling" == rel) {
		return tree[ch1].parent == tree[ch2].parent;
	} else if ("descendant" == rel) {
		return anc == ch2;
	} else if ("ancestor" == rel) {
		return anc == ch1;
	}
}

bool check(Person * tree, map <string, int> personMap, string p1, string p2, string rel) {
	int pindx1 = personMap.find(p1)->second;
	int pindx2 = personMap.find(p2)->second;
	//cout << "find " << p1 << " " << pindx1 << " " << p2 << " " << pindx2 << endl;

	int LCA = findLCA(tree, pindx1, pindx2);
	
	return isRelValid(tree, pindx1, pindx2, LCA, rel);
}

int main()
{
	map <string, int> personMap;
	Person person[103];
	int indx = 0;
	string name;
	int n, m;
	cin >> n >> m;
	getline(cin, name);getline(cin, name);
	person[0].name = name;
	person[0].parent = -1;
	person[0].depth = 0;
	personMap.insert(pair<string, int>(name, indx));
	indx++, n--;
	int parnode = 0, pardepth = 0;
	while (n--) {
		getline(cin, name);
		int curdepth = getDepth(name);
		int curnode = indx;
		person[curnode].name = name.substr(curdepth*2, name.length() - curdepth*2);
		person[curnode].depth = curdepth;
		personMap.insert(pair<string, int>(person[curnode].name, curnode));
		++indx;
		while ((curdepth-pardepth)!=1) {
			if (pardepth >= curdepth) {
				pardepth -= 1;
				parnode = person[parnode].parent;
			} else {
				pardepth += 1;
				int last = person[parnode].descendants.size()-1;
				parnode = person[parnode].descendants[last];
			}
		}
		person[curnode].parent = parnode;
		person[parnode].descendants.push_back(curnode);
	}
	/*for (int i = 0; i < indx; ++i) {
		cout << person[i].parent << " <- " << person[i].name << " -> ";
		for (int j = 0; j < person[i].descendants.size(); ++j) {
			cout << person[i].descendants[j] << " ";
		}cout << endl;
	}
	map<string, int>::iterator itr;
	for (itr = personMap.begin(); itr != personMap.end(); ++itr) {
		cout << itr->first << " " << itr->second << endl;
	}

	cout << "Press to continue ..." << endl;getchar();getchar();getchar();cout << "go on..." << endl;*/

	int words = 6;
	while (m--) {
		string question[words];
		for (int i = 0; i < words; ++i) {
			cin >> question[i];
		}
		/*for (int i = 0; i < words; ++i) {
			cout << question[i] << " ";
		} cout << endl;
		cout << "Press to continue ..." << endl;getchar();getchar();cout << "go on..." <<endl;*/

		if (check(person, personMap, question[0], question[words-1], question[3])) {
			puts("True");
		} else {
			puts("False");
		}
	}

	return 0;
}
