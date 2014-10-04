#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

int toNumber(string str, int s, int len) {
	int ret = 0;
	for (int i = 0; i < len; ++i) {
		ret = ret*10 + str[s+i] - '0';
	}
	return ret;
}

/*string toString(int val) {
	string ret, rev;
	if (val == 0) {
		ret = "0";
	} else {
		ret = "";
		rev = "";
	}
	
	while (val) {
		rev.append(1, val%10+'0');
		val = val/10;
	}
	
	for (int i = rev.size()-1; i >= 0; --i) {
		ret.append(1, rev[i]);
	}
	
	return ret;
}*/

bool checkValid(string str, int first, int second, int third, vector <int> hasIp[]) {
	
	if (str[0]=='0' && first > 1) return false;
	if (str[first] == '0' && second-first > 1) return false;
	if (str[second] == '0' && third-second > 1) return false;
	if (str[third] == '0' && str.size()-third > 1) return false;
	
	int ip[4];
	ip[0] = toNumber(str, 0, first);
	ip[1] = toNumber(str, first, second-first);
	ip[2] = toNumber(str, second, third-second);
	ip[3] = toNumber(str, third, str.size()-third);
	//cout << ip[0] << " " << ip[1] << " " << ip[2] << " " << ip[3] << endl;	
	/*bool found[4];
	for (int i = 0; i < 4; ++i)  {
		found[i] = false;
		for (int j = 0; j < hasIp[i].size(); ++j) {
			if (ip[i] == hasIp[i][j]) {
				found[i] = true;
			} else {
				hasIp[i].push_back(ip[i]);
			}
		}
	}*/
	
	return ip[0]<=255 && ip[1]<=255 && ip[2]<=255 && ip[3]<=255
		   /*&& !(found[0] && found[1] && found[2] && found[3])*/;
}

vector <string> restoreIpAddresses(string str) {
	vector <string> validIps;
	vector<int> hasIp[4];
	
	int len = str.size();
	for (int firstDelim = 1; firstDelim <= 3; ++firstDelim) {
		for (int secondDelim = firstDelim+1; secondDelim <=firstDelim + 3; ++ secondDelim) {
			for (int thirdDelim = secondDelim + 1; thirdDelim <= secondDelim + 3; ++thirdDelim) {
				//cout << firstDelim << " " << secondDelim << " " << thirdDelim << " " << len << endl;
				//system("pause");
				if (thirdDelim < len && len <= thirdDelim + 3) {
					if (checkValid(str, firstDelim, secondDelim, thirdDelim, hasIp)) {
						string aValidIp = "";
						aValidIp.append(str.substr(0, firstDelim));
						aValidIp.append(1, '.');
						aValidIp.append(str.substr(firstDelim, secondDelim-firstDelim));
						aValidIp.append(1, '.');
						aValidIp.append(str.substr(secondDelim, thirdDelim-secondDelim));
						aValidIp.append(1, '.');
						aValidIp.append(str.substr(thirdDelim, len-thirdDelim));
						validIps.push_back(aValidIp);
					}
				}
			}
		}
	}
	
	return validIps;
}

int main() {
	string str("172162541");
	cout << str << endl;
	
	vector <string> validIP = restoreIpAddresses(str);
	
	for (int i = 0; i < validIP.size(); ++i) {
		cout << validIP[i] << endl;
	}
	
	return 0;
}
