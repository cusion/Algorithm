#include <iostream>
#include <cstdio>

using namespace std;

/************ My Own Solution *******************
/* This solution uses each bits to seperate array
   into different groups, and finally get a group
   which has only one element, and this is the nu-
   mber we want.
   
void myswap(int *arr, int i, int j) {
	arr[i] += arr[j];
	arr[j] = arr[i] - arr[j];
	arr[i] = arr[i] - arr[j];
}

int singleNumber(int A[], int n) {
	int left = 0, right = n-1;
	int preLeft = 0, preRight = n-1, flag = 1;
	while (1) {
		left = preLeft;
		right = preRight;
		cout << flag << " " << left << " " << right << endl;
		while (left < right) {
			if ((A[left] & flag) == 0) {
				++left;
			} else {
				while (left < right && ((A[right] & flag) != 0))--right;
				if (left < right) {
					myswap(A, left, right);
					++left;
				}
			}
		}
		flag = flag << 1;
		
		cout << left << " " << right << endl;
		for (int i = 0; i < n; ++i) {
			cout << A[i] << " ";
		}puts("");
		
		if ((left - preLeft) == 1) {
			return A[left-1];
		} else if(left == preRight) {
			return A[preRight];
		}
		
		if ((left - preLeft) % 3 == 0) {
			preLeft = left;
		} else {
			preRight = left-1;
		}
	}
}
*/

/************* An Excellent Solution from the Web *******
/* The main idea of this solutio is to use binary operation
   to simulate arbitrary radix operations, in this case, we
   use variable 'one', 'two', 'three' to record those bits which have
   appeared equal to 1 once twice, and third respectively.
*/
int singleNumber(int A[], int n) {
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < n; ++i) {
		two |= (one&A[i]);
		one ^= A[i];              // this operation not only records appearance of 
		                          // bit equals to 1, but also remove those have appeared twice
		three = one & two;
		// before next iteration, we should clear bits that have repeatedly record 
		// bits 1 when it counts 3, to make sure the when next iteration starts to 
		// count, each variable record bits equal to 1 that appeared exactly equal to what that
		// variable means.
		one &= ~three;
		two &= ~three;
	}
	
	return one;
}

int main() {
	int arr[] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
	cout << singleNumber(arr, 10);
	return 0;
}
