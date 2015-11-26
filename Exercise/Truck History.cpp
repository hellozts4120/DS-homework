#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 2010, INFINITE = 1000000;
int Dis[MAX][MAX];
char Word[MAX][7];
int n;

int Weight(int a, int b){
	int cnt = 0;
	for(int i = 0; i < 7; i++){
		if(Word[a][i] != Word[b][i]){
			cnt++;
		}
	}
	return cnt;
}

int Prim(){
	int sum = 0, pos = 0, Min;
	int visited[MAX], least[MAX];
	memset(visited,0,sizeof(visited));
	visited[0] = 1;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			least[i] = Dis[i][pos];
		}
	}
	for(int i = 0; i < n-1; i++){
		Min = INFINITE;
		for(int j = 0; j < n; j++){
			if(!visited[j] && least[j] < Min){
				Min = least[j];
				pos = j;
			}
		}
		sum += Min;
		visited[pos] = 1;
		for(int j = 0; j < n; j++){
			if(!visited[j] && Dis[pos][j] < least[j]){
				least[j] = Dis[pos][j];
			}
		}
	}
	return sum;
}

int main(){
	while(cin >> n){
		if(!n){
			break;
		}
		for(int i = 0; i < n; i++){
			cin >> Word[i];
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j){
					Dis[i][i] = 0;
					continue;
				}
				Dis[i][j] = Dis[j][i] = Weight(i, j);
			}
		}
		int ans = Prim();
		cout << "The highest possible quality is 1/" << ans << "." << endl;
	}
	return 0;
}