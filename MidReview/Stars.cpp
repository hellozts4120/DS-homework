#include<cstdio>
#include<cstring>

int level[15010];
int sum[32010];

/*	x & (-x)：x为奇数时，结果为1；x为偶数时，结果为x中2的最大次方的因子	*/
int GetSum(int x){	//获取x的level
	int Sum = 0;
	while(x > 0){
		Sum += sum[x];
		x -= (x & (-x));
	}
	return Sum;
}

void Update(int x){ //更新sum数组中下标大于x的数的值
	while(x < 32010){
		sum[x]++;
		x += (x & (-x));
	}
}

int main(){
	int n,x,y;
	scanf("%d",&n);
	memset(level,0,sizeof(level));
	memset(sum,0,sizeof(sum));
	for(int i = 0; i < n; i++){
		int s = 0;
		scanf("%d%d",&x,&y);
		level[GetSum(x + 1)]++;
		Update(x + 1);
	}
	for(int i = 0; i < n; i++){
		printf("%d\n",level[i]);
	}
	return 0;
}
