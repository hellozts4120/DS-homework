#include<cstdio>

long long ans = 0;

struct liba{
	long long height;
	int count;
}Liba[100010];

int main(){
	int n;
	while(scanf("%d",&n) && n){
		int top = 0, tmp;
		long long cur,total;
		ans = 0;
		for(int i = 0; i < n; i++){
			scanf("%lld",&cur);
			tmp = 0;
			while(top && Liba[top-1].height >= cur){
				total = Liba[top-1].height*(Liba[top-1].count + tmp);
				if(total > ans){
					ans = total;
				}
				tmp += Liba[top-1].count;
				--top;
			}
			Liba[top].height = cur;
			Liba[top].count = tmp+1;
			++top;
		}
		tmp = 0;
		while(top){
			total = Liba[top-1].height*(Liba[top-1].count + tmp);
			if(total > ans){
				ans = total;
			}
			tmp += Liba[top-1].count;
			--top;
		}
		printf("%lld\n",ans);
	}
	return 0;
}