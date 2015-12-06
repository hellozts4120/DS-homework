#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX = 1000010;
char str[MAX], s[MAX];
int start = 1005;
char ans[1005];
char temp[15];
int Next[MAX];

void GetNext(char *str){
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
			j = Next[j];
		}
	}
}

int KMP(char *str, int len){
	int L = strlen(str);
	int j = 0, c = 0, index;
	for(int i = start+1; i < start+len; i++){
		while(j && str[j] != s[i]){
			j = Next[j];
		}
		if(str[j] == s[i]){
			j++;
		}
		if(j > c){
			c = j;
			index = i;
		}
		if(j == L){
			return i-j;
		}
	}
	if(c){
		return index-c;
	}
	return -1;
}

int main(){
	int n,l;
	scanf("%d%d%s",&n,&l,str);
	int len = strlen(str);
	for(int i = 0; str[i]; i++){
		s[start+i] = str[len-i-1];	//ÄæÐò»¯
	}
	s[start+len] = '\0';
	int cur = l;
	while(cur--){
		strncpy(temp, s+start, 13);
		if(len < 13){
			temp[len] = '\0';
		}
		else{
			temp[13] = '\0';
		}
		GetNext(temp);
		int K = KMP(temp, len);
		start--;
		len++;
		if(K < 0){
			s[start] = 0;
		}
		else{
			s[start] = s[K];
		}
	}
	for(int i = 0; i < l; i++){
		ans[i] = s[start+l-i-1];
	}
	ans[l] = '\0';
	printf("%s\n",ans);
	return 0;
}
