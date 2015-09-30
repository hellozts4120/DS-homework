#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char str[1000];
char out[1000];

void Del(char *s,char ch){		//从后往前找，减少移动数组次数
	int len = strlen(s);
	for(int i = len; i >= 0;i--){
		if(s[i] == ch){
			for(int j = i+1;j <= len;j++){
				s[j - 1] = s[j];
			}
			len--;
		}
	}
	cout << len << endl;
	str[len+1] = '\0';
}


int main(){
	char ch;
	cout << "Enter Str:";
	cin >> str;
	cout << "Enter ch:";
	cin >> ch;
	Del(str,ch);
	puts(str);
	return 0;
}