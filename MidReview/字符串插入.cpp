#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int MaxAscii,MaxLocation;
	char str[15],strIn[5];
	char strOut[20];
	while(cin >> str >> strIn){
		MaxAscii = 0;
		int len1 = strlen(str);
		for(int i = 0; i < len1; i++){
			if(int(str[i]) > MaxAscii){
				MaxLocation = i;
				MaxAscii = int(str[i]);
			}
		}
		for(int i = 0; i <= MaxLocation; i++){
			strOut[i] = str[i];
		}
		int k = 0;
		for(int i = MaxLocation+1; i <= MaxLocation+3; i++){
			strOut[i] = strIn[k++];
		}
		k = MaxLocation+4;
		for(int i = MaxLocation+1; str[i]; i++){
			strOut[k++] = str[i];
		}
		strOut[k] = '\0';
		cout << strOut << endl;
	}
	return 0;
}