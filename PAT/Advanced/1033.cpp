#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Station{
	double price;
	double dist;
	
	friend bool operator <(Station a, Station b){
		return a.dist < b.dist;
	}
}station[505];

int goNextStation(int currentPos, double cap, double avg, double dist, int n)
{
	int i=currentPos+1;
	double len = cap*avg > dist-station[currentPos].dist? dist-station[currentPos].dist:cap*avg;
	while(i<n && station[i].dist-station[currentPos].dist<=len){
		if(station[i].price <= station[currentPos].price) return i;
		++i;
	}

	if(station[currentPos].dist + cap*avg >= dist) return currentPos;

	int Min=currentPos+1;
	for(i = currentPos+1; i<n && Min<n && station[i].dist - station[currentPos].dist <= len; ++i){
		Min = station[Min].price >= station[i].price? i:Min; 
	}

	if(Min<n && station[Min].dist-station[currentPos].dist <= len) return Min;
	
	return currentPos;
}

int main()
{
	double cap, dist, avg;
	int n;
	cin>>cap>>dist>>avg>>n;
	for(int i=0; i<n; ++i){
		cin>>station[i].price>>station[i].dist;
	}
	sort(station, station+n);
	/*for(int i = 0; i<n; ++i){
		cout<<station[i].dist<<" "<<station[i].price<<endl;
	}*/

	if(station[0].dist > 0){
		cout<<"The maximum travel distance = 0.00\n";
		return 0;
	}

	int car_pos = 0;
	double gas_left = 0;
	double cost = 0;
	while(1){
		//cout<<car_pos<<" "<<gas_left<<endl;
		int nextStation = goNextStation(car_pos, cap, avg, dist, n);

		if(nextStation == car_pos){
			if(station[car_pos].dist + cap*avg >= dist){
				cost += ((dist - station[car_pos].dist)/avg - gas_left)*station[car_pos].price;
				printf("%.2lf\n", cost);
				break;
			}else{
				printf("The maximum travel distance = %.2lf\n", station[car_pos].dist + cap*avg);
				break;
			}
		}
		
		if(station[nextStation].price > station[car_pos].price){
			cost += (cap-gas_left) * station[car_pos].price;
			gas_left = cap - (station[nextStation].dist-station[car_pos].dist)/avg;
		}else{
			cost += ((station[nextStation].dist-station[car_pos].dist)/avg - gas_left)*station[car_pos].price;
			gas_left=0;
		}
		car_pos = nextStation;
	}

	return 0;
}
