#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;

double getRet(int A[], int B[], int mida, int midb, int m, int n) {
	if (mida < 0) {
		if ((m+n)%2) {
			return B[midb]*1.0;
		} else {
			return (B[midb]+B[midb-1])*1.0/2;
		}
	}
	
	if (midb < 0) {
		if ((m+n)%2) {
			return A[mida]*1.0;
		} else {
			return (A[mida]+A[mida-1])*1.0/2;
		}
	}
	
	if ((m+n)%2) {
		if (A[mida] > B[midb]) {
			if (mida == 0) {
				return B[midb]*1.0;
			} else {
				return max(B[midb], A[mida-1]);
			}
		} else {
			if (midb == 0) {
				return A[mida]*1.0;
			} else {
				return max(A[mida], B[midb-1]);
			}
		}
	} else {
		vector <int> cand;
		if (mida+midb < ((m+n)>>1)) {
			
		}
		sort(cand.begin(), cand.end(), greater<int>());
		puts("------------- cand --------------");
		for (int i = 0; i < cand.size(); ++i) {
			cout << cand[i] << " ";
		}puts("");
		puts("---------------------");
		return (cand[1]+cand[2])*1.0/2;
	}
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	if (m == 0) {
		return ((B[n-1-n/2]+B[n/2])*1.0/2);
	}
	if (n == 0) {
		return ((A[m-1-m/2]+A[m/2])*1.0/2);
	}
	int left = 0;
	int right = min(m, n);
	bool flag = (m >= n);
	int mida = m/2;
	int midb = n/2;
	puts("******* test *********");
	while (left <= right) {
		cout << mida << " " << midb << endl;
		if (A[mida] <= B[midb]) {
			if (mida == m-1 || B[midb] <= A[mida+1]) {
				break;
			} else {
				if (flag) {
					if (midb == 0) {
						midb--;
						//mida++;
						break;
					}
					right = midb - 1;
					midb = (left + right) >> 1;
					mida += right - midb + 1;
				} else {
					left = mida + 1;
					mida = (left+right) >> 1;
					midb -= mida-left+1;
				}
			}
		} else if (A[mida] > B[midb]) {
			if (midb == n-1 || A[mida] <= B[midb+1]) {
				break;
			} else {
				if (flag) {
					left = midb + 1;
					midb = (left+right) >> 1;
					mida -= midb-left+1;
				} else {
					if (mida == 0) {
						mida--;
						//midb++;
						break;
					}
					right = mida - 1;
					mida = (left + right) >> 1;
					midb += right-mida+1;
				}
			}
		}
	}
	puts("out");
	cout << mida << " " << midb << endl;
	puts("******************************");
	
	return getRet(A, B, mida, midb, m, n);
}

double compareFindMedian(int A[], int m, int B[], int n) {
	if (m == 0) {
		return ((B[n-1-n/2]+B[n/2])*1.0/2);
	}
	if (n == 0) {
		return ((A[m-1-m/2]+A[m/2])*1.0/2);
	}
	vector <int> seq;
	int inda = 0;
	int indb = 0;
	while (inda < m && indb < n) {
		if (A[inda] <= B[indb]) {
			seq.push_back(A[inda++]);
		} else {
			seq.push_back(B[indb++]);
		}
	}
	while (inda < m) {
		seq.push_back(A[inda++]);
	}
	while (indb < n) {
		seq.push_back(B[indb++]);
	}
	
	int len = seq.size();
	return (seq[len-1-len/2] + seq[len/2])*1.0/2;
}

int main() {
	int m, n, *A, *B;
	srand(time(0));
	m = rand()%20;
	n = rand()%20;
	A = NULL;
	B = NULL;
	if (m > 0) {
		A = new int[m];
		for (int i = 0; i < m; ++i) {
			A[i] = rand()%20;
		}
		sort(A, A+m);
		cout << m << " : ";
		for (int i = 0; i < m; ++i) {
			cout << A[i] << " ";
		}
		puts("");
	}
	if (n > 0) {
		B = new int[n];
		for (int i = 0; i < n; ++i) {
			B[i] = rand()%20;
		}
		sort(B, B+n);
		cout << n << " : ";
		for (int i = 0; i < n; ++i) {
			cout << B[i] << " ";
		}
		puts("");
	}
	system("pause");
	puts("======================================");
	cout << findMedianSortedArrays(A, m, B, n) << endl;
	cout << compareFindMedian(A, m, B, n) << endl;
	puts("+++++++++++++++++++++++++++++++++++++++");
	
	if (A) {
		delete[] A;
	}
	if (B) {
		delete[] B;
	}
	return 0;
}
