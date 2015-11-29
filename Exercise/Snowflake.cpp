#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int Hash[100010],Next[100010];

struct Leave{
	int len[6];
}snow[100010];

bool Judge(int a, int b){
	int i,j,k;
	for(i = 0; i < 6; i++){
		for(j = i, k = 0; k < 6; k++, j=(j+1)%6){
			if(snow[a].len[k] != snow[b].len[j]){
				break;
			}
		}
		if(k == 6){
			return true;
		}
		for(j = i, k = 0; k < 6; k++, j=(j+5)%6){
			if(snow[a].len[k] != snow[b].len[j]){
				break;
			}
		}
		if(k == 6){
			return true;
		}
	}
	return false;
}


bool TryHash(int index){
	int x = 0;
	for(int i = 0; i < 6; i++){
		x = (int)((((long long)(snow[index].len[i]) * (long long)(snow[index].len[i])) + x) % 1000007);	//平方取模法
	}
	int u = Hash[x];
	while(u){		//拉链法解决冲突
		if(Judge(index,u)){
			return false;
		}
		u = Next[u];
	}
	Next[index] = Hash[x];
	Hash[x] = index;
	return true;
}

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i = 1; i <= n; i++){	//下标从1开始
			for(int j = 0; j < 6; j++){
				scanf("%d",&snow[i].len[j]);
			}
		}
		memset(Hash,0,sizeof(Hash));
		memset(Next,0,sizeof(Next));
		int i;
		for(i = 1; i <= n; i++){
			if(TryHash(i) == false){
				break;
			}
		}
		if(i == n+1){
			printf("No two snowflakes are alike\n");
		}
		else{
			printf("Twin snowflakes found.\n");
		}
	}
	return 0;
}