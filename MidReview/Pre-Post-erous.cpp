/*	���� ��13 abejkcfghid jkebfghicda
    ��Ȼa,b����ȷ�����ɺ���֪ j,k,e�ض�Ϊ b �ĺ������ j,k,e �ݹ�ɻ��j,k,e��λ�ù�ϵ��ͬ������Ԫ�ض�����ȷ���Լ����ڵĲ�����
    ����ÿһ�㣬���������C(m��n)��֪������m����ѡn����������� m��ʾ����m��������n ���ʾ�ò�������	*/

#include<iostream>
#include<cstring>
using namespace std;

int m;

int C(int a,int b){
	int x = 1;
	for(int i = 0; i < b; i++){
		x *= (a - i);
	}
	for(int i = 1; i <= b; i++){
		x /= i;
	}
	return x;
}

int solve(int x,char *pre,char *post){
	int i = 1, j = 0;		//i��pre�±꣬j��post�±�
	int sum = 1, son = 0;	//sum�������son����������
	while(i < x){
		while(post[j] != pre[i]){
			j++;
		}
		son++;
		sum *= solve(j - i + 2,pre + i,post + i - 1);
		i = j + 2;
	}
	return sum * C(m,son);
}


int main(){
	char pre[30],post[30];
	while(cin >> m){
		if(!m){
			break;
		}
		cin >> pre >> post;
		cout << solve(strlen(pre),pre,post) << endl;
	}
	return 0;
}
