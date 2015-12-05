#include<cstdio>
#include<cstring>

int n,m;
bool flag;
int ans[2010], fa[2010];

void Init(){
	for(int i = 1; i <= n; i++){
		ans[i] = 0;
		fa[i] = i;
	}
	flag = true;
}

int Find(int a){
	int temp;
	if(a != fa[a]){
		temp = Find(fa[a]);
		ans[a] = ans[a] ^ ans[fa[a]];
		fa[a] = temp;
		return fa[a];
	}
	return a;
}

void Union(int a, int b){
	int Fa, Fb;
	Fa = Find(a);
	Fb = Find(b);
	if(Fa == Fb){
		flag = ans[a] ^ ans[b];
	}
	else{
		fa[Fa] = Fb;
		ans[Fa] = (~(ans[a] ^ ans[b]));
	}
}


int main(){
	int cases,cur = 0;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %d",&n,&m);
		Init();
		int a,b;
		for(int i = 0; i < m; i++){
			scanf("%d %d",&a,&b);
			if(flag){
				Union(a,b);
			}
		}
		printf("Scenario #%d:\n",++cur);
		if(flag){
			printf("No suspicious bugs found!\n");
		}
		else{
			printf("Suspicious bugs found!\n");
		}
		printf("\n");
	}
	return 0;
}
