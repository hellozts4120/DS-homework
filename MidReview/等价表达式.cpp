#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>
using namespace std;

void Trans(char str[], char post[], int &m){
	stack<char>Stack;
	for(unsigned int i = 0; i < strlen(str); i++){
		if(((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= '0') && (str[i] <= '9'))){
			post[m++] = str[i];
		}
		if(str[i] == '('){
			Stack.push(str[i]);
		}
		if(str[i] == '+' || str[i] == '-'){
			while(!Stack.empty() && (Stack.top()=='*'||Stack.top()=='/'||Stack.top()=='-'||Stack.top()=='+')){
				post[m++] = Stack.top();
				Stack.pop();
			}
			Stack.push(str[i]);
		}
		if(str[i] == '*' || str[i] == '/'){
			while(!Stack.empty() && (Stack.top()=='*'||Stack.top()=='/')){
				post[m++] = Stack.top();
				Stack.pop();
			}
			Stack.push(str[i]);
		}
		if(str[i] == ')'){
			while(Stack.top() != '('){
				post[m++] = Stack.top();
				Stack.pop();
			}
			Stack.pop();
		}
		if(str[i] == ' ' || str[i] == '\t'){
			continue;
		}
	}
	while(!Stack.empty()){
		post[m++]=Stack.top();
		Stack.pop();
	}
	post[m] = '\0';
}

int GetNum(char OutStr[]){
	stack<int>Final;
	for(unsigned int i = 0; i < strlen(OutStr); i++){
		if(((OutStr[i] >= 'a') && (OutStr[i] <= 'z')) || ((OutStr[i] >= 'A') && (OutStr[i] <= 'Z'))){
			Final.push(int(OutStr[i] - '@'));
		}
		else if((OutStr[i] >= '0') && (OutStr[i] <= '9')){
			Final.push(int(OutStr[i] - '0'));
		}
		else{
			int a,b,c;
			a = Final.top();Final.pop();
			b = Final.top();Final.pop();
			switch(OutStr[i]){
				case '+':
					c = a+b;
					break;
				case '-':
					c = b-a;
					break;
				case '*':
					c = a*b;
					break;
				case '/':
					c = b/a;
					break;
				default:;
			}
			Final.push(c);
		}
	}
	return Final.top();
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int cases;
	scanf("%d",&cases);
	getchar();
	while(cases--){
		char a[85],b[85];
		char aT[85],bT[85];
		int num1 = 0,num2 = 0;
		gets(a);
		gets(b);
		Trans(a,aT,num1);
		Trans(b,bT,num2);
		int aa = GetNum(aT);
		int bb = GetNum(bT);
		if(aa == bb){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}