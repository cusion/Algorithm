#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
#define MAX 100005
#define abs(a) ((a)>0 ? (a) : -(a))
#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))

// this method returns runtime error because of the prime selection procedure,
// we did not check the out-of-boundary problem. This time, it gets TLE.
// try to think about the difference between the AC solution and this one.

void getPrime(vector<bool> &isPrime) {
	int cnt = 0;
	vector<int> primes(isPrime.size());
	for (int i = 2; i < isPrime.size(); ++i) {
		if (isPrime[i]) primes[cnt++] = i;
		for (int j = 0; j < cnt && i*primes[j] < MAX; ++j) {
			isPrime[i*primes[j]] = false;
			if (i%primes[j] == 0) {
				break;
			}
		}
	}
	return ;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void primeSwap(vector<bool> &isPrime, vector<int> &num, vector<pair<int, int> > &out) {
	if (num.size() <= 1) {
		return ;
	}
	for (int i = 0; i < num.size(); ++i) {
		if (num[i] == i+1) {
			continue;
		} else {
			/*cout << i << " " << num[i] << endl;
			for (int j = 0; j < out.size(); ++j) {
				cout << out[j].first << " " << out[j].second << endl;
			}
			system("pause");*/
			if(isPrime[abs(num[i]-1-i)+1]) {
				out.push_back(pair<int, int>(min(i+1, num[i]), max(i+1, num[i])));
				swap(num[i], num[num[i]-1]);
			} else {
				/**** there is not always such solution
				for (int tmp = 0; tmp < num.size(); ++tmp) {
					if (isPrime[abs(tmp-num[i]+1)+1] && isPrime[abs(tmp-i)+1]) {
						out.push_back(pair<int, int>(min(tmp+1, i+1), max(tmp+1, i+1)));
						swap(num[tmp], num[i]);
						out.push_back(pair<int, int>(min(tmp+1, num[tmp]), max(tmp+1, num[tmp])));
						swap(num[tmp], num[num[tmp]-1]);
						out.push_back(pair<int, int>(min(tmp+1, i+1), max(tmp+1, i+1)));
						swap(num[tmp], num[i]);
						break;
					}
				}*/
				// the following method cheeted because we could not prove its truth
				// that it will always has a solution.
				// the final solution should be finding a shortest path from src to tar
				// and then swap then one by one
				int low, high, step = 0;
				int src = i, tar = num[i]-1;
				bool isChanged = false;
				for (int step = 0; step < num.size(); ++step) {
					if (!isPrime[step+1]) continue;
					for (int low = 0; low+step < num.size(); ++low) {
						high = low + step;
						if (isPrime[abs(src-low)+1] && isPrime[abs(tar-high)+1]) {
							if (step == 0) {
								swap(num[low], num[src]);
								swap(num[low], num[tar]);
								swap(num[low], num[src]);
								++low, ++src, ++tar;
								out.push_back(pair<int,int>(min(low, src), max(low, src)));
								out.push_back(pair<int,int>(min(low, tar), max(low, tar)));
								out.push_back(pair<int,int>(min(low, src), max(low, src)));
							} else {
								swap(num[src], num[low]);
								swap(num[low], num[high]);
								swap(num[high], num[tar]);
								swap(num[high], num[low]);
								swap(num[low], num[src]);
								++src, ++low, ++high, ++tar;
								out.push_back(pair<int,int>(min(src, low), max(src, low)));
								out.push_back(pair<int,int>(min(low, high), max(low, high)));
								out.push_back(pair<int,int>(min(high, tar), max(high, tar)));
								out.push_back(pair<int,int>(min(high, low), max(high, low)));
								out.push_back(pair<int,int>(min(low, src), max(low, src)));
							}
							isChanged = true;
							break;
						} else if (isPrime[abs(src-high)+1] && isPrime[abs(tar-low)+1]) {
							if (step == 0) {
								swap(num[src], num[low]);
								swap(num[low], num[tar]);
								swap(num[low], num[src]);
								++low, ++src, ++tar;
								out.push_back(pair<int,int>(min(low, src), max(low, src)));
								out.push_back(pair<int,int>(min(low, tar), max(low, tar)));
								out.push_back(pair<int,int>(min(low, src), max(low, src)));
							} else {
								swap(num[tar], num[low]);
								swap(num[low], num[high]);
								swap(num[high], num[src]);
								swap(num[high], num[low]);
								swap(num[low], num[tar]);
								++src, ++low, ++high, ++tar;
								out.push_back(pair<int,int>(min(tar, low), max(tar, low)));
								out.push_back(pair<int,int>(min(low, high), max(low, high)));
								out.push_back(pair<int,int>(min(high, src), max(high, src)));
								out.push_back(pair<int,int>(min(high, low), max(high, low)));
								out.push_back(pair<int,int>(min(low, tar), max(low, tar)));
							}
							isChanged = true;
							break;
						} // end if-elseif
					} // end inner for
					if (isChanged == true) break;
				} // end outer for
			}
			--i;
		}
	} // end main loop
	
	/*for (int i = 0; i < num.size(); ++i) {
		cout << num[i] << " " ;
	}puts("");*/
}

int main() {
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	vector<bool> isPrime(n+1, true);
	vector<pair<int,int> > out;
	getPrime(isPrime);
	primeSwap(isPrime, num, out);
	cout << out.size() << endl;
	for (int i = 0; i < out.size(); ++i) {
		cout << out[i].first << " " << out[i].second << endl;
	}
	return 0;
}
