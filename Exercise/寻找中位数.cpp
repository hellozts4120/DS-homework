#include<iostream>
#include<cstdlib>
using namespace std;

int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	int n,a[10010];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	qsort(a,n,sizeof(int),cmp);
	cout << a[n/2] << endl;
	return 0;
}