#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<iostream>
#include<cstdlib>
using namespace std;

struct Link{
	int value;
	Link *next;
};

Link *LoopSearch(Link *head){
	Link *chaser,*L;
	bool looper = false;
	L = head;
	chaser = head;
	while(L -> next && chaser -> next){
		L = L -> next;
		chaser = chaser -> next;
		chaser = chaser -> next;
		if(L == chaser){
			looper = true;
			break;
		}
	}
	if(looper == false){
		L = NULL;
		cout << "No Loop! Return NULL!" << endl;
		return L;
	}
	else
		cout << "Have Loop! Return First Pointer to the Loop!" << endl;
		return L;
}

Link *MakeLoop(Link *head){
	Link *a = head;
	Link *b = head;
	while(a->next != NULL){
		a = a->next;
	}
	a->next = b;
	return head;
}

Link *append(Link *head){
	Link *temp = head,*p;
	p = (Link *)malloc(sizeof(Link));
	cin >> p->value;
	p->next = NULL;
	if(head == NULL) return p;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = p;
	return head;
}

void PrintAll(Link *head){
	Link *temp = head;
	int n = 1;
	if(head == NULL){
		cout << "Void LinkList!" << endl;
	}
	cout << "All Information:" << endl;
	while(temp != NULL){
		cout << "Index" << n << ": " << temp->value << endl;
		temp = temp->next;
		n++;
	}
}

int main(){
	Link *head1 = NULL;
	Link *result = NULL;
	int n,cases;
	cout << "Enter List Num:";
	cin >> n;
	cout << "Enter Value of List:";
	for(int i = 0;i < n;i++){
		head1 = append(head1);
	}
	PrintAll(head1);
	cout << "Input 1 to MakeLoop, else to Do Nothing!" << endl;
	cin >> cases;
	if(cases == 1) {head1 = MakeLoop(head1);}
	cout << "Input Enter to Test Loop!" << endl;
	system("pause");
	result = LoopSearch(head1);
	if(result){cout << "Return Value: " << result->value << endl;}
	return 0;
}
