#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval &a, const Interval &b) {
	return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &intervals) {
	vector<Interval> ret;
	if (intervals.empty()) {
		return ret;
	}
	sort(intervals.begin(), intervals.end(), cmp);
	int cur = 0;
	int next = 1;
	while (cur < intervals.size()) {
		//cout << cur << endl;
		next = cur + 1;
		if (next < intervals.size() && intervals[cur].end >= intervals[next].start) {
			while (next < intervals.size() && intervals[cur].end >= intervals[next].start) {
				if (intervals[cur].end < intervals[next].end) {
					intervals[cur].end = intervals[next].end;
				}
				++next;
			}
		}
		ret.push_back(intervals[cur]);
		cur = next;
	}
	
	return ret;
}

int main() {
	vector<Interval> a;
	a.push_back(Interval(1, 3));
	a.push_back(Interval(8, 10));
	a.push_back(Interval(2, 6));
	a.push_back(Interval(15, 18));
	vector<Interval> ret = merge(a);
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i].start << " " << ret[i].end << endl;
	}
	return 0;
}
