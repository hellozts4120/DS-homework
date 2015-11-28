#include<iostream>
#include<cstdlib>
using namespace std;

struct People{
	int num;
	int prior;
}Man[1000];

int cmp(const void *a, const void *b){
	return ((People *)b)->prior - ((People *)a)->prior;
}

int front = 0,rear = 0;

int main(){
	int cases;
	while(cin >> cases && cases){
		if(cases == 1){
			cin >> Man[rear].num >> Man[rear].prior;
			rear++;
			qsort(Man+front, rear-front, sizeof(People), cmp);
		}
		else if(cases == 2){
			if(front == rear){
				cout << 0 << endl;
			}
			else{
				cout << Man[front++].num << endl;
			}
		}
		else if(cases == 3){
			if(front == rear){
				cout << 0 << endl;
			}
			else{
				cout << Man[--rear].num << endl;
			}
		}
	}
	return 0;
}