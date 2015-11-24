#include<iostream>
#include<cstring>
using namespace std;

int m,n;
int player[10010];

int main(){
	while(cin >> n >> m){
		if(!n && !m){
			break;
		}
		memset(player,0,sizeof(player));
		int Max = 0, Second = 0, pos;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int temp;
				cin >> temp;
				player[temp]++;
				if(Max < player[temp]){
					Max = player[temp];
				}
			}
		}
		for(Second = Max - 1; Second >= 1; Second--){
			bool Find = 0;
			for(int i = 1; i <= 10000; i++){
				if(player[i] == Second){
					Find = 1;
					cout << i;
					pos = i;
					break;
				}
			}
			if(Find){
				break;
			}
		}
		for(int i = pos + 1; i <= 10000; i++){
			if(player[i] == Second){
				cout << " " << i;
			}
		}
		cout << endl;
	}
	return 0;
}

