#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const int MAX = 210;
const int INFINITE = 1000000;

struct Point{
	int x,y;
}point[MAX];
int n;
double dis[MAX][MAX];

double Distance(Point a, Point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void Floyd(){
	int visit[MAX];
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			dis[i][j] = dis[j][i] = Distance(point[i],point[j]);
		}
	}
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(dis[i][k] < dis[i][j] && (dis[k][j] < dis[i][j])){
					if(dis[i][k] < dis[k][j]){
						dis[i][j] = dis[j][i] = dis[k][j];
					}
					else{
						dis[i][j] = dis[j][i] = dis[i][k];
					}
				}
			}
		}
	}
}

int main(){
	int cur = 1;
	while(cin >> n){
		if(!n){
			break;
		}
		for(int i = 0; i < n; i++){
			cin >> point[i].x >> point[i].y;
		}
		Floyd();
		cout << "Scenario #" << cur++ << endl;
		cout << setiosflags(ios::fixed);
		cout << setprecision(3) << "Frog Distance = " << dis[0][1] << endl; 
		cout << endl;
	}
	return 0;
}