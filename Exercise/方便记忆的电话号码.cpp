#include<iostream>
#include<cstring>
using namespace std;

int dic[10000000];

int Digit(char c){
	if(c >= '0' && c <= '9'){
		return (c - '0');
	}
	if(c >= 'a' && c <= 'z'){
		c -= 'a';
	}
	else if(c >= 'A' && c <= 'Z'){
		c -= 'A';
	}
	if(c > 15){
		c--;
	}
	return (c/3 + 2);
}

int Trans(char *str){
	int ans = 0;
	for(int i = 0; str[i]; i++){
		if(str[i] == '-'){
			continue;
		}
		else{
			ans = 10 * ans + Digit(str[i]);
		}
	}
	return ans;
}

void Print(int x, int count){
	int cur = 0;
	int divide = 1000000;
	char out[9];
	out[3] = '-';
	out[8] = '\0';
	for(int i = 0; i < 8; i++){
		if(i == 3){
			continue;
		}
		out[i] = x/divide + '0';
		x = x % divide;
		divide /= 10;
	}
	cout << out << " " <<count << endl;
}

int main(){
	int n;
	bool IsPrint = false;
	char str[201];
	cin >> n;
	memset(dic,0,sizeof(dic));
	for(int i = 0; i < n; i++){
		cin >> str;
		dic[Trans(str)]++;
	}
	for(int i = 0; i < 10000000; i++){
		if(dic[i] > 1){
			IsPrint = true;
			Print(i, dic[i]);
		}
	}
	if(!IsPrint){
		cout << "No duplicates." << endl;
	}
	return 0;
}
