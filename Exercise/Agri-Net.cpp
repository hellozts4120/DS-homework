#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 110;
const int INFINITE = 1000000;
int dis[MAX][MAX];
int visited[MAX],least[MAX],n;

int Prim(){
	memset(visited,0,sizeof(visited));
	memset(least,INFINITE,sizeof(least));
	int sum = 0,pos = 0,min;
	visited[0] = 1;
	for(int i = 0; i < n; i++){
		if(i != pos){
			least[i] = dis[pos][i];
		}
	}
	for(int i = 0; i < n - 1; i++){
		min = INFINITE;
		for(int j = 0; j < n; j++){
			if(!visited[j] && min > least[j]){
				pos = j;
				min = least[j];
			}
		}
		sum += min;
		visited[pos] = 1;
		for(int j = 0; j < n; j++){
			if(!visited[j] && least[j] > dis[pos][j]){
				least[j] = dis[pos][j];
			}
		}
	}
	return sum;
}

int main(){
	while(cin >> n){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> dis[i][j];
			}
		}
		cout << Prim() << endl;
	}
	return 0;
}