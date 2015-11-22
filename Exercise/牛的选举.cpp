#include<iostream>
#include<cstdlib>
using namespace std;

struct Ox{
	int first;
	int second;
	int num;
}AllOx[50010];

int cmp1(const void *a, const void *b){
	return ((Ox *)b)->first - ((Ox *)a)->first;
}

int cmp2(const void *a, const void *b){
	return ((Ox *)b)->second - ((Ox *)a)->second;
}

int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> AllOx[i].first >> AllOx[i].second;
		AllOx[i].num = i + 1;
	}
	qsort(AllOx,n,sizeof(Ox),cmp1);
	qsort(AllOx,k,sizeof(Ox),cmp2);
	cout << AllOx[0].num << endl;
	return 0;
}