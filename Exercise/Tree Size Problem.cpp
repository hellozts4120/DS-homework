#include<iostream>
#include<cstring>
using namespace std;

int Dis[200][200];
int visit[200],n;
int sum = 0;

bool Check(int a, int b, int &x){	//�ж�a,b����Ҷ����Ƿ���й�����ֱ�Ӹ��ڵ㣬���У�����a���乫�����ڵ�ľ���
	bool flag = true;
	for(int i = 0; i < n; i++){
		if(!visit[i] && i!=a && i!=b){
			if(flag){
				x = Dis[a][i] - (Dis[a][i] + Dis[b][i] - Dis[a][b]) / 2;
				flag = false;
			}
			else if(x != Dis[a][i] - (Dis[a][i] + Dis[b][i] - Dis[a][b]) / 2){
				return false;	//��Ϊֱ�Ӹ��ڵ�ʱ����
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
				for(b = a+1; b < n; b++){	//���Ҿ��й������ڵ������Ҷ�ڵ㲢����ϲ�
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
				if(!visit[i]){		//�����½��n,����a,b����Ϊ�丸�ڵ㣩
					Dis[i][n] = Dis[n][i] = Dis[i][a] - x;
				}
			}
			n++;
		}
		cout << sum << endl;
	}
	return 0;
}