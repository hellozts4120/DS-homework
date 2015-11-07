#include<iostream>
using namespace std;

int sum = 0;

void fun(int top,int n){
	if(top == -1 && !n){
		sum++;
		return;
	}
	else if(top == -1){
		top++;
		fun(top,--n);
		top--;
	}
	else if(n == 0){
		top--;
		fun(top,n);
	}
	else{
		top++;
		fun(top,--n);
		top -= 2;
		fun(top,++n);
	}
}

int main(){
	int in;
	int top = -1;
	cin >> in;
	fun(top,in);
	cout << sum << endl;
	return 0;
}