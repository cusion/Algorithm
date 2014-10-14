// BEGIN CUT HERE

// END CUT HERE
#line 5 "Lottery.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

struct Node {
	int id;
	double oddsRev;
	string name;
	friend bool operator < (Node a, Node b) {
		if (a.oddsRev < b.oddsRev) {
			return true;
		} else if (a.oddsRev > b.oddsRev) {
			return false;
		} else {
			return a.name < b.name;
		}
	}
};

class Lottery
{
        public:
        vector <string> sortByOdds(vector <string> rules)
        {
    		VS ret(rules.size());
        	if (rules.empty()) {
        		return ret;
        	}
    		vector<Node> rank(rules.size());
    		for (int i = 0; i < rules.size(); ++i) {
    			rank[i].id = i;
    			int pos = rules[i].find(':');
    			rank[i].name = rules[i].substr(0, pos);
    			++pos;
    			string tmp = getNum(rules[i], pos);
    			int choices = str2int(tmp);
    			tmp = getNum(rules[i], pos);
    			int blanks = str2int(tmp);
    			bool sorted = getBool(rules[i], pos);
    			bool unique = getBool(rules[i], pos);
    			if (sorted==true && unique==true) {
    				rank[i].oddsRev = pickLimited(choices, blanks);
    			} else if (sorted==true && unique == false) {
    				rank[i].oddsRev = pickInOrder(choices, blanks);
    			} else if (sorted==false && unique == true) {
    				rank[i].oddsRev = pickDifferent(choices, blanks);
    			} else {
    				rank[i].oddsRev = pickAny(choices, blanks);
    			}
    		}
    		sort(rank.begin(), rank.end());
    		
    		for (int i = 0; i < rank.size(); ++i) {
    			ret[i] = rank[i].name;
    		}
    		
    		return ret;
        }
        
        private:
        	string getNum(string str, int &pos) {
        		while (str[pos] > '9' || str[pos] < '0') {
        			++pos;
        		}
        		string ret = "";
        		while (str[pos] >= '0' && str[pos] <= '9') {
        			ret.push_back(str[pos]);
        			++pos;
        		}
        		
        		return ret;
        	}
        	
        	bool getBool(string str, int &pos) {
        		while(str[pos]==' ') {
        			++pos;
        		}
        		if (str[pos] == 'T') {
        			++pos;
        			return true;
        		} else {
        			++pos;
        			return false;
        		}
        	}
        	
        	int str2int(string str) {
        		int ret = 0;
        		for (int i = 0; i < str.size(); ++i) {
        			ret = ret*10 + str[i] - '0';
        		}
        		//cout << ret << endl;
        		
        		return ret;
        	}
        	
        	double pickAny(int choices, int blanks) {
        		//cout << "pick Any " << pow(choices, blanks) << endl;
        		return pow(choices, blanks);
        	}
        	
        	double pickDifferent(int choices, int blanks) {
        		double res = 1.0;
        		for (int i = 0; i < blanks; ++i) {
        			res *= choices;
        			choices--;
        		}
        		
        		//cout << "pick Different " << res << endl;
        		return res;
        	}
        	
        	double pickInOrder(int choices, int blanks) {
        		long long dp[choices+1][blanks+1];
        		for (int i = 0; i <= blanks; ++i) {
        			dp[0][i] = 0;
        			dp[1][i] = 1;
        		}
        		for (int i = 0; i <= choices; ++i) {
        			dp[i][0] = 0;
        			dp[i][1] = i;
        		}
        		for (int i = 2; i <= choices; ++i) {
        			for (int j = 2; j <= blanks; ++j) {
        				dp[i][j] = dp[i][j-1] + dp[i-1][j];
        			}
        		}
        		/*for (int i = 0; i <= choices; ++i) {
        			for (int j = 0; j <= blanks; ++j) {
        				cout << dp[i][j] << " ";
        			}puts("");
        		}*/
        		
        		//cout << "pick In Order " << dp[choices][blanks] << endl;
        		return dp[choices][blanks]*1.0;
        	}
        	
        	double pickLimited(int choices, int blanks) {
        		long long dp[choices+1][blanks+1];
        		for (int i = 0; i <= blanks; ++i) {
        			dp[0][i] = 0;
        			dp[1][i] = 0;
        		}
        		for (int i = 0; i <= choices; ++i) {
        			dp[i][0] = 0;
        			dp[i][1] = i;
        		}
        		for (int i = 2; i <= choices; ++i) {
        			for (int j = 2; j <= blanks; ++j) {
        				if (j > i) {
        					dp[i][j] = 0;
        				} else {
        					dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        				}
        			}
        		}
        		
        		//cout << "pick Limited " << dp[choices][blanks] << endl;
        		return dp[choices][blanks]*1.0;
        	}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"PICK ANY TWO: 10 2 F F"
,"PICK TWO IN ORDER: 10 2 T F"
,"PICK TWO DIFFERENT: 10 2 F T"
,"PICK TWO LIMITED: 10 2 T T"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "PICK TWO LIMITED",  "PICK TWO IN ORDER",  "PICK TWO DIFFERENT",  "PICK ANY TWO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortByOdds(Arg0)); }
	void test_case_1() { string Arr0[] = {"INDIGO: 93 8 T F",
 "ORANGE: 29 8 F T",
 "VIOLET: 76 6 F F",
 "BLUE: 100 8 T T",
 "RED: 99 8 T T",
 "GREEN: 78 6 F T",
 "YELLOW: 75 6 F F"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortByOdds(Arg0)); }
	void test_case_2() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortByOdds(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        Lottery ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE

