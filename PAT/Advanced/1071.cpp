#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isAlphaNumerical(char ch) {
	if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		//cout << "yes" << ch << endl;
		return true;
	}
	return false;
}

/*string getWord(string str) {
	string ret = "";
	for (int i = 0; i < str.size(); ++i) {
		if (isAlphaNumerical(str[i])) {
			if ((str[i]>='A') && (str[i]<='Z')) {
				ret.append(1, str[i]-'A'+'a');
			} else {
				ret.append(1, str[i]);
			}
		}
	}

	return ret;
}*/

bool getItem(char * str, string &ret, int &indx) {
	while (str[indx] != '\0' && !isAlphaNumerical(str[indx])) {
		indx++;
	}
	if (str[indx] == '\0') {
		return false;
	}

	while (str[indx] != '\0' && isAlphaNumerical(str[indx])) {
		if (str[indx]>='A' && str[indx]<='Z') {
			ret.append(1, str[indx]-'A'+'a');	
		} else {
			ret.append(1, str[indx]);
		}
		indx++;
	}

	return true;
}

char str[1100000];

int main()
{
	map <string, int> counter;
	map <string, int>::iterator itr;
	string strItem = "";
	//bool isFirst = true;
	gets(str);
	int indx = 0;
	while (getItem(str, strItem, indx)) {		
		/*if (isFirst) {
			isFirst = false;
			strItem = "";
			continue;
		}*/
		//cout << strItem << endl;
		itr = counter.find(strItem);
		//cout << str << " " << " " << itr->second << endl;
		if (itr!=counter.end()) {
			itr->second = itr->second + 1;
			//cout << "Find ";
			//cout << str << " " << getWord(str) << " " << itr->second << endl;
		} else {
		    //cout << "Not find ";
			counter.insert(pair<string, int>(strItem, 1));
			//cout << str << " " << getWord(str) << " " << itr->second << endl;
		}
		strItem = "";
	}

	int maxCounter = 0;
	map <string, int>::iterator maxItr=counter.begin();
	for (itr = counter.begin(); itr!=counter.end();++itr) {
		if (itr->second > maxCounter) {
			maxCounter = itr->second;
			maxItr = itr;
		}
	}
	cout << maxItr->first << " " << maxItr->second << endl;	

	return 0;
}
