#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cmath>
#include <cstdlib>
using namespace std;

// I had been stucked on this problems for a long time, and the most important thing
// I learnt from this problem is firstly a more consideration about the input case.
// At first, I did not recognise that there would be duplicated pointed in the input,
// so I processed assuming all points are identical from each other, after I realised
// about the duplicated input, the second problem causes me to stuck for a much longer
// time, that is the hash operation on User-Defined Class. However, I finally get all
// these through and completed the final answer as below. There are still some aspects
// which need more attention, such as preserving the line as the standard form ax+by+c=0
// rather than the slope form.
// Interestingly is that, this problem could also be solved with O(n^3) complexity, which
// is firstly pick arbitrary two points to enumerate a line and count all the points which
// are aligned with this particluar line. As we have already known, this process contains
// many duplicated countings.

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

#define INF ((numeric_limits<double>::max)())

struct KeyHash {
 std::size_t operator()(const Point& k) const
 {
     long long kx = k.x;
     kx <<= 32;
     long long ky = k.y;
     return kx+ky;
 }
};
 
struct KeyEqual {
 bool operator()(const Point& lhs, const Point& rhs) const
 {
    return lhs.x == rhs.x && lhs.y == rhs.y;
 }
};

struct Slope {
	double k;
	double b;
	Slope(double kk, double bb) : k(kk), b(bb){}
};

struct KeyHashSlope {
 std::size_t operator()(const Slope& k) const
 {
     unsigned int a = (unsigned int)k.k;
     unsigned int b = (unsigned int)k.b;
	 return fabs(a-INF) < 1e-50 ? b : abs(a)+abs(b);
 }
};
 
struct KeyEqualSlope {
 bool operator()(const Slope& lhs, const Slope& rhs) const
 {
    return fabs(lhs.k -rhs.k) < 1e-50 && fabs(lhs.b - rhs.b) < 1e-50;
 }
};

int maxPoints(vector<Point> &points) {
	if (points.size() <= 2) return points.size();
	
	unordered_map <Slope, int, KeyHashSlope, KeyEqualSlope> slope;
	unordered_map <Slope, int, KeyHashSlope, KeyEqualSlope>::iterator itr;
	unordered_map <Point, int, KeyHash, KeyEqual> pointGroup;
	unordered_map <Point, int, KeyHash, KeyEqual>::iterator itr1, itr2;
	
	int n = points.size();
	
	for (int i = 0; i < n; ++i) {
		itr1 = pointGroup.find(points[i]);
		if (itr1 == pointGroup.end()) {
			pointGroup.insert(pair<Point, int> (points[i], 1));
		} else {
			itr1->second++;
		}
	}
	
	//cout << pointGroup.size() << endl;
	/*for (itr1 = pointGroup.begin(); itr1 != pointGroup.end(); ++itr1) {
		cout << itr1->first.x << " " << itr1->first.y << endl;
	}
	system("pause");*/
	
	if (pointGroup.size() <= 2) return n;
	
	for (itr1 = pointGroup.begin(); itr1 != pointGroup.end(); ++itr1) {
		unordered_set <double> firstFoundByItr1;
		unordered_set <double>::iterator foundItr;
		for (itr2 = next(itr1); itr2 != pointGroup.end(); ++itr2) {
			int dX = (itr2->first).x - (itr1->first).x;
			int dY = (itr2->first).y - (itr1->first).y;
			int cross = (itr2->first).x * (itr1->first).y - (itr2->first).y * (itr1->first).x;
			double curSlope = dX == 0 ? INF : (1.0*dY/dX);
			double b = dX == 0 ? 1.0*cross/(dY) : 1.0*cross/(dX);
			
			//cout << itr1->first.x << " " << itr1->first.y << " " << itr2->first.x;
			//cout << " " << itr2->first.y << endl;
			//system("pause");
			
			Slope cur3Slope(curSlope, b);
			itr = slope.find(cur3Slope);
			
			if (itr == slope.end()) {
				firstFoundByItr1.insert(curSlope);
				slope.insert(pair<Slope, int> (cur3Slope, itr1->second + itr2->second));
			} else {
				foundItr = firstFoundByItr1.find(curSlope);
				if (foundItr != firstFoundByItr1.end()) {
					itr->second += itr2->second;
				}
			}
		}
	}
	
	int maxNum = 0;
	for (itr = slope.begin(); itr != slope.end(); ++itr) {
		int num = itr->second;
		if (num > maxNum) {
			maxNum = num;
		}
	}
	
	return maxNum;
}

int main() {
	int x, y;
	vector <Point> points;
	scanf("(%d,%d)", &x, &y);
	Point tmp(x, y);
	points.push_back(tmp);
	while(scanf(",(%d,%d)", &x, &y)) {
		if(x == 100000) break;
		Point tmp(x, y);
		points.push_back(tmp);
	}
	cout << points.size() << endl;
	puts("===================");
	cout << maxPoints(points);
	return 0;
}
