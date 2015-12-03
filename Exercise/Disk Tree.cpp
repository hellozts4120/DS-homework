#include<iostream>
#include<cstring>
using namespace std;

struct Node{
	Node *son;
	Node *brother;
	char name[10];
	Node(){
		son = NULL;
		brother = NULL;
		name[0] = '\0';
	};
};

Node *root;
int n;

Node *Insert(Node *root, char *key){
	Node *p, *q, *t;
	if(root->son == NULL || strcmp(root->son->name, key) > 0){
		t = new Node;
		strcpy(t->name, key);
		t->son = NULL;
		t->brother = root->son;
		root->son = t;
		return t;
	}
	if(!strcmp(root->son->name, key)){
		return root->son;
	}
	for(p=root->son,q=p->brother; q&&strcmp(q->name, key)<0; p=q,q=q->brother);
	if(q == NULL || strcmp(q->name, key) > 0){
		t= new Node;
		strcpy(t->name, key);
		t->son = NULL;
		t->brother = p->brother;
		p->brother = t;
		return t;
	}
	return q;
}

void GetName(char *str, char *key, int &cur){
	int i;
	for(i = 0; str[cur]!='\0' && str[cur]!='\\'; cur++,i++){
		key[i] = str[cur];
	}
	key[i] = '\0';
}

void Input(){
	char str[85], key[10];
	int cur = 0, j = 0;
	Node *p;
	root = new Node;
	cin >> n;
	for(int i = 0; i < n; i++){
		cur = 0;
		cin >> str;
		GetName(str,key,cur);
		for(p = Insert(root,key); str[cur];){
			GetName(str,key,++cur);
			p = Insert(p,key);
		}
	}
}

void Find(Node *root, int k){
	for(; root; root = root->brother){
		for(int i = 0; i < k; i++){
			cout << " ";
		}
		cout << root->name << endl;
		if(root->son){
			Find(root->son, k+1);
		}
	}
}

int main(){
	Input();
	Find(root->son, 0);
	cout << endl;
	return 0;
}