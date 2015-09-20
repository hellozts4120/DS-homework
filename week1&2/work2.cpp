#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<iostream>
using namespace std;

struct Link{
	int value;
	Link *next;
};

Link *Merge(Link *head1,Link *head2){
	Link *temp1,*temp2;
	Link *newone,*temp3;
	int i;
	temp1 = head1->next;
	temp2 = head2;
	temp3  = head1;
	newone = head1;
	newone->next = NULL;
	while(temp1 || temp2){
		if(temp1 == NULL){
			temp3 = temp2;
			temp2 = temp2->next;
		}
		else if(temp2 == NULL){
			temp3 = temp1;
			temp1 = temp1->next;
		}
		else if(temp1->value <= temp2->value){
			temp3 = temp1;
			temp1 = temp1->next;
		}
		else{
			temp3 = temp2;
			temp2 = temp2->next;
		}
		temp3->next = newone->next;
		newone->next = temp3;
	}
	i = newone->value;
	Link *temp4 = newone;
	while(temp4->next != NULL){
		if(temp4->next->value >= i){
			temp4->value = temp4->next->value;
			temp4->next->value = i;
		}
		temp4 = temp4->next;
	}
	return newone;
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
	Link *head2 = NULL;
	Link *newone = NULL;
	int n1,n2;
	cout << "Enter List1 Num:";
	cin >> n1;
	cout << "Enter List2 Num:";
	cin >> n2;
	cout << "Enter Value of List1:";
	for(int i = 0;i < n1;i++){
		head1 = append(head1);
	}
	PrintAll(head1);
	cout << "Enter Value of List2:";
	for(int i = 0;i < n2;i++){
		head2 = append(head2);
	}
	PrintAll(head2);
	cout << "Now Merge..." << endl;
	newone = Merge(head1,head2);
	PrintAll(newone);
	return 0;
}