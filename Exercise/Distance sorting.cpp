#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

struct Point{
	int x,y,z;
}AllPoint[10];

struct Distance{
	double len;
	Point PA,PB;
}dis[100];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> AllPoint[i].x >> AllPoint[i].y >> AllPoint[i].z;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			dis[cnt].PA = AllPoint[i];
			dis[cnt].PB = AllPoint[j];
			dis[cnt].len = sqrt((dis[cnt].PA.x - dis[cnt].PB.x) * (dis[cnt].PA.x - dis[cnt].PB.x) +
								(dis[cnt].PA.y - dis[cnt].PB.y) * (dis[cnt].PA.y - dis[cnt].PB.y) +
								(dis[cnt].PA.z - dis[cnt].PB.z) * (dis[cnt].PA.z - dis[cnt].PB.z));
			cnt++;
		}
	}
	bool flag = false;
	for(int i = 0; i < n; i++){
		flag = true;
		for(int j = cnt - 1; j > i; j--){
			if(dis[j].len > dis[j-1].len){
				flag = 0;
				Distance temp = dis[j];
				dis[j] = dis[j-1];
				dis[j-1] = temp;
			}
		}
		if(flag){
			break;
		}
	}
	for(int i = 0; i < cnt; i++){
		cout <<"("<<dis[i].PA.x<<","<<dis[i].PA.y<<","<<dis[i].PA.z<<")-("<<dis[i].PB.x<<","<<dis[i].PB.y<<","<<dis[i].PB.z<<")=";
		cout << setiosflags(ios::fixed);
		cout << setprecision(2) << dis[i].len << endl;
	}
	return 0;
}
