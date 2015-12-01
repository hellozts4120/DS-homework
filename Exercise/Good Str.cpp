#include<iostream>
#include<cstring>
using namespace std;

struct Stu{
	char str[1000];
	char t[1000];
	bool IsRight;
}work[55];

int main(){
	int n;
	char temp[1000];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> work[i].str;
		work[i].IsRight = true;
		strcpy(work[i].t, work[i].str);
	}
	cin >> temp;
	int left,right,j,start,out;
	for(j = 0; temp[j]; j++){
		if(temp[j] >= 'A' && temp[j] <= 'Z'){
			temp[j] = temp[j] - 'A' + 'a';
		}
		if(temp[j] == '['){
			left = j-1;
			start = j+1;
		}
		if(temp[j] == ']'){
			out = j-1;
		}
	}
	int k;
	for(int i = 0; i < n; i++){
		for(k = 0; k <= left; k++){
			if(work[i].str[k] >= 'A' && work[i].str[k] <= 'Z'){
				work[i].str[k] = work[i].str[k] - 'A' + 'a';
			}
			if(work[i].str[k] != temp[k]){
				work[i].IsRight = false;
				cout << i << endl;
				break;
			}
		}
		if(!work[i].IsRight){
			continue;
		}
		if(work[i].str[k] >= 'A' && work[i].str[k] <= 'Z'){
			work[i].str[k] = work[i].str[k] - 'A' + 'a';
		}
		for(int u = start; u <= out; u++){
			if(work[i].str[k] == temp[u]){
				break;
			}
			if(u == out){
				work[i].IsRight = false;
				cout << i << endl;
			}
		}
		if(!work[i].IsRight){
			continue;
		}
		k++;
		for(int u = out+2; temp[u]; u++){
			if(work[i].str[k] >= 'A' && work[i].str[k] <= 'Z'){
				work[i].str[k] = work[i].str[k] - 'A' + 'a';
			}
			if(work[i].str[k] != temp[u]){
				work[i].IsRight = false;
				cout << i << endl;
				break;
			}
			k++;
		}
	}
	for(int i = 0; i < n; i++){
		if(work[i].IsRight){
			cout << i+1 << " " << work[i].t << endl;
		}
	}
	return 0;
}