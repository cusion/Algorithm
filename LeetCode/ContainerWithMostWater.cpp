#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

/**************** This is a wrong solution *************
 because it does not consider either the case of equal
 value with different position or the case of small value
 but large position distance

int maxArea(vector<int> &height) {
	if (height.size() <= 1) {
		return 0;
	}
	int maxH, secH;
	maxH = secH = height[0];
	int maxP = 0, secP = 0;
	for (int i = 1; i < height.size(); ++i) {
		if (height[i] > maxH) {
			secH = maxH;
			maxH = height[i];
			secP = maxP;
			maxP = i;
		} else {
			if (height[i] > secH) {
				secH = height[i];
				secP = i;
			}
		}
	}
	
	return secH*abs(maxP-secP);
}*/

/******************* TLE version *******************
int maxArea(vector <int> &height) {
	if (height.size() <= 1) {
		return 0;
	}
	int maxArea = 0;
	for (int i = 0; i < height.size(); ++i) {
		for (int j = i+1; j < height.size(); ++j) {
			int tmpArea = (j-i)*min(height[i], height[j]);
			if (maxArea < tmpArea) {
				maxArea = tmpArea;
			}
		}
	}
	return maxArea;
}*/

/***************** Passed, but rather ugly many restrictions attached method *******************
int maxArea(vector <int> &height) {
	if (height.size() <= 1) {
		return 0;
	}
	int maxArea = 0;
	int maxHeight = height[0];
	vector <int> leftWallPos;
	leftWallPos.push_back(0);
	for (int i = 1; i < height.size(); ++i) {
		maxHeight = maxHeight < height[i] ? height[i]:maxHeight;
		if (height[i] > height[i-1]) {
			leftWallPos.push_back(i);  // This condition could be further restricted to (height[i] > leftWallPos[leftWallPos.size()-1])
		}
	}
	vector <int> rightWallPos;
	rightWallPos.push_back(height.size()-1);
	for (int i = height.size()-2; i >= 0; --i) {
		if (height[i] > height[i+1]) {
			rightWallPos.push_back(i); // This condition could be further restricted to (height[i] > leftWallPos[leftWallPos.size()-1])
		}
	}
	
	// The following code could be further optimized if we keep record of 
	// Maxheight not only for the whole sequence but rather all those after
	// leftWallPos[i] and all those before rightWallPos[j];
	for (int i = 0; i < leftWallPos.size(); ++i) {
		if (maxArea >= maxHeight*(height.size()-leftWallPos[i]-1)) {
			break;
		}
		for (int j = 0; j < rightWallPos.size(); ++j) {
			if (rightWallPos[j] <= leftWallPos[i] || maxArea >= maxHeight*rightWallPos[j]) {
				break;
			}
			int tmpArea = (rightWallPos[j]-leftWallPos[i]) * min(height[rightWallPos[j]],height[leftWallPos[i]]);
			if (maxArea < tmpArea) {
				maxArea = tmpArea;
			}
		}
	}
	
	/*************** Another TLE version **********************
	for (int i = height.size()-1; i > 0; --i) {
		if (maxArea >= maxHeight*i) {
			break;
		}
		for (int j = 0; j+i <height.size(); ++j) {
			int tmpArea = i*min(height[j+i], height[j]);
			if (maxArea < tmpArea) {
				maxArea = tmpArea;
			}
		}
	}
	
	return maxArea;
}*/

/************* A further optimized method of the previous one, but still not the best ************
int maxArea(vector <int> &height) {
	if (height.size() <= 1) {
		return 0;
	}
	int maxArea = 0;
	vector <int> leftWallPos;
	int maxLeft[height.size()];
	leftWallPos.push_back(0);
	maxLeft[0] = height[0];
	for (int i = 1; i < height.size(); ++i) {
	    maxLeft[i] = max(maxLeft[i-1], height[i]);
		if (height[i] > height[leftWallPos[leftWallPos.size()-1]]) {
			leftWallPos.push_back(i);
		}
	}
	vector <int> rightWallPos;
	int maxRight[height.size()];
	rightWallPos.push_back(height.size()-1);
	maxRight[height.size()-1] = height[height.size()-1];
	for (int i = height.size()-2; i >= 0; --i) {
	    maxRight[i] = max(maxRight[i+1], height[i]);
		if (height[i] > height[rightWallPos[rightWallPos.size()-1]]) {
			rightWallPos.push_back(i);
		}
	}
	
	for (int i = 0; i < leftWallPos.size(); ++i) {
		if (maxArea >= maxRight[leftWallPos[i]]*(height.size()-leftWallPos[i]-1)) {
			break;
		}
		for (int j = 0; j < rightWallPos.size(); ++j) {
			if (rightWallPos[j] <= leftWallPos[i]  || maxArea >= maxLeft[rightWallPos[j]]*rightWallPos[j]) {
				break;
			}
			int tmpArea = (rightWallPos[j]-leftWallPos[i]) * min(height[rightWallPos[j]],height[leftWallPos[i]]);
			if (maxArea < tmpArea) {
				maxArea = tmpArea;
			}
		}
	}
	return maxArea;
}*/

// A nice O(NlgN) solution, though there exists an even better O(N) solution
/*struct Node {
	int height;
	int indx;
	Node (int h, int ii):height(h), indx(ii){}
	friend bool operator < (Node a, Node b) {
		return a.height > b.height;
	}
};
int maxArea(vector <int> &height) {
	if (height.size() <= 1) {
		return 0;
	}
	vector <Node> nodes;
	for (int i = 0; i < height.size(); ++i) {
		nodes.push_back(Node(height[i], i));
	}
	sort(nodes.begin(), nodes.end());
	int left = min(nodes[0].indx, nodes[1].indx);
	int right = max(nodes[0].indx, nodes[1].indx);
	int maxArea = nodes[1].height*(right-left);
	for (int i = 2; i < nodes.size(); ++i) {
		int indx = nodes[i].indx;
		int width = 0;
		if (indx > right) {
			right = indx;
			width = right - left;
		} else if (indx < left) {
			left = indx;
			width = right - left;
		} else {
			width = max(indx-left, right-indx);
		}
		maxArea = max(maxArea, nodes[i].height*width);
	}
	
	return maxArea;
}*/

// The Final BEST SOLUTION, O(N) complexity
int maxArea(vector <int> &height) {
	if (height.size() <= 1) {
		return 0;
	}
	int left = 0;
	int right = height.size() - 1;
	int maxArea = 0;
	while (left < right) {
		maxArea = max(maxArea, min(height[left], height[right])*(right-left));
		if (height[left] > height[right]) {
			right--;
		} else {
			left++;
		}
	}
	
	return maxArea;
}

int main() {
	return 0;
}
