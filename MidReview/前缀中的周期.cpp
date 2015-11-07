#include<iostream>
#include<cstring>
using namespace std;

char str[1000001];
int Next[1000001];

void GetNext(){
	memset(Next,0,sizeof(Next));
	int i = 0, j = -1;
	Next[i] = j;
	int len = strlen(str);
	while(i < len){
		if(j == -1 || str[i] == str[j]){
			i++;
			j++;
			Next[i] = j;
		}
		else{
			j = Next[j];	//return to Next[j] to compare;
		}
	}
}


int main(){
	int count = 0;
	int n;
	while(cin >> n){
		if(!n){
			break;
		}
		cin >> str;
		GetNext();
		count++;
		cout << "Test case #" << count << endl;
		for(int i = 1; i <= n; i++){
			if(Next[i]>0 && i%(i-Next[i])==0){
				cout << i << " " << i/(i-Next[i]) << endl;
			}
		}
		cout << endl;
	}
	return 0;
}