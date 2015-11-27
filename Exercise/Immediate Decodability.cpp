#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

struct Trie{
	Trie *child[2];
	int sum;
	Trie(){
		sum = 0;
		child[1] = child[0] = NULL;
	};
};

bool flag;

Trie *root = new Trie;

void Insert(char *str){
	Trie *temp = root, *cur;
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		int id = str[i] - '0';
		if(temp->child[id] == NULL){
			cur = new Trie;
			cur->sum = 1;
			temp->child[id] = cur;
			temp = temp->child[id];
		}
		else{
			temp = temp->child[id];
			if(i == len - 1 || ((temp->child[0] == NULL) && (temp->child[1] == NULL))){
				flag = 0;
				return;
			}
		}
	}
	return;
}

void Del(Trie *root){
	for(int i = 0; i < 2; i++){
		if(root->child[i] != NULL){
			Del(root->child[i]);
		}
	}
	delete root;
}

int main(){
	freopen("1.txt","r",stdin);
	int cases = 1;
	char str[50];
	flag = 1;
	while(scanf("%s",str) != EOF){
		root = new Trie;
		Insert(str);
		while(scanf("%s",str) != EOF && (str[0] != '9')){
			if(!flag){
				continue;
			}
			Insert(str);
		}
		if(flag){
			printf("Set %d is immediately decodable\n",cases++);
		}
		else{
			printf("Set %d is not immediately decodable\n",cases++);
		}
		Del(root);
	}
	return 0;
}