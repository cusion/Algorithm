#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int folderType(string str) {
	if (str.length() == 1 && str[0] == '.') {
		return 0;
	} else if (str.length() == 2 && str[0] == '.' && str[1] == '.') {
		return -1;
	}
	
	return 1;
}

string getFolder(string path, int &start) {
	int len = 0;
	while (start < path.length() && path[start] == '/') {
		++start;
	}
	if (start >= path.length()) {
		string ret="";
		return ret;
	} 
	while (start+len < path.length() && path[start+len]!='/') {
		++len;
	}
	return path.substr(start,len);
}

string simplifyPath(string path) {
	string ret;
	if (path.empty()) {
		return ret;
	}
	vector <string> curPath;
	curPath.push_back("/");
	int start = 0;
	while (start < path.size() && path[start]!='/') {
		++start;
	}
	while (start < path.size()) {
		string tmpFolder = getFolder(path, start);
		if (tmpFolder.empty()) break;
		start += tmpFolder.length();
		int type = folderType(tmpFolder);
		if (type == 1) {
			curPath.push_back(tmpFolder);
		} else if (type == -1) {
			if (curPath.size() > 1) {
				curPath.pop_back();
			}
		}
	}
	
	ret = curPath[0];
	for (int i = 1; i < curPath.size(); ++i) {
		ret.append(curPath[i]);
		if (i!=curPath.size()-1) {
			ret.append(1, '/');
		}
	}
	return ret;
}

int main() {
	string path = "/a/./b/../../c/";
	cout << simplifyPath(path);
	return 0;
}
