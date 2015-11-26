#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

vector<int> word[26];
queue<int> Q;
int InDegree[26];
int temp[26];
char OutPut[26];
int n,m;

bool Find(int a, int b){
	for(int i = 0; i < word[a].size(); i++){
		if(word[a][i] == b){
			return true;
		}
	}
	return false;
}

int TopSort(){
	while(!Q.empty()){
		Q.pop();
	}
	for(int i = 0; i < n; i++){
		if(!InDegree[i]){
			Q.push(i);
		}
	}
	int count = 0;
	bool UnSure = false;
	while(!Q.empty()){
		if(Q.size() > 1){
			UnSure = true;
		}
		int out = Q.front();
		OutPut[count++] = out + 'A';
		Q.pop();
		for(int i = 0; i < word[out].size(); i++){
			InDegree[word[out][i]]--;
			if(!InDegree[word[out][i]]){
				Q.push(word[out][i]);
			}
		}
	}
	if(count < n){
		return 3;
	}
	if(UnSure){
		return 2;
	}
	return 1;
}

int main(){
	while(cin >> n >> m){
		if(!n && !m){
			break;
		}
		memset(InDegree,0,sizeof(InDegree));
		memset(temp,0,sizeof(temp));
		for(int i = 0; i <= n; i++){
			word[i].clear();
		}
		int flag = 2;	//1:sure, 2:unsure, 3:wrong
		int pos;	//±£´æµ¯³öÎ»ÖÃ
		bool HaveOut = false;
		char a,b,mid;
		for(int i = 1; i <= m; i++){
			cin >> a >> mid >> b;
			if(HaveOut){
				continue;
			}
			if(!Find(a-'A',b-'A')){
				word[a-'A'].push_back(b-'A');
				InDegree[b-'A']++;
			}
			memcpy(temp, InDegree, sizeof(InDegree));
			flag = TopSort();
			memcpy(InDegree, temp, sizeof(temp));
			if(flag != 2){
				pos = i;
				HaveOut = true;
			}
		}
		if(flag == 1){
			cout << "Sorted sequence determined after " << pos << " relations: ";
			for(int i = 0; i < n; i++){
				cout << OutPut[i];
			}
			cout << "." << endl;
		}
		else if(flag == 2){
			cout << "Sorted sequence cannot be determined." << endl;
		}
		else{
			cout << "Inconsistency found after " << pos << " relations." << endl;
		}
	}
	return 0;
}
