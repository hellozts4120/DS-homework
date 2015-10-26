#include<iostream>
using namespace std;
/*	本题中没有使用数据结构，直接采用枚举法枚举各种可能情况（数括号，详细分析见实验报告），暴力求解	*/

char str[1000];

int main(){
	int n;
	int cur = 0;	//前置标记点，标记指定字串的起始点
	int end = 0;	//后缀标记点，标记指定字串的终止点
	int k = cur;
	char opt;
	cin >> str;
	while(str[end++]);	//后缀标记点初始化
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> opt;
		if(opt == 'T'){		//Tail情况下将前置标记点向前，直到掠过Head元素结束
			int count = 0;
			while(str[k]){
				if(str[k] == '('){
					count++;
				}
				else if(str[k] == ')'){
					count--;
				}
				else if(str[k] == ','){
					if(count == 1){
						break;
					}
					else if(count == 0){
						break;
					}
				}
				k++;
			}
			cur = k;
			cur++;
			k++;
		}
		else if(opt == 'H'){	//Head情况下将后缀标记点前移，至Head元素之末尾结束
			int count = 0;
			while(str[k]){
				if(str[k] == '('){
					count++;
				}
				else if(str[k] == ')'){
					count--;
				}
				else if(str[k] == ','){
					if(count == 0){
						break;
					}
				}
				k++;
			}
			end = k;
			k = cur;
		}
	}
	for(int i = cur; i < end; i++){
		if(str[i] != '(' && str[i] != ')'){		//顺序输出前置——后缀范围内的所有非括号字符，即为所求元素
			cout << str[i];
		}
	}
	cout << endl;
	return 0;
}
