#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct Box{
	int value;
	int num;
	int visit;
};

struct Circle{
	int cost;
	int n;
	int Min;
	Circle(){
		cost = 0;
		n = 0;
		Min = 100000000;
	};
};

int temp = 0;

int cmp1(const void *a, const void *b){
	return ((Box *)a)->value - ((Box *)b)->value;
}

int cmp2(const void *a, const void *b){
	return ((Circle *)a)->Min - ((Circle *)b)->Min;
}

bool IsMerge(Circle a, Circle b){
	temp = a.n * (a.Min - b.Min) - (b.Min + 3 * a.Min);
	if(temp > 0){
		return true;
	}
	return false;
}

void Merge(Circle &a, Circle &b){
	if(IsMerge(a,b)){
		b.n += a.n;
		b.cost += a.cost - temp;
	}
	else{
		b.cost += a.cost;
	}
}

int main(){
	int n;
	while(scanf("%d",&n)){
		if(!n){
			break;
		}
		Box *box;
		Circle *circle;
		box = new Box[n+1];
		circle = new Circle[n+1];
		for(int i = 0; i < n; i++){
			scanf("%d",&box[i].value);
			box[i].num = i;
			box[i].visit = 0;
		}
		qsort(box,n,sizeof(Box),cmp1);
		int CurNum = 0;
		int cnt = 0;
		while(CurNum < n){
			int i = 0;
			while(box[i].visit){
				i++;
			}
			for(; i < n; i = box[i].num){
				if(!box[i].visit){
					box[i].visit = 1;
					CurNum++;
					circle[cnt].cost += box[i].value;
					circle[cnt].n++;
					if(circle[cnt].Min > box[i].value){
						circle[cnt].Min = box[i].value;
					}
				}
				else{
					circle[cnt].cost += (circle[cnt].n - 2) * circle[cnt].Min;
					cnt++;
					break;
				}
			}
		}
		qsort(circle,cnt,sizeof(Circle),cmp2);
		for(int i = 1; i < cnt; i++){
			Merge(circle[i], circle[0]);
		}
		printf("%d\n",circle[0].cost);
	}
	return 0;
}
