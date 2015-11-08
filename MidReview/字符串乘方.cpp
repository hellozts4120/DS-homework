#include<cstdio>
#include<cstring>

char str[1000010];
int Next[1000010];

void GetNext(){
	int i = 0, j = -1;
	Next[i] = j;
	while(str[i]){
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

int main(){
	while(scanf("%s",str)){
		if(str[0] == '.' && str[1] == '\0'){
			break;
		}
		memset(Next,0,sizeof(Next));
		GetNext();
		int len = strlen(str);
		if(Next[len] && len%(len - Next[len]) == 0){
			printf("%d\n",len / (len - Next[len]));
		}
		else{
			printf("1\n");
		}
	}
	return 0;
}


