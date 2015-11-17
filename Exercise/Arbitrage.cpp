#include<iostream>
#include<cstring>
using namespace std;

const int INFINITE = 1000000;
const int MAX = 35;
double dis[MAX][MAX];
char Bank[MAX][100];
int n,m;

void Floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dis[i][j] < dis[i][k] * dis[k][j]){
					dis[i][j] = dis[i][k] * dis[k][j];
				}
			}
		}
	}
}

void InitBank(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j){
				dis[i][j] = 1;
			}
			else{
				dis[i][j] = 0;
			}
		}
	}
}

void InitChange(){
	char from[100],to[100];
	int j,k;
	double change;
	for(int i = 1; i <= m; i++){
		cin >> from >> change >> to;
		for(j = 1; j <= n; j++){
			if(!strcmp(Bank[j],from)){
				break;
			}
		}
		for(k = 1; k <= n; k++){
			if(!strcmp(Bank[k],to)){
				break;
			}
		}
		dis[j][k] = change;
	}
}

int main(){
	int cases = 1;
	while((cin >> n) && n){
		for(int i = 1; i <= n; i++){
			cin >> Bank[i];
		}
		InitBank();
		cin >> m;
		InitChange();
		Floyd();
		cout << "Case " << cases++ << ": ";
		bool Find = false;
		for(int i = 1; i <= n; i++){
			if(dis[i][i] > 1){
				Find = true;
				break;
			}
		}
		if(Find == true){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
		//cout << endl;
	}
	return 0;
}