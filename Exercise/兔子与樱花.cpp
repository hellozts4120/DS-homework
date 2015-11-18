#include<iostream>
#include<cstring>
#include<map>
#include<string>
using namespace std;

const int MAX = 35, INFINITE = 100000;
int n;
map<string,int>VtoN;
map<int,string>NtoV;

struct Point{
	int len;
	int pre;
}dis[MAX][MAX];

void Init(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dis[i][j].pre = -1;
			if(i == j){
				dis[i][j].len = 0;
			}
			else{
				dis[i][j].len = INFINITE;
			}
		}
	}
}

void Floyd(){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(dis[i][j].len > (dis[i][k].len + dis[k][j].len)){
					dis[i][j].len = dis[i][k].len + dis[k][j].len;
					dis[i][j].pre = dis[k][j].pre;
				}
			}
		}
	}
}

void Print(int a,int b){
	if(a == b){
		cout << NtoV[a];
		return;
	}
	Print(a,dis[a][b].pre);
	cout << "->(" << dis[dis[a][b].pre][b].len << ")->" << NtoV[b];

}

int main(){
	int p,q,r;
	int len;
	cin >> p;
	string from,to;
	for(int i = 0; i < p; i++){
		cin >> from;
		VtoN[from] = i;
		NtoV[i] = from;
	}
	n = p;
	Init();
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> from >> to >> len;
		if(dis[VtoN[from]][VtoN[to]].len > len){
			dis[VtoN[from]][VtoN[to]].len = len;
			dis[VtoN[to]][VtoN[from]].len = len;
			dis[VtoN[from]][VtoN[to]].pre = VtoN[from];
			dis[VtoN[to]][VtoN[from]].pre = VtoN[to];
		}
	}
	Floyd();
	cin >> r;
	while(r--){
		cin >> from >> to;
		Print(VtoN[from],VtoN[to]);
		cout << endl;
	}
	return 0;
}