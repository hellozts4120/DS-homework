/*	�����ǡ�//����ע�ͣ�������Ƕ��ע��	*/
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
				while(ch == '/'){	//����Ƿ����ע��״̬
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
					if(ch == '"'){	//�����ַ���״̬����ֱ�Ӻ���һ������ע��
						InStr = true;
					}
					printf("%c",ch);
				}
			}
			else{	//in str.
				if(ch == '\\'){		//ת���ַ���ֱ�Ӻ��Ժ���
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