#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct Word{
	char str[10];
	char tra[10];
}Dic[105];

int cmp(const void *a, const void *b){
	return *((char *)a) - *((char *)b);
}

int cmp1(const void *a, const void *b){
	Word *a1 = (Word *)a, *b1 = (Word *)b;
	return (strcmp(a1->str, b1->str) > 0);
}

int main(){
	char str[10];
	int n = 0;
	while(cin >> str){
		if(!strcmp(str, "XXXXXX")){
			break;
		}
		strcpy(Dic[n].str, str);
		qsort(str,strlen(str),sizeof(char),cmp);
		strcpy(Dic[n].tra, str);
		n++;
	}
	qsort(Dic,n,sizeof(Word),cmp1);
	while(cin >> str){
		bool IsHave = 0;
		if(!strcmp(str, "XXXXXX")){
			break;
		}
		qsort(str,strlen(str),sizeof(char),cmp);
		for(int i = 0; i < n; i++){
			if(!strcmp(str,Dic[i].tra)){
				cout << Dic[i].str << endl;
				IsHave = 1;
			}
		}
		if(!IsHave){
			cout << "NOT A VALID WORD" << endl;
		}
		cout << "******" << endl;
	}
	return 0;
}