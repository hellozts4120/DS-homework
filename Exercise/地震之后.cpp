/*	有向图的MST，不能使用Prim或Kruskal，使用最小树形图的朱刘算法	*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX = 105, INFINITE = 1000000;
int n,m;
double Dis[MAX][MAX];
int pre[MAX];	//权值最小的前驱边;
bool visited[MAX];	//该点是在环中还是环外;
bool inc[MAX];	//该点是否已经被删除;


struct Node{
	int x,y;
}Village[MAX];

double CalWay(int x, int y){
	return sqrt((Village[x].x - Village[y].x)*(Village[x].x - Village[y].x) + (Village[x].y - Village[y].y)*(Village[x].y - Village[y].y));
}

void DFS(int x){	//递归深搜，判断是否能够生成MST
	visited[x] = true;
	for(int i = 1; i <= n; i++){
		if(!visited[i] && Dis[x][i] < INFINITE){
			DFS(i);
		}
	}
	return;
}


double DirectedMST(int x){
	memset(visited,0,sizeof(visited));
	memset(inc,0,sizeof(inc));
	DFS(x);		//深搜，判断是否能够形成MST
	double sum = 0;
	for(int i = 1; i <= n; i++){	//若不能生成MST，直接输出-1（不能生成）
		if(!visited[i]){
			return -1;
		}
	}
	memset(visited,0,sizeof(visited));	//若能够生成，则继续
	while(1){
		for(int i = 1; i <= n; i++){	//1.找每个顶点的最小前驱边。
			if(i != x && !inc[i]){
				Dis[i][i] = INFINITE;
				pre[i] = i;
				for(int j = 1; j <= n; j++){
					if(!inc[j] && Dis[pre[i]][i] > Dis[j][i]){
						pre[i] = j;
					}
				}
			}
		}
		int i;		//2.判断是否有环
		for(i = 1; i <= n; i++){
			if(i != x && !inc[i]){
				int j = i, cur = 0;
				while(j != x && pre[j] != i && cur <= n){
					j = pre[j];
					cur++;
				}
				if(j == x || cur > n){		//此时以i为起始点遍历无环
					continue;
				}
				break;	//有环存在
			}
		}
		if(i > n){		//3.此时无环，直接遍历输出答案
			for(int j = 1; j <= n; j++){
				if(j != x && !inc[j]){
					sum += Dis[pre[j]][j];
				}
			}
			return sum;
		}
		int j = i;		//4.有环，则进行收缩
		memset(visited,0,sizeof(visited));
		do{
			sum += Dis[pre[j]][j];
			j = pre[j];
			visited[j] = true;
			inc[j] = true;
		}while(j != i);
		inc[i] = false;		//环缩成了点i，点依然存在
		for(int k = 1; k <= n; k++){	//收缩过程
			if(visited[k]){		//在环中的点
				for(int u = 1; u <= n; u++){	//不在环中的点
					if(!visited[u]){
						if(Dis[i][u] > Dis[k][u]){
							Dis[i][u] = Dis[k][u];
						}
						if(Dis[u][k] < INFINITE && Dis[u][k] - Dis[pre[k]][k] < Dis[u][i]){
							Dis[u][i] = Dis[u][k] - Dis[pre[k]][k];
						}
					}
				}
			}
		}
	}
	return sum;
}

int main(){
	while(cin >> n >> m){
		for(int i = 1; i <= n; i++){
			cin >> Village[i].x >> Village[i].y;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j){
					Dis[i][j] = INFINITE;	//这里重要，到自己的距离也是无穷
				}
				else{
					Dis[i][j] = INFINITE;
				}
			}
		}
		for(int i = 1; i <= m; i++){
			int from,to;
			cin >> from >> to;
			Dis[from][to] = CalWay(from, to);
		}
		double ans = DirectedMST(1);
		if(ans < 0){
			cout << "NO" << endl;
		}
		else{
			printf("%.2f\n",ans);
		}
	}
	return 0;
}