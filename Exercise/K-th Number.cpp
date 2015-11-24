#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

struct Node{
	int n,x;
}str[100010];

int cmp(const void *a, const void *b){
	return ((Node *)a)->x - ((Node *)b)->x;
}

int main(){
	int n,m;
	int a,b,k;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&str[i].x);
		str[i].n = i + 1;
	}
	qsort(str,n,sizeof(Node),cmp);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d",&a,&b,&k);
		for(int j = 0; j < n; j++){
			if(str[j].n >= a && str[j].n <= b){
				k--;
			}
			if(!k){
				printf("%d\n",str[j].x);
				break;
			}
		}
	}
	return 0;
}