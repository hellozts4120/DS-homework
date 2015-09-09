#include<iostream>
using namespace std;	//�������Ϊ����һ�飬ÿ���ȱȽ�һ�δ�С���ٷֱ�͵�ǰ���������С�Ƚϴ�С����3�Σ���ִ��3n/2
int allMax,allMin;

void PickMinAndMax(int *str,int n){
	int Max,Min;
	int tempmax,tempmin;
	int i,j;
	if(n == 1){
		allMax = allMin = str[0];
		return;
	}
	for(i = 0,j = 1;i < n && j < n;i += 2,j += 2){
		if(str[i] == str[j]){
			tempmax = tempmin = str[i];
			if(i == 0) Max = Min = str[i];
		}
		else if(str[i] > str[j]){
			tempmax = str[i];
			tempmin = str[j];
			if(i == 0) Max = str[i];Min = str[j];
		}
		else {
			tempmax = str[j];
			tempmin = str[i];
			if(i == 0) Max = str[j];Min = str[i];
		}
		if(tempmax > Max) Max = tempmax;
		if(tempmin < Min) Min = tempmin;
	}
	if(i < n || j < n){
		if(str[n - 1] > Max) Max = str[n - 1];
		if(str[n - 1] < Min) Min = str[n - 1];
	}
	allMax = Max;
	allMin = Min;
}

int main(){
	int n,i;
	cin >> n;
	int *str = new int[n];
	for(i = 0;i < n;i++){
		cin >> str[i];
	}
	printf("%d",str[0]);
	PickMinAndMax(str,n);
	cout << "max:" << allMax << " ; min:" << allMin << endl;
	delete []str;
	return 0;
}