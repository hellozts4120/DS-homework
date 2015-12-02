#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char str[1000];
int ASCII[200];
int ff[7];

void Fun(){
	memset(ASCII,0,sizeof(ASCII));
	memset(ff,0,sizeof(ff));
	int i = 0, sum = 0;
	while (str[i]){
		if(str[i] == 'f'){
			if(str[i+1] == 'f' && str[i+2] == 'l' || str[i+2] == 'i'){
				if(str[i+2] == 'l'){
					ff[0] = 1;
				}
				if(str[i+2] == 'i'){
					ff[1] = 1;
				}
				i += 2;
			}
			else if(str[i+1] == 'f' || str[i+1] == 'i' || str[i+1] == 'l'){
				if(str[i+1] == 'f'){
					ff[2] = 1;
				}
				if(str[i+1] == 'i'){
					ff[3] = 1;
				}
				if(str[i+1] == 'l'){
					ff[4] = 1;
				}
				i++;
			}
			else{
				ASCII[str[i]] = 1;
			}
		}
		else if(str[i] == '`' && str[i+1] == '`'){
			ff[5] = 1;
			i++;
		}
		else if(str[i] == '\'' && str[i+1] == '\''){
			ff[6] = 1;
			i++;
		}
		else{
			ASCII[str[i]] = 1;
		}
		i++;
	}
	for(int i = 0; i < 200; i++){
		if(ASCII[i]){
			sum++;
		}
	}
	for(int i = 0; i < 7; i++){
		if(ff[i]){
			sum++;
		}
	}
	cout << sum << endl;
}


int main(){
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	char ch;
	int len = 0;
	while(scanf("%c",&ch) != EOF){
		if(ch == ' ' || ch == '\n'){
			continue;
		}
		str[len++] = ch;
	}
	str[len] = '\0';
	Fun();
	return 0;
}