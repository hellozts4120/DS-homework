#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
	string in;
	string str;
	map<string,int>Trans;
	int sum;
	Trans["zero"] = 0;Trans["one"] = 1;Trans["two"] = 2;Trans["three"] = 3;Trans["four"] = 4;Trans["five"] = 5;
	Trans["six"] = 6;Trans["seven"] = 7;Trans["eight"] = 8;Trans["nine"] = 9;Trans["ten"] = 10;Trans["eleven"] = 11;Trans["twelve"] = 12;
	Trans["thirteen"] = 13;Trans["fourteen"] = 14;Trans["fifteen"] = 15;Trans["sixteen"] = 16;Trans["seventeen"] = 17;Trans["eighteen"] = 18;
	Trans["nineteen"] = 19;Trans["twenty"] = 20;Trans["thirty"] = 30;Trans["forty"] = 40;Trans["fifty"] = 50;Trans["sixty"] = 60;
	Trans["seventy"] = 70;Trans["eighty"] = 80;Trans["ninety"] = 90;Trans["hundred"] = 100;Trans["thousand"] = 1000;Trans["million"] = 1000000;
	bool IsNegative = 0;
	while(getline(cin,in)){
		if(in == ""){
			break;
		}
		int cur = 0;
		int priority = 0;
		IsNegative = 0;
		sum = 0;
		in += ' ';
		str = "";
		for(int i = 0; in[i]; i++){
			if(in[i] != ' '){
				str += in[i];
			}
			else{
				if(str == "negative"){
					IsNegative = 1;
				}
				else if(str == "thousand" || str == "million"){
					if(Trans[str] > priority){
						priority = Trans[str];
						sum += (sum + cur) * Trans[str];
						cur = 0;
					}
					else{
						sum += cur * Trans[str];
						cur = 0;
					}
				}
				else if(str == "hundred"){
					cur *= Trans[str];
				}
				else{
					cur += Trans[str];
				}
				str = "";
			}
		}
		if(cur){
			sum += cur;
		}
		if(IsNegative){
			sum *= -1;
		}
		cout << sum << endl;
	}
	return 0;
}

