#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

struct CallRecord {
	int day, hour, minute;
	bool status;
	friend bool operator < (CallRecord a, CallRecord b) {
		if (a.day < b.day) {
			return true;
		} else if (a.day == b.day){
			if (a.hour < b.hour) {
				return true;
			} else if (a.hour == b.hour) {
				return a.minute < b.minute;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
};

void primCallRecord(unordered_map<string, vector<CallRecord> > &umap) {
	if (umap.empty()) {
		return;
	}
	unordered_map<string, vector<CallRecord> >::iterator itr;
	
	/******* This is an miss understanding of what 'paired' means
	for (itr = umap.begin(); itr != umap.end(); ++itr) {
		sort(itr->second.begin(), itr->second.end());
		stack<CallRecord> onlineRecord;
		vector<CallRecord> cleanRecord;
		for (int i = 0; i < itr->second.size(); ++i) {
			if (itr->second[i].status == true) {
				onlineRecord.push(itr->second[i]);
			} else {
				if (!onlineRecord.empty()) {
					cleanRecord.push_back(onlineRecord.top());
					onlineRecord.pop();
					cleanRecord.push_back(itr->second[i]);
				}
			}
		}
		// cleanRecord is now arranged counter chronological order, since the
		// start time order is reversed by the stack we use;
		itr->second = cleanRecord;
	}*/
	for (itr = umap.begin(); itr != umap.end(); ++itr) {
		sort(itr->second.begin(), itr->second.end());
		vector<CallRecord> cleanRecord;
		for (int i = 0; i < itr->second.size()-1; ) {
			if (itr->second[i].status == true && itr->second[i+1].status == false) {
				cleanRecord.push_back(itr->second[i]);
				cleanRecord.push_back(itr->second[i+1]);
				i += 2;
			} else {
				++i;
			}
		}
		itr->second = cleanRecord;
	}
	
	return;
}

void calculateBill(vector<string>&users, vector<int> &rate, unordered_map<string, vector<CallRecord> >&umap, string month) {
	sort(users.begin(), users.end());
	/*for (int i = 0; i < users.size(); ++i) {
		cout << users[i] << endl;
	}*/
	primCallRecord(umap);
	
	/*for (auto it = umap.begin(); it != umap.end(); ++it) {
		cout << it->first << endl;
		for (int i = 0; i < it->second.size(); ++i) {
			cout << it->second[i].day << " " << it->second[i].hour << " " << it->second[i].minute << endl;
		}
	}
	system("pause");*/
	for (int i = 0; i < users.size(); ++i) {		
		string curUser = users[i];
		vector<CallRecord> curRecord= umap[curUser];
		
		if (curRecord.size() > 0) {
			cout << users[i] << " " << month << endl;
		}
		double total = 0;
		int indx = 0;
		while (indx < curRecord.size()) {
			CallRecord on = curRecord[indx];
			++indx;
			CallRecord off = curRecord[indx];
			++indx;
			
			int duration = (off.day-on.day)*24*60 + (off.hour-on.hour)*60 + (off.minute-on.minute);
			
			printf("%02d:%02d:%02d %02d:%02d:%02d %d ", on.day, on.hour, on.minute, off.day, off.hour, off.minute, duration);
			
			int curHour = on.hour;
			int curMin = on.minute;
			double cost = 0;
			while (duration > 0) {
				int timeElapse = min(duration, 60-curMin);
				
				cost += rate[curHour] * timeElapse;
				
				curHour = (curHour+1)%24;
				curMin = (curMin + timeElapse)%60;
				duration -= timeElapse;
			}
			printf("$%.2f\n", cost/100);
			total += cost;
		}
		if (curRecord.size() > 0) {
			printf("Total amount: $%.2f\n", total/100);
		}
	}
}

int main(){
	vector <int> rate(24);
	unordered_map<string, vector<CallRecord> > umap;
	vector <string> users;
	int n;
	for (int i = 0; i < 24; ++i) {
		cin >> rate[i];
	}
	cin >> n;
	string name, time, stat;
	for (int i = 0; i < n; ++i) {
		cin >> name >> time >> stat;
		
		CallRecord cal;
		cal.day = (time[3]-'0')*10 + time[4]-'0';
		cal.hour = (time[6]-'0')*10 + time[7]-'0';
		cal.minute = (time[9]-'0')*10 + time[10]-'0';
		cal.status = stat[1] == 'n' ? true : false;
		
		//puts("=============================");
		//cout << cal.day << " " << cal.hour << " " << cal.minute << " " << cal.status << endl;
		//system("pause");	
		if (umap.find(name) == umap.end()) {
			vector <CallRecord> tmp;
			tmp.push_back(cal);
			umap[name] = tmp;
			users.push_back(name);
		} else {
			umap[name].push_back(cal);
		}
	}
	/*cout << umap.size() << endl;
	puts("-------------------------");
	for (auto it = umap.begin(); it != umap.end(); ++it) {
		cout << it->first << " " << it->second.size() << endl;
	}
	system("pause");*/
	
	calculateBill(users, rate, umap, time.substr(0, 2));
	return 0;
}
