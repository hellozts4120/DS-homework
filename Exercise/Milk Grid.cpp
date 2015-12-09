/*	二维KMP，需分别对行和列运用KMP	*/
#include<iostream>
#include<cstring>
using namespace std;

const int MAXR = 10010, MAXC = 76; 
int Next[MAXR];

struct Grid{
	char str[MAXR][MAXC];
	int n,m;
}G;

void GetRowNext(Grid G, int next[], int r){
	int i = 0, j = -1;
	next[i] = j;
	while(i < G.m){
		if(j == -1 || G.str[r][i] == G.str[r][j]){
			i++;
			j++;
			next[i] = j;
		}
		else{
			j = next[j];
		}
	}
}

void GetColNext(Grid G, int next[], int c){
	int i = 0, j = -1;
	next[i] = j;
	while(i < G.n){
		if(j == -1 || G.str[i][c] == G.str[j][c]){
			i++;
			j++;
			next[i] = j;
		}
		else{
			j = next[j];
		}
	}
}

int LCM(int a, int b){		//计算指定字符串的最小循环节
	int temp;
	if(a < b){
		a ^= b, b ^= a, a ^= b;
		temp = a;
	}
	while(b && (a % b)){
		a += temp;
	}
	return a;
}

int main(){
	int i,j,a,b;
	cin >> G.n >> G.m;
	for(int i = 0; i < G.n; i++){
		cin >> G.str[i];
	}
	for(i = b = 0; i < G.n; i++){
		GetRowNext(G, Next, i);
		a = G.m - Next[G.m];
		b = LCM(a, b);
		if(b >= G.m){
			b = G.m;
			break;
		}
	}
	for(i = b, j = b = 0; j < G.m; j++){
		GetColNext(G, Next, j);
		a = G.n - Next[G.n];
		b = LCM(a, b);
		if(b >= G.n){
			b = G.n;
			break;
		}
	}
	a = i*b;
	b = G.m * G.n;
	if(a > b){
		cout << b << endl;
	}
	else{
		cout << a << endl;
	}
	return 0;
}