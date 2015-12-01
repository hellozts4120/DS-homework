/*	不考虑‘//’的注释，不考虑嵌套注释	*/
#include<cstdio>
#include<cstring>

int main(){
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	char ch;
	bool InComment = false;
	bool InStr = false;
	while(scanf("%c",&ch) != EOF){
		if(!InComment){
			if(!InStr){
				while(ch == '/'){	//检测是否进入注释状态
					scanf("%c",&ch);
					if(ch == '/'){
						printf("/");
					}
					else if(ch != '*' && ch != '"'){
						printf("/");
					}
					else if(ch == '*'){
						InComment = true;
					}
				}
				if(!InComment){
					if(ch == '"'){	//进入字符串状态，可直接忽略一切疑似注释
						InStr = true;
					}
					printf("%c",ch);
				}
			}
			else{	//in str.
				if(ch == '\\'){		//转义字符，直接忽略后续
					char ch1;
					scanf("%c",&ch1);
					printf("%c%c",ch,ch1);
				}
				else{
					if(ch == '"'){
						InStr = false;
					}
					printf("%c",ch);
				}
			}
		}
		else{	//in comment
			while(ch == '*'){
				scanf("%c",&ch);
				if(ch == '/'){
					InComment = false;	// avoid '***/'
				}
			}
		}
	}
	return 0;
}