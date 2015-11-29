#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

int Wa[20010],Wb[20010],Wv[20010],Ws[20010];
int Rank[20010],height[20010],str[20010],sa[20010];

struct Node{
	int id,num;
}Milk[20010];

int MilkCmp(const void *a, const void *b){
	return ((Node *)a)->num - ((Node *)b)->num;
}

bool cmp(int *r,int a,int b,int l){
	return ((r[a] == r[b]) && (r[a+l] == r[b+l]));
}

void GetSA(int *r, int *sa, int n, int m){
	int *x = Wa, *y = Wb, *t;
	int i,j,p;
	for(i = 0; i < m; i++)Ws[i] = 0;
	for(i = 0; i < n; i++)Ws[x[i] = r[i]]++;
	for(i = 1; i < m; i++)Ws[i] += Ws[i-1];
	for(i = n-1; i >= 0; i--)sa[--Ws[x[i]]] = i;
	for(j = 1, p = 1; p < n; j *= 2, m = p){
		for(p = 0,i = n-j; i < n; i++)y[p++] = i;
		for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i]-j;
		for(i = 0; i < n; i++)Wv[i] = x[y[i]];
		for(i = 0; i < m; i++)Ws[i] = 0;
		for(i = 0; i < n; i++)Ws[Wv[i]]++;
		for(i = 1; i < m; i++)Ws[i] += Ws[i-1];
		for(i = n-1; i >= 0; i--)sa[--Ws[Wv[i]]] = y[i];
		for(t = x,x = y,y = t,p = 1,x[sa[0]] = 0,i = 1; i < n; i++){
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		}
	}
}

void Cal(int *str, int *sa, int n){
	int i,j,k = 0;
	for(int i = 1; i <= n; i++){
		Rank[sa[i]] = i;
	}
	for(i = 0; i < n; height[Rank[i++]] = k){
		for(k?(k--) : 0,j = sa[Rank[i] - 1]; str[i+k] == str[j+k];k++);
	}
}

void Binary(int *sa,int *h,int n,int k){
	int left = 0, right = n, mid;
	int flag, count;
	while(left <= right){
		mid = left + ((right - left) >> 1);
		flag = 0; count = 1;
		for(int i = 2; i <= n && !flag; i++){
			if(h[i] < mid){
				count = 1;
			}
			else{
				count++;
				if(count >= k){
					flag = 1;
				}
			}
		}
		if(flag){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	cout << right << endl;
}

int main(){
	int n,k,m;
	while(scanf("%d%d",&n,&k) != EOF){
		for(int i = 0; i <n; i++){
			scanf("%d",&Milk[i].num);
			Milk[i].id = i;
		}
		qsort(Milk,n,sizeof(Node),MilkCmp);
		str[Milk[0].id] = m = 1;
		for(int i = 1; i < n; i++){
			if(Milk[i].num != Milk[i-1].num){
				m++;
			}
			str[Milk[i].id] = m;
		}
		str[n] = 0;
		GetSA(str,sa,n+1,m+1);
		Cal(str,sa,n);
		Binary(sa,height,n,k);
	}
	return 0;
}