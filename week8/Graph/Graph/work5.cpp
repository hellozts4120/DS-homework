#include<iostream>
using namespace std;

const int MAXP = 30,INFINITE = 100000;
int Dist[MAXP][MAXP];	//记录两点最短距离

void InitDist(int v){	//初始状态，图中都是孤立的点，没有边；自己到自己的距离为0，到其他点的距离为无穷大。
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			Dist[i][j] = INFINITE;
		}
	}
	for(int i = 0; i < v; i++){
		Dist[i][i] = 0;
	}
}

void BuildPath(int from, int to, int dist){
	if(Dist[from][to] > dist){
		Dist[from][to] = dist;
		Dist[to][from] = dist;
	}
}

void Floyd(int v){		//所求的点即为最短路径最大的两个点之一
	for(int k = 0; k < v; k++){
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				if(Dist[i][j] > (Dist[i][k] + Dist[k][j])){
					Dist[i][j] = Dist[k][j] + Dist[i][k];
				}
			}
		}
	}
}

int main(){
	int n;
	int from,to;
	int dist;
	cout << "输入小区个数：";
	cin >> n;
	InitDist(n);
	int q;
	cout << "输入路的总数：";
	cin >> q;
	cout << "输入两小区序号(最小下标从0开始)，及它们之间的路径长短：" << endl;
	for(int i = 0; i < q; i++){
		cin >> from >> to >> dist;
		BuildPath(from,to,dist);
	}
	Floyd(n);
	int MaxDist = INFINITE,Max1 = 0,MaxNum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(Dist[i][j] != INFINITE){
				if(Max1 < Dist[i][j]){
					Max1 = Dist[i][j];
				}
			}
		}
		if(MaxDist > Max1){
			MaxDist = Max1;
			MaxNum = i;
		}
		Max1 = 0;
	}
	cout << "合适的点为：" <<MaxNum << endl;
	return 0;
}
