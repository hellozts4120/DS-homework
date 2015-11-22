#include<cstdio>
#include<iostream>
using namespace std;

const int MAX = 1000000000;
int str[500010];
int L[250005],R[250005];
long ans;

void Merge(int left, int right, int mid){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	for(int i = 0; i < n1; i++){
		L[i] = str[left + i];
	}
	for(int i = 0; i < n2; i++){
		R[i] = str[mid + i + 1];
	}
	int i = 0, j = 0;
	L[n1] = R[n2] = MAX;
	for(int k = left; k <= right; k++){
		if(L[i] <= R[j]){
			str[k] = L[i++];
		}
		else{
			str[k] = R[j++];
			ans += long(n1) - i;
		}
	}
}

void MergeSort(int left, int right){
	int mid;
	if(left == right){
		return;
	}
	mid = left + ((right - left) >> 1);
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	Merge(left, right, mid);
	return;
}

int main(){
	int n;
	while((cin >> n) && n){
		for(int i = 0; i < n; i++){
			cin >> str[i];
		}
		ans = 0;
		MergeSort(0, n-1);
		printf("%ld\n",ans);
	}
	return 0;
}