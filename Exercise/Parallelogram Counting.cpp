#include<iostream>
#include<cstring>
using namespace std;

int ans,sum;
int Hash[7345787],Next[1000010];

struct Node{
	int x,y;
}Point[1010];

struct Mid{
	int x,y;
	int count;
}All[1000010];

int CalHash(int x, int y){
	int key = 0;
	key = ((x << 2) + (x >> 4)) ^ (y << 10);
	key = key % 7345787;
	if(key < 0){
		key += 7345787;
	}
	return key;
}

void Insert(int x, int y){
	int key = CalHash(x,y);
	bool IsOccupy = 0;
	for(int i = Hash[key]; i != -1; i = Next[i]){
		if(All[i].x == x && All[i].y == y){
			IsOccupy = 1;
			ans += All[i].count++;
			break;
		}
	}
	if(!IsOccupy){
		All[sum].x = x;
		All[sum].y = y;
		All[sum].count = 1;
		Next[sum] = Hash[key];
		Hash[key] = sum++;
	}
}

int main(){
	int cases,n;
	cin >> cases;
	while(cases--){
		memset(Hash,-1,sizeof(Hash));
		cin >> n;
		ans = 0;
		sum = 0;
		for(int i = 0; i < n; i++){
			cin >> Point[i].x >> Point[i].y;
		}
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				Insert(Point[i].x + Point[j].x, Point[i].y + Point[j].y);
			}
		}
		cout << ans << endl;
	}
	return 0;
}