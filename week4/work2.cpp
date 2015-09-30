#include<iostream>
#include<cstring>
using namespace std;

char str[1000];

char firstSingle(char * str){
	int Save[128];
	memset(Save,0,sizeof(Save));
	char *Key = str;
	while(*Key != '\0'){
		Save[*Key]++;
		*Key++;
	}
	Key = str;
	while(*Key != '\0'){
		if(Save[*Key] == 1){
			return *Key;
		}
		*Key++;
	}
	return 0;
}

int main(){
	char result;
	cout << "Enter Str:";
	cin >> str;
	result = firstSingle(str);
	if(result == 0){
		cout << "No Find!" << endl;
	}
	else cout << "Result:" << result << endl;
	return 0;
}