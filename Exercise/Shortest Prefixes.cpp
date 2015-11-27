#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

struct Trie{
	Trie *child[26];
	int sum;
	Trie(){
		sum = 0;
		memset(child,NULL,sizeof(child));
	};
};

Trie *root = new Trie;

void Insert(char *str){
	Trie *temp = root, *cur;
	int len = strlen(str);
	for(int i = 0; i <len; i++){
		int id = str[i] - 'a';
		if(temp->child[id] == NULL){
			cur = new Trie;
			cur->sum = 1;
			temp->child[id] = cur;
			temp = temp->child[id];
		}
		else{
			(temp->child[id]->sum)++;
			temp = temp->child[id];
		}
	}
}

void Search(char *str){
	char ans[21];
	Trie *temp = root;
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		int id = str[i] - 'a';
		temp = temp->child[id];
		ans[i] = str[i];
		ans[i+1] = '\0';
		if(temp->sum == 1){
			cout << str << " " << ans << endl;
			return;
		}
	}
	cout << str << " " << str << endl;
	return;
}

int main(){
	//freopen("1.txt","r",stdin);
	char word[1010][21];
	int t = 0;
	while(scanf("%s",word[t]) != EOF){
		Insert(word[t]);
		t++;
	}
	for(int i = 0; i < t; i++){
		Search(word[i]);
	}
	return 0;
}