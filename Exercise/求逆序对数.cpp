#include<iostream>
using namespace std;

int str[20010];
int ans = 0;

void Merge(int left, int right, int mid){
	int L[20010],R[20010];
	int n1 = mid - left + 1;
	int n2 = right - mid;
	for(int i = 0; i < n1; i++){
		L[i] = str[left + i];
	}
	for(int i = 0; i < n2; i++){
		R[i] = str[mid + 1 + i];
	}
	int i = 0, j = 0, k = left;
	while(k <= right && i != n1 && j != n2){
		if(L[i] <= R[j]){
			str[k++] = L[i++];
		}
		else{
			str[k++] = R[j++];
			ans += n1 - i;
		}
	}
	if(i == n1){
		while(j != n2){
			str[k++] = R[j++];
		}
	}
	else{
		while(i != n1){
			str[k++] = L[i++];
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
}

int main(){
	int n;
	while((cin >> n) && n){
		ans = 0;
		for(int i = 0; i < n; i++){
			cin >> str[i];
		}
		MergeSort(0, n-1);
		cout << ans << endl;
	}
	return 0;
}