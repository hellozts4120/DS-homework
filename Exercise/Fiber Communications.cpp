#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n,p;
struct Pair{
	int x,y;
}Cow[10010];

int cmp(const void *a, const void *b){
	if(((Pair *)a)->x == ((Pair *)b)->x){
		return (((Pair *)a)->y - ((Pair *)b)->y);
	}
	else{
		return (((Pair *)a)->x - ((Pair *)b)->x);
	}
}

int main(){
	cin >> n >> p;
	int output = 1000000;
	for(int i = 0; i < p; i++){
		cin >> Cow[i].x >> Cow[i].y;
	}
	for(int i = 0; i < n; i++){
		int ans = 0;
		for(int j = 0; j < p; j++){
			if(Cow[j].x < i){
				Cow[j].x += n;
			}
			if(Cow[j].y < i){
				Cow[j].y += n;
			}
			if(Cow[j].x > Cow[j].y){
				int temp = Cow[j].x;
				Cow[j].x = Cow[j].y; Cow[j].y = temp;
			}
		}
		qsort(Cow,p,sizeof(Pair),cmp);
		int l = Cow[0].x, r = Cow[0].y;
		for(int j = 1; j < p; j++){
			if(r >= Cow[j].x){
				r = max(Cow[j].y,r);
			}
			else{
				ans += r - l;
				l = Cow[j].x; r = Cow[j].y;
			}
		}
		if(ans + r - l < output){
			output = ans + r - l;
		}
	}
	cout << output << endl;
	return 0;
}

