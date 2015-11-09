/*	举例 ：13 abejkcfghid jkebfghicda
    显然a,b容易确定，由后序知 j,k,e必定为 b 的后代。对 j,k,e 递归可获得j,k,e的位置关系。同理其它元素都可以确定自己所在的层数。
    对于每一层，计算组合数C(m，n)可知（即从m个中选n个），这里的 m表示的是m叉树，而n 则表示该层结点数。	*/

#include<iostream>
#include<cstring>
using namespace std;

int m;

int C(int a,int b){
	int x = 1;
	for(int i = 0; i < b; i++){
		x *= (a - i);
	}
	for(int i = 1; i <= b; i++){
		x /= i;
	}
	return x;
}

int solve(int x,char *pre,char *post){
	int i = 1, j = 0;		//i：pre下标，j：post下标
	int sum = 1, son = 0;	//sum：结果，son：子树个数
	while(i < x){
		while(post[j] != pre[i]){
			j++;
		}
		son++;
		sum *= solve(j - i + 2,pre + i,post + i - 1);
		i = j + 2;
	}
	return sum * C(m,son);
}


int main(){
	char pre[30],post[30];
	while(cin >> m){
		if(!m){
			break;
		}
		cin >> pre >> post;
		cout << solve(strlen(pre),pre,post) << endl;
	}
	return 0;
}
