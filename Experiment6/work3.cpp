#include<iostream>
using namespace std;
/*	������û��ʹ�����ݽṹ��ֱ�Ӳ���ö�ٷ�ö�ٸ��ֿ�������������ţ���ϸ������ʵ�鱨�棩���������	*/

char str[1000];

int main(){
	int n;
	int cur = 0;	//ǰ�ñ�ǵ㣬���ָ���ִ�����ʼ��
	int end = 0;	//��׺��ǵ㣬���ָ���ִ�����ֹ��
	int k = cur;
	char opt;
	cin >> str;
	while(str[end++]);	//��׺��ǵ��ʼ��
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> opt;
		if(opt == 'T'){		//Tail����½�ǰ�ñ�ǵ���ǰ��ֱ���ӹ�HeadԪ�ؽ���
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
		else if(opt == 'H'){	//Head����½���׺��ǵ�ǰ�ƣ���HeadԪ��֮ĩβ����
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
		if(str[i] != '(' && str[i] != ')'){		//˳�����ǰ�á�����׺��Χ�ڵ����з������ַ�����Ϊ����Ԫ��
			cout << str[i];
		}
	}
	cout << endl;
	return 0;
}
