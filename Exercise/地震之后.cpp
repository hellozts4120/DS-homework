/*	����ͼ��MST������ʹ��Prim��Kruskal��ʹ����С����ͼ�������㷨	*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX = 105, INFINITE = 1000000;
int n,m;
double Dis[MAX][MAX];
int pre[MAX];	//Ȩֵ��С��ǰ����;
bool visited[MAX];	//�õ����ڻ��л��ǻ���;
bool inc[MAX];	//�õ��Ƿ��Ѿ���ɾ��;


struct Node{
	int x,y;
}Village[MAX];

double CalWay(int x, int y){
	return sqrt((Village[x].x - Village[y].x)*(Village[x].x - Village[y].x) + (Village[x].y - Village[y].y)*(Village[x].y - Village[y].y));
}

void DFS(int x){	//�ݹ����ѣ��ж��Ƿ��ܹ�����MST
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
	DFS(x);		//���ѣ��ж��Ƿ��ܹ��γ�MST
	double sum = 0;
	for(int i = 1; i <= n; i++){	//����������MST��ֱ�����-1���������ɣ�
		if(!visited[i]){
			return -1;
		}
	}
	memset(visited,0,sizeof(visited));	//���ܹ����ɣ������
	while(1){
		for(int i = 1; i <= n; i++){	//1.��ÿ���������Сǰ���ߡ�
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
		int i;		//2.�ж��Ƿ��л�
		for(i = 1; i <= n; i++){
			if(i != x && !inc[i]){
				int j = i, cur = 0;
				while(j != x && pre[j] != i && cur <= n){
					j = pre[j];
					cur++;
				}
				if(j == x || cur > n){		//��ʱ��iΪ��ʼ������޻�
					continue;
				}
				break;	//�л�����
			}
		}
		if(i > n){		//3.��ʱ�޻���ֱ�ӱ��������
			for(int j = 1; j <= n; j++){
				if(j != x && !inc[j]){
					sum += Dis[pre[j]][j];
				}
			}
			return sum;
		}
		int j = i;		//4.�л������������
		memset(visited,0,sizeof(visited));
		do{
			sum += Dis[pre[j]][j];
			j = pre[j];
			visited[j] = true;
			inc[j] = true;
		}while(j != i);
		inc[i] = false;		//�������˵�i������Ȼ����
		for(int k = 1; k <= n; k++){	//��������
			if(visited[k]){		//�ڻ��еĵ�
				for(int u = 1; u <= n; u++){	//���ڻ��еĵ�
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
					Dis[i][j] = INFINITE;	//������Ҫ�����Լ��ľ���Ҳ������
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