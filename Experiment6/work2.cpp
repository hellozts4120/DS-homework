#include<iostream>
#include<stack>
#include<string>
using namespace std;

enum ElemTag{A,L};   

struct GNode{
	ElemTag Tag;
	union{
		char data;
		struct{
			GNode *head;
			GNode *tail;
		}ptr;
	};
};

string Cut(string &S){
	int n,i,k;
	string ch,h;
	n = S.length();
	for(i = 0,k = -1; i < n && (ch != "," || k != 0); i++){
		ch = S.substr(i,1);
		if(ch == "("){
			k++;
		}
		else if(ch == ")"){
			k--;
		}
	}
	if(i < n){
		h = S.substr(1,i - 2);
		S = "(" + S.substr(i,n - i);  
	}
	else{
		h = S.substr(1,n - 2);
		S = "";
	}
	return h;
}

void Create(GNode *&G, string S){
	string Sub;
	if(S == "()"){
		G = NULL;
	}
	else{
		G = new GNode;
		if(S.length() == 1){
			G->Tag = A;
			G->data = S[0];
		}
		else{
			G->Tag = L;
			Sub = Cut(S);
			Create(G->ptr.head,Sub);
			if(S.empty()){
				G->ptr.tail = NULL;
			}
			else{
				Create(G->ptr.tail,S);
			}
		}
	}
}

void Traverse(GNode *G){
	if(G == NULL){
		cout << "()";
	}
	else{
		if(G->Tag == A){
			cout << G->data;
		}
		else{
			GNode *p = NULL;
			cout << "(";
			p = G;
			while(p){
				Traverse(p->ptr.head);
				p = p->ptr.tail;
				if(p){
					cout << ",";
				}
				cout << ")";
			}
		}
	}
}

GNode* GetHead(GNode *G){
	return G->ptr.head;
}

GNode* GetTail(GNode *G){
	return G->ptr.tail;
}

int main(){
	int n;
	char temp;
	GNode *G = NULL;
	string S;
	cin >> S;
	Create(G,S);
	GNode *t = G;
	cin >> n;
	/*for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp == 'T'){
			t = GetTail(t);
		}
		if(temp == 'H'){
			t = GetHead(t);
		}
	}
	while(t->ptr.head->Tag == A){
		cout << t->data;
		t = t->ptr.head;
	}*/
	Traverse(G);
	cout <<endl;
	return 0;
}