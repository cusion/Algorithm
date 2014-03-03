#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

vector <string> fullJustify(vector<string> &words, int L) {
	vector <int> spaces;
	vector <int> wordsInLine;
	int lineLen=0;                 // contain words and spaces
	vector <string> lines;
	//puts("============= test ==============");
	for (int i = 0; i < words.size(); ++i) {
		//cout <<words[i] << " LineLen " << lineLen << endl;
		if (lineLen + words[i].size() < L) {
			lineLen += words[i].size() + 1;
			wordsInLine.push_back(i);
			spaces.push_back(1);
		} else if (lineLen + words[i].size() > L) {
			--i;
			if (!spaces.empty()) {
				spaces.pop_back();
				--lineLen;
			}
			int spacesLeft = L - lineLen;
			if (spaces.empty()) {
				spaces.push_back(spacesLeft);
			} else {
				int ind = 0;
				while (ind < spacesLeft) {
					++spaces[ind % spaces.size()];
					++ind;
				}
			}
			string line = "";
			for (int j = 0; j < wordsInLine.size(); ++j) {
				line.append(words[wordsInLine[j]]);
				if (j < spaces.size()) {
					line.append(spaces[j], ' ');
				}
			}
			lineLen = 0;
			wordsInLine.clear();
			spaces.clear();
			lines.push_back(line);
		} else {
			string line = "";
			for (int j = 0; j < wordsInLine.size(); ++j) {
				line.append(words[wordsInLine[j]]);
				line.append(1, ' ');
			}
			line.append(words[i]);
			lineLen = 0;
			wordsInLine.clear();
			spaces.clear();
			lines.push_back(line);
		}
	}
	
	if (!wordsInLine.empty()) {
		int spacesLeft = L - lineLen;
		string line = "";
		for (int i = 0; i < wordsInLine.size(); ++i) {
			line.append(words[wordsInLine[i]]);
			if (i < spaces.size()) {
				line.append(spaces[i], ' ');
			}
		}
		line.append(spacesLeft, ' ');
		lines.push_back(line);
	}
	
	//puts("========== end Test ==========");
	return lines;
}

int main() {
	string strs[7] = {"This", "is", "an", "example", "of", "text", "justification."};
	string strs2[5] = {"What", "must", "be", "shall", "be."};
	vector <string> words(strs2, strs2+5);
	vector <string> wordsJustified = fullJustify(words, 12);
	for (int i = 0; i < wordsJustified.size(); ++i) {
		cout << wordsJustified[i] << "|" << endl;
	}
	
	return 0;
}
