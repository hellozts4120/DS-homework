#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char str1[100010],str2[100010];
	while(cin >> str1 >> str2){
		int i,j = 0;
		int len = strlen(str2);
		for(i = 0; str2[i]; i++){
			if(str2[i] == str1[j]){
				j++;
			}
			if(str1[j] == '\0'){
				break;
			}
		}
		if(str1[j] == '\0'){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}