#include<iostream>
#include<cstdlib>
using namespace std;

int cmp(const void *a, const void *b){
	return *((int *)a) - *((int *)b);
}

int main(){
	int db[100010];
	char str[100];
	int n,k;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> db[i];
	}
	qsort(db,n,sizeof(int),cmp);
	cin >> str;
	cin >> k;
	while(k--){
		int temp;
		cin >> temp;
		cout << db[temp-1] << endl;
	}
	return 0;
}
