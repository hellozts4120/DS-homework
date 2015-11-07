#include<iostream>
#include<algorithm>
using namespace std;

int card[2000002];
int goodcard[100010];

int main(){
	int n,k,p;
	cin >> n >> k >> p;
	for(int i = 0; i < k; i++){
		card[i] = i + 1;
	}
	int cur = 0;
	int GoodCount = 0;
	int head = 0, tail = k;
	while(head <= tail){
		if(cur == n - 1){
			goodcard[GoodCount++] = card[head];
		}
		head++;
		for(int i = 0; i < p; i++){
			card[tail++] = card[head++];
		}
		cur = (cur + 1) % n;
	}
	sort(goodcard,goodcard+GoodCount);
	for(int i = 0; i < GoodCount; i++){
		cout << goodcard[i] << endl;
	}
	return 0;
}