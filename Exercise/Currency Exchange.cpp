#include<iostream>
#include<cstring>
using namespace std;

int n,m,s;	//n:货币种数;m:银行数量;s:持有货币的种类
double v;	//v:持有货币的数量
int edge;	//边总数
double value[105];

class Point{
public:
	int a,b;
	double r,c;
}Bank[210];

bool Bellman(){
	memset(value,0,sizeof(value));
	value[s] = v;
	bool flag;
	for(int i = 1; i < n; i++){
		flag = false;
		for(int j = 0; j < edge; j++){
			if(value[Bank[j].b] < (value[Bank[j].a] - Bank[j].c) * Bank[j].r){
				value[Bank[j].b] = (value[Bank[j].a] - Bank[j].c) * Bank[j].r;
				flag = true;
			}
		}
		if(!flag){
			break;
		}
	}
	for(int j = 0; j < edge; j++){
		if(value[Bank[j].b] < (value[Bank[j].a] - Bank[j].c) * Bank[j].r){
			return true;
		}
	}
	return false;
}

int main(){
	int ta,tb;
	double rab,cab,rba,cba;
	while(cin >> n >> m >> s >> v){
		edge = 0;
		for(int i = 0; i < m; i++){
			cin >> ta >> tb >> rab >> cab >> rba >> cba;
			Bank[edge].a = ta;
			Bank[edge].b = tb;
			Bank[edge].c = cab;
			Bank[edge].r = rab;
			edge++;
			Bank[edge].a = tb;
			Bank[edge].b = ta;
			Bank[edge].c = cba;
			Bank[edge].r = rba;
			edge++;
		}
		if(Bellman()){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}