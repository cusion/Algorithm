#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Person {
    int stunum;
    int de;
    int cai;
    friend bool operator < (Person a, Person b) {
		if (a.de + a.cai > b.de + b.cai) return true;
		else if (a.de + a.cai < b.de + b.cai) return false;
		else {
			if (a.de > b.de) return true;
			else if (a.de < b.de) return false;
			else {
				if (a.stunum > b.stunum) return false;
				else return true;
			}
		}
	}       
}stu[4][100002];
int ind[4];

int main()
{
    int N, H, L;
    cin >> N >> L >> H;
    Person tmp;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        cin >> tmp.stunum >> tmp.de >> tmp.cai;
        if (tmp.de >= L && tmp.cai >= L) {
            cnt++;
            if (tmp.de >= H && tmp.cai >= H){
                stu[0][ind[0]++] = tmp;
            } else if (tmp.de >= H) {
                stu[1][ind[1]++] = tmp;          
            } else if (tmp.de >= tmp.cai) {
                stu[2][ind[2]++] = tmp;
            } else {
                stu[3][ind[3]++] = tmp;
            }
        }
    }
    
    cout << cnt << endl;
    for (int i = 0; i < 4; ++i) {
        if (ind[i]) {
            sort(stu[i], stu[i]+ind[i]);
            for (int j = 0; j < ind[i]; ++j) {
                //cout << stu[i][j].stunum << " " << stu[i][j].de << " " << stu[i][j].cai << endl;
                printf("%d %d %d\n", stu[i][j].stunum, stu[i][j].de, stu[i][j].cai);
            }
        }    
    }
    
    system("pause");
    
    return 0;
}
