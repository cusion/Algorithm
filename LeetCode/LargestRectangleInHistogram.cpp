#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

/******************** One O(NlogN) Solution of mine*******************
first sort the height with indx, and then use each height as a 
restriction to find its max range of indx, then update maxArea;

struct Node {
	int height;
	int indx;
	Node(int h, int ii):height(h), indx(ii){}
	friend bool operator < (Node a, Node b) {
		return a.height > b.height;
	}
};

int mergeLen(unordered_map<int,int> &umap, int left, int right) {
	int upper = right + umap[right] - 1;
	int lower = left - umap[left] + 1;
	int len = upper - lower + 1;
	umap[upper] = len;
	umap[lower] = len;
	return len;
}

int findMaxLen(unordered_map<int, int> &umap, int indx) {
	int maxLen = 1;
	umap.insert(pair<int, int>(indx, 1));
	if (umap.find(indx-1) != umap.end()) {
		maxLen = mergeLen(umap, indx-1, indx);
	}
	if (umap.find(indx+1) != umap.end()) {
		maxLen = mergeLen(umap, indx, indx+1);
	}
	
	return maxLen;
}

int largestRectangleArea(vector<int> &height) {
	if (height.empty()) {
		return 0;
	}
	vector <Node> hSorted;
	for (int i = 0; i < height.size(); ++i) {
		hSorted.push_back(Node(height[i], i));
	}
	sort(hSorted.begin(), hSorted.end());
	int maxArea = 0;
	unordered_map <int, int> umap;
	unordered_map <int, int>::iterator itr;
	for (int i = 0; i < hSorted.size(); ++i) {
		if (maxArea/hSorted.size() >= hSorted[i].height) { // if we use multiplication here, we may encounter an overflow problem
			break;
		}
		int maxLen = findMaxLen(umap, hSorted[i].indx);
		cout << "height " << hSorted[i].height << " len " << maxLen << endl;
		int tmpArea = maxLen * hSorted[i].height;
		maxArea = tmpArea > maxArea ? tmpArea : maxArea;
	}
	
	return maxArea;
}*/

/*********************** Description about divide and conquer method, codes coming soon********************/
// 1. find the minimum location lm of current [l, r] interval;
// 2. divided it into two parts [l, lm-1], [lm+1, r];
// 3. select the larger among the largest area of [l, lm-1] , [lm+1, r] and height[lm]*(l-r+1);
// this method would encounter a worst solution if the height is already in an increasing or descending order; and if we
// use naive O(N) finding method int the first step, then the worst case is O(N^2) complexity, however, we could further
// improve it with an O(logN) findint method using interval tree or tree-array algorithm. Then the worst case would be O(NlogN).

/************************* Final O(N) ******************/
// psuedo O(N) method
// compute the left most border and right most boarder of the current height bar; then compute the largest area rect
// this code would encounter a worst case with {2,3,2,3,2,3,2,3,2,3}, in this situation, calculate the left most border
// of the right most point would cost O(N^2) complexity, as is the case with the right most border of the left most point
/*int largestRectangleArea(vector<int> &height) {
	if (height.empty()) {
		return 0;
	}
	int leftBorder[height.size()];
	int rightBorder[height.size()];
	//initialize the border
	for (int i = 0; i < height.size(); ++i) {
		leftBorder[i] = i;
		rightBorder[i] = i;
	}
	// expand the left border
	for (int i = 1; i < height.size(); ++i) {
		while (leftBorder[i] > 0 && height[i] <= height[leftBorder[i]-1]) {
			leftBorder[i] = leftBorder[leftBorder[i]-1];
		}
	}
	// expand the right border
	for (int i = height.size()-2; i >= 0; --i) {
		while (rightBorder[i] < height.size()-1 && height[i] <= height[rightBorder[i]+1]) {
			rightBorder[i] = rightBorder[rightBorder[i]+1];
		}
	}
	// calculate the largest area
	int maxArea = 0;
	for (int i = 0; i < height.size(); ++i) {
		cout << leftBorder[i] << " " << rightBorder[i] << endl;
		int tmpArea = height[i] * (rightBorder[i]-leftBorder[i]+1);
		maxArea = maxArea > tmpArea ? maxArea : tmpArea;
	}
	
	return maxArea;
}*/

/**************************** Real O(N) ****************************/
// Major Idea: This is a more efficient implementation of the above method,
// in which, we only use a stack to store bars that need to confirm its right
// most border, for every time we meet a bar, if it is larger than the stack
// top, then its left most border is its index, if it is less than the stack
// top, then the right most border of the stack top is confirmed, then it needs
// to be popped out of the stack, and because its left most border is confirmed
// since when it is pushed into the stack, we have known its left most border, 
// we could calculate its area like what we did in the previouse method.

// two stack version
/*int largestRectangleArea(vector<int> &h) {
	if (h.empty()) {
		return 0;
	}
	if (h.size() == 1) {
		return h[0];
	}
	h.push_back(0);
	stack <int> height;
	stack <int> leftBorder;
	int maxArea = 0;
	for (int i = 0; i < h.size(); ++i) {
		if (height.empty() || h[i] > height.top()) {
			height.push(h[i]);
			leftBorder.push(i);
		} else if (h[i] < height.top()) {
			int tmpArea;
			int curLeft;;
			while (!height.empty() && h[i] <= height.top()) {
				curLeft = leftBorder.top();
				tmpArea = height.top()*(i-curLeft);   // actually it is curHeight*(i-1 - curLeft + 1);
				maxArea = maxArea > tmpArea ? maxArea : tmpArea;
				height.pop();
				leftBorder.pop();
			}
			height.push(h[i]);
			leftBorder.push(curLeft);
		}
	}
	
	return maxArea;
}*/

// one stack version, we only need to record the left border;
int largestRectangleArea(vector<int> &h) {  
    stack<int> S;  
    h.push_back(0);  
    int sum = 0;  
    for (int i = 0; i < h.size(); i++) {  
    	if (S.empty() || h[i] > h[S.top()]) S.push(i);  
        else {  
        	int tmp = S.top();
        	S.pop();
        	int tmpArea = h[tmp]*(S.empty()? i : i-1-S.top());        // left border is the previous index+1, and right one is i-1
       		sum = max(sum, tmpArea); 
       		//cout << i << " " << (S.empty()?0:S.top()) << " " << tmpArea << endl;
        	i--;
    	}  
	}  
    return sum;  
}

int main() {
	int arr[] = {1,2,5,7,3,5,4};
	vector <int> height(arr, arr+7);
	cout << largestRectangleArea(height) << endl;
	return 0;
}
