#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Data{
	int b;
	int p;
	bool friend operator <(Data a, Data b){
		return a.p < b.p;
	}
};

int main()
{
	//freopen("in.txt", "r", stdin);
	Data data[105][105];
	int ab[105*105];
	int maxb[105];
	int t,n,m[105];
	cin>>t;
	while(t--){
		cin>>n;
		int ab_ind = 0;
		for(int i = 0; i<n; ++i){
			cin>>m[i];
			maxb[i]=0;
			for(int j = 0; j<m[i]; ++j){
				cin>>data[i][j].b;
				cin>>data[i][j].p;
				ab[ab_ind++]=data[i][j].b;
				maxb[i] = maxb[i] < data[i][j].b? data[i][j].b:maxb[i];
			}

			sort(data[i], data[i]+m[i]);
		}

		sort(ab, ab+ab_ind);
		sort(maxb, maxb+n);

		int search_index = 0;
		double res = 0;
		while(search_index<ab_ind && ab[search_index]<=maxb[0]){
			if(search_index>0 && ab[search_index -1] == ab[search_index]){
				search_index++;
				continue;
			}
			double	sum = 0;
			int i = 0;
			for(; i<n; ++i){
				int j = 0;
				for( ; j<m[i]; ++j){
					if(data[i][j].b >= ab[search_index]){
						sum += data[i][j].p;
						break;
					}
				}
				if(j >= m[i])break;
			}

			if(i>=n){
				if(res<ab[search_index]/sum) res = ab[search_index]/sum;
			}

			search_index++;
		}

		printf("%.3lf\n", res);
	}
	return 0;
}
