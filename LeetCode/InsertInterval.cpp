#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// This method should have a simpler form cause we could immediately search for the 
// interval in which the start and end of the new Interval locates
/*vector <Interval> insert(vector <Interval> intervals, Interval newInterval) {
	vector <Interval> ret;
	if (intervals.empty()) {
		ret.push_back(newInterval);
		return ret;
	}
	if (newInterval.start > intervals[intervals.size()-1].end) {
		intervals.push_back(newInterval);
		ret = intervals;
	} else if (newInterval.end < intervals[0].start) {
		//puts("test");
		intervals.insert(intervals.begin(), newInterval);
		ret = intervals;
	} else {
		int left, right;
		int small = 0;
		int big = intervals.size()-1;
		left = (small + big) >> 1;
		while(small < big) {
			left = (small + big) >> 1;
			if (intervals[left].end == newInterval.start) {
				break;
			} else if (intervals[left].end < newInterval.start) {
				small = left + 1;
			} else {
				big = left;
			}
		}
		left = small == big ? small : left;
		//puts("test");
		small = 0;
		big = intervals.size() - 1;
		right = (small + big) >> 1;
		while (small < big) {
			right = (small + big) >> 1;
			if (intervals[right].start == newInterval.end) {
				break;
			} else if (intervals[right].start < newInterval.end) {
				cout << "small " << small << " big " << big << endl;
				if (small == right) {
					if (intervals[big].start <= newInterval.end) {
						right = big;
					}
					break;
				}
				small = right;
			} else {
				big = right - 1;
			}
		}
		right = small == big ? small : right;
		for (int i = 0; i < left; ++i) {
			ret.push_back(intervals[i]);
		}
		cout << left << " " << right << endl;
		puts("=======================");
		newInterval.start = intervals[left].start < newInterval.start ? intervals[left].start : newInterval.start;
		newInterval.end = intervals[right].end > newInterval.end ? intervals[right].end : newInterval.end;
		ret.push_back(newInterval);
		for (int i = right + 1; i < intervals.size(); ++i) {
			ret.push_back(intervals[i]);
		}
	}
	
	return ret;
}*/

/**************** Output Limit Exceeded, now correct ********************/
vector <Interval> insert(vector <Interval> intervals, Interval newInterval) {
	if (intervals.empty()) {
		intervals.push_back(newInterval);
		return intervals;
	}
	
	if (intervals[0].start > newInterval.end) {
		intervals.insert(intervals.begin(), newInterval);
		return intervals;
	} else if (intervals[intervals.size()-1].end < newInterval.start) {
		intervals.push_back(newInterval);
		return intervals;
	}
	
	int ind = 0;
	while (intervals[ind].end < newInterval.start) {
		++ind;
	}
	
	//cout << ind << endl;
	if (intervals[ind].start > newInterval.end) {
		intervals.insert(intervals.begin()+ind, newInterval);
		return intervals;
	}
	
	if (intervals[ind].start > newInterval.start) {
		intervals[ind].start = newInterval.start;
	}
	if (intervals[ind].end < newInterval.end) {
		intervals[ind].end = newInterval.end;
	}
	
	++ind;
	while (ind < intervals.size() && intervals[ind].end < newInterval.end) {
		intervals.erase(intervals.begin() + ind);
	}
	if (ind < intervals.size() && intervals[ind].start <= newInterval.end) {
		intervals[ind-1].end = intervals[ind].end;
		intervals.erase(intervals.begin() + ind);
	}
	
	return intervals;
}

int main() {
	vector <Interval> vec;
	vec.push_back(Interval(2, 4));
	vec.push_back(Interval(5, 7));
	//vec.push_back(Interval(8, 10));
	vec.push_back(Interval(11, 13));
	//vec.push_back(Interval(12, 16));
	vector <Interval> ret = insert(vec, Interval(8, 10));
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i].start << " " << ret[i].end << endl;
	}
	return 0;
}
