#include<iostream>
using namespace std;

int n;
bool IsFind;

void DFS(unsigned long long x,int step){
	if(IsFind || step == 19){
		return;
	}
	if(x % n == 0){
		cout << x << endl;
		IsFind = true;
		return;
	}
	else{
		DFS(10 * x,step + 1);
		DFS(10 * x + 1,step + 1);
	}
	return;
}

int main(){
	while(cin >> n){
		if(!n){
			break;
		}
		IsFind = false;
		DFS(1,0);
	}
	return 0;
}