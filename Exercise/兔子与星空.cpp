#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 26,INFINITY = 1000000;
int dis[MAX][MAX];
int least[MAX],visited[MAX];
int n;

int Prim(){
	memset(visited,0,sizeof(visited));
	int sum = 0,pos = 0,min;
	visited[0] = 1;
	for(int i = 0; i < n; i++){
		if(i != pos){
			least[i] = dis[pos][i];
		}
	}
	for(int i = 0; i < n-1; i++){
		min = INFINITY;
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
	cin >> n;
	char t1,t2;
	int k1,k2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j){
				dis[i][j] = 0;
			}
			else{
				dis[i][j] = INFINITY;
			}
		}
	}
	for(int i = 0; i < n - 1; i++){
		cin >> t1 >> k1;
		for(int j = 0; j < k1; j++){
			cin >> t2 >> k2;
			dis[t1 - 'A'][t2 - 'A'] = k2;
			dis[t2 - 'A'][t1 - 'A'] = k2;
		}
	}
	cout << Prim() << endl;
	return 0;
}