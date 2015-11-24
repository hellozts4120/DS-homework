#include<iostream>
#include<cstring>
using namespace std;

int str[10010];
int ans;

void Merge(int left, int right, int mid){
	int L[10010], R[10010];
	int n1 = mid - left + 1;
	int n2 = right - mid;
	for(int i = 0; i < n1; i++){
		L[i] = str[left + i];
	}
	for(int i = 0; i < n2; i++){
		R[i] = str[mid + 1 + i];
	}
	int i = 0, j = 0;
	L[n1] = 1000010;
	R[n2] = 1000010;
	for(int k = left; k <= right; k++){
		if(L[i] <= R[j]){
			str[k] = L[i++];
		}
		else{
			str[k] = R[j++];
			ans += n1 - i;
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
	int cases;
	cin >> cases;
	int t = 1;
	while(cases--){
		int n;
		cin >> n;
		ans = 0;
		for(int i = 0; i < n; i++){
			cin >> str[i];
		}
		MergeSort(0, n-1);
		cout << "Scenario #" << t++ << ": " << endl;
		cout << ans << endl;
		cout << endl;
	}
	return 0;
}
