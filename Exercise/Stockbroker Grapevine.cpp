#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 210;
const int INFINITE = 1000000;
int dis[MAX][MAX];
int ans[MAX];
int n;

void Floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}

int main(){
	while(cin >> n){
		if(!n){
			break;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = INFINITE;
			}
			dis[i][i] = 0;
		}
		for(int i = 1; i <= n; i++){
			int people;
			cin >> people;
			for(int j = 0; j < people; j++){
				int a,b;
				cin >> a >> b;
				dis[i][a] = b;
			}
		}
		Floyd();
		int MinTime = INFINITE,MinNum;
		memset(ans,0,sizeof(ans));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dis[i][j] > ans[i] && i != j){
					ans[i] = dis[i][j];
				}
			}
			if(ans[i] < MinTime){
				MinTime = ans[i];
				MinNum = i;
			}
		}
		if(MinTime == INFINITE){
			cout << "disjoint" << endl;
		}
		else{
			cout << MinNum << " " << MinTime << endl;
		}
	}
	return 0;
}
