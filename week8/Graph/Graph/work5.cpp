#include<iostream>
using namespace std;

const int MAXP = 30,INFINITE = 100000;
int Dist[MAXP][MAXP];	//��¼������̾���

void InitDist(int v){	//��ʼ״̬��ͼ�ж��ǹ����ĵ㣬û�бߣ��Լ����Լ��ľ���Ϊ0����������ľ���Ϊ�����
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

void Floyd(int v){		//����ĵ㼴Ϊ���·������������֮һ
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
	cout << "����С��������";
	cin >> n;
	InitDist(n);
	int q;
	cout << "����·��������";
	cin >> q;
	cout << "������С�����(��С�±��0��ʼ)��������֮���·�����̣�" << endl;
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
	cout << "���ʵĵ�Ϊ��" <<MaxNum << endl;
	return 0;
}
