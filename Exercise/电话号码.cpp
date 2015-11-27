#include<iostream>
#include<cstring>
using namespace std;

struct Trie{
	Trie *child[10];
	int sum;
	Trie(){
		memset(child,NULL,sizeof(child));
		sum = 0;
	};
}*root;

bool flag;

void Insert(char *str){
	Trie *temp = root, *cur;
	for(int i = 0; i < strlen(str); i++){
		int id = str[i] - '0';
		if(temp->child[id] == NULL){
			cur = new Trie;
			temp->child[id] = cur;
			temp = temp->child[id];
		}
		else{
			temp = temp->child[id];
			if(i == strlen(str) - 1 || temp->sum == 1){
				flag = 0;
				break;
			}
		}
	}
	temp->sum = 1;
}

void Del(Trie *root){
	for(int i = 0; i < 10; i++){
		if(root->child[i]){
			Del(root->child[i]);
		}
	}
	delete root;
}

int main(){
	int cases,n;
	cin >> cases;
	while(cases--){
		root = new Trie;
		cin >> n;
		flag = 1;
		for(int i = 0; i < n; i++){
			char str[11];
			cin >> str;
			if(flag){
				Insert(str);
			}
		}
		if(flag){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
		Del(root);
	}
	return 0;
}