#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;

int board[512][512];
int tree[2000000];
char code[2000000];
int cur = 0;

int DFS(int LeftX, int RightX, int LeftY, int RightY, int k){		//DFS,得到每个正方形块是否全为相同值
	if(LeftX > RightX || LeftY > RightY){
		return 0;
	}
	if(LeftX == RightX && LeftY == RightY){
		tree[k] = board[LeftX][LeftY];
		return board[LeftX][LeftY];
	}
	int MidX = (LeftX + RightX)/2;
	int MidY = (LeftY + RightY)/2;
	int s = 0;
	s += DFS(LeftX,MidX,LeftY,MidY,(k << 2));
	s += DFS(LeftX,MidX,MidY+1,RightY,(k << 2) + 1);
	s += DFS(MidX+1,RightX,LeftY,MidY,(k << 2) + 2);
	s += DFS(MidX+1,RightX,MidY+1,RightY,(k << 2) + 3);
	tree[k] = s;
	return s;
}

void BFS(int LeftX, int RightX, int LeftY, int RightY, int k){		//BFS,得到二进制数组
	queue<int> K,X,Y;
	K.push(k);
	X.push(RightX - LeftX + 1);
	Y.push(RightY - LeftY + 1);
	int x,y;
	while(!K.empty()){
		k = K.front(); K.pop();
		x = X.front(); X.pop();
		y = Y.front(); Y.pop();
		if(tree[k] == x * y || tree[k] == 0){
			code[cur++] = '0';
			code[cur++] = (tree[k] != 0) + '0';
			continue;
		}
		code[cur++] = '1';
		K.push((k << 2)); X.push(x/2); Y.push(y/2);
		K.push((k << 2) + 1); X.push(x/2); Y.push(y/2);
		K.push((k << 2) + 2); X.push(x/2); Y.push(y/2);
		K.push((k << 2) + 3); X.push(x/2); Y.push(y/2);
	}
}

int main(){
	int cases;
	int n;
	cin >> cases;
	while(cases--){
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> board[i][j];
			}
		}
		cur = 0;
		DFS(0,n-1,0,n-1,1);
		BFS(0,n-1,0,n-1,1);
		code[cur] = '\0';
		int len = strlen(code);
		int ans = 0;
		for(int i = 0; i < len; i++){	//将二进制数组转换为十进制
			ans = (ans<<1) | (code[i] - '0');
		}
		printf("%X\n", ans);	//十六进制输出
	}
	return 0;
}