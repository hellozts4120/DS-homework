#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct Table{
	int start[110];
	int end[110];
};

int main(){
	int a,b,c,ans;
	int table[3];
	int hour,minute,time,people;
	int count[3];
	Table CurTable[3];
	while(cin >> a >> b >> c){
		if(!a && !b && !c){
			break;
		}
		memset(table,0,sizeof(table));
		memset(count,0,sizeof(count));
		memset(CurTable,0,sizeof(CurTable));
		ans = 0;
		char str[10];
		while(cin >> str){
			if(str[0] == '#'){
				break;
			}
			cin >> people;
			hour = 10 * (str[0] - '0') + (str[1] - '0');
			minute = 10 * (str[3] - '0') + (str[4] - '0');
			time = 60 * (hour - 8) + minute;
			if(people == 1 || people == 2){
				if(time >= CurTable[0].end[count[0]]){	//可以直接入桌
					CurTable[0].start[count[0]] = time;
					CurTable[0].end[count[0]] = time + 30;
					count[0]++;
					if(count[0] >= a){
						count[0] = 0;
					}
					ans += people;
				}
				else if(time >= CurTable[0].start[count[0]]){	//等待后可以入桌
					CurTable[0].start[count[0]] = CurTable[0].end[count[0]];
					CurTable[0].end[count[0]] += 30;
					count[0]++;
					if(count[0] >= a){
						count[0] = 0;
					}
					ans += people;
				}
				else{
					continue;
				}
			}
			else if(people == 3 || people == 4){
				if(time >= CurTable[1].end[count[1]]){	//可以直接入桌
					CurTable[1].start[count[1]] = time;
					CurTable[1].end[count[1]] = time + 30;
					count[1]++;
					if(count[1] >= b){
						count[1] = 0;
					}
					ans += people;
				}
				else if(time >= CurTable[1].start[count[1]]){	//等待后可以入桌
					CurTable[1].start[count[1]] = CurTable[1].end[count[1]];
					CurTable[1].end[count[1]] += 30;
					count[1]++;
					if(count[1] >= b){
						count[1] = 0;
					}
					ans += people;
				}
				else{
					continue;
				}
			}
			else if(people == 5 || people == 6){
				if(time >= CurTable[2].end[count[2]]){	//可以直接入桌
					CurTable[2].start[count[2]] = time;
					CurTable[2].end[count[2]] = time + 30;
					count[2]++;
					if(count[2] >= c){
						count[2] = 0;
					}
					ans += people;
				}
				else if(time >= CurTable[2].start[count[2]]){	//等待后可以入桌
					CurTable[2].start[count[2]] = CurTable[2].end[count[2]];
					CurTable[2].end[count[2]] += 30;
					count[2]++;
					if(count[2] >= c){
						count[2] = 0;
					}
					ans += people;
				}
				else{
					continue;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

