#include<iostream>
#include<cstring>
using namespace std;

int Dis[200][200];
int visit[200],n;
int sum = 0;

bool Check(int a, int b, int &x){	//判断a,b两个叶结点是否具有公共的直接父节点，若有，返回a到其公共父节点的距离
	bool flag = true;
	for(int i = 0; i < n; i++){
		if(!visit[i] && i!=a && i!=b){
			if(flag){
				x = Dis[a][i] - (Dis[a][i] + Dis[b][i] - Dis[a][b]) / 2;
				flag = false;
			}
			else if(x != Dis[a][i] - (Dis[a][i] + Dis[b][i] - Dis[a][b]) / 2){
				return false;	//非为直接父节点时报错
			}
		}
	}
	return true;
}

int main(){
	while(cin >> n){
		if(!n){
			break;
		}
		sum = 0;
		memset(visit,0,sizeof(visit));
		for(int i = 0; i < n; i++){
			Dis[i][i] = 0;
			for(int j = i+1; j < n; j++){
				cin >> Dis[i][j];
				Dis[j][i] = Dis[i][j];
			}
		}
		int a,b,x;
		while(1){
			bool flag = false;
			for(a = 0; a < n; a++){
				if(visit[a]){
					continue;
				}
				for(b = a+1; b < n; b++){	//查找具有公共父节点的两个叶节点并将其合并
					if(visit[b]){
						continue;
					}
					if(Check(a, b, x)){
						flag = true;
						break;
					}
				}
				if(flag){
					break;
				}
			}
			if(!flag){
				break;
			}
			visit[a] = visit[b] = true;
			sum += Dis[a][b];
			for(int i = 0; i < n; i++){
				if(!visit[i]){		//加入新结点n,代替a,b（作为其父节点）
					Dis[i][n] = Dis[n][i] = Dis[i][a] - x;
				}
			}
			n++;
		}
		cout << sum << endl;
	}
	return 0;
}