#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char WrongList[27][5] = {"qsz","vgn","xdv","sefc","wdr","drgv","fthb","gyjn","uko","hukm","jil","ko","nj","bhm","il","o","aw","eft","awdx","rgy","yji","cfb","qse","zsc","thu","ax"};

struct Dict{		//存储正确文章中每个词的词典
	char str[300];
	int sum;
	bool visit;
	Dict(){
		str[0] = '\0';
		sum = 0;
		visit = false;
	}
}Dic[100107];

int Hash(char str[]){		//获取正确文章中每个词的hash值
    unsigned int seed = 131;  
    unsigned int key = 0;  
    for(int i = 0; str[i]; i++){
        key = key * seed + str[i];  
    }  
    return (key & 0x7FFFFFFF)%100107;  
}  

int main(){
	char word[50];
	freopen("word.txt","r",stdin);
	freopen("right.txt","w",stdout);
	while(scanf("%s",word) != EOF){		//输入正确文章中所有的单词，建立词典
		int key = Hash(word);
		while((strcmp(Dic[key].str,word)) != 0 && Dic[key].visit){
			key += 3;		//线性法解决冲突
		}
		if(!Dic[key].visit){
			strcpy(Dic[key].str,word);
			Dic[key].visit = true;
			Dic[key].sum += 1;
		}
		else{
			Dic[key].sum += 1;
		}
	}

	freopen("wrong.txt","r",stdin);
	while(scanf("%s",word) != EOF){		//逐个从错误单词列表中读取单词
		if(word[0] == '#' && word[1] == '\0'){
			break;
		}
		int times;
		int key = Hash(word);
		while((strcmp(Dic[key].str,word)) != 0 && Dic[key].visit){
			key += 3;		//线性法解决冲突
		}
		if(!Dic[key].visit){
			times = 0;
		}
		else{
			times = Dic[key].sum;
		}
		int MaxTime = times;
		char MaxStr[50],TempStr[50];
		memcpy(MaxStr,word,sizeof(word));
		memcpy(TempStr,word,sizeof(word));

		for(int i = 0; word[i]; i++){
			int id = word[i] - 'a';
			for(int j = 0; WrongList[id][j]; j++){
				word[i] = WrongList[id][j];
				int Key1 = Hash(word);
				while((strcmp(Dic[Key1].str,word)) != 0 && Dic[Key1].visit){
					Key1 += 3;		//线性法解决冲突
				}
				if(!Dic[Key1].visit){
					times = 0;
				}
				else{
					times = Dic[Key1].sum;
				}
				if(times > MaxTime){
					MaxTime = times;
					memcpy(MaxStr,word,sizeof(word));
				}
			}
			memcpy(word,TempStr,sizeof(TempStr));
		}
		int j = 1;TempStr[0] = word[0];
		for(int i = 1; word[i]; i++){
			if(word[i] == word[i - 1]){
				continue;
			}
			else{
				TempStr[j++] = word[i];
			}
		}
		TempStr[j] = '\0';
		int Key1 = Hash(TempStr);
		while((strcmp(Dic[Key1].str,TempStr)) != 0 && Dic[Key1].visit){
			Key1 += 3;		//线性法解决冲突
		}
		if(!Dic[Key1].visit){
			times = 0;
		}
		else{
			times = Dic[Key1].sum;
		}
		if(times > MaxTime){
			MaxTime = times;
			memcpy(MaxStr,TempStr,sizeof(word));
		}
		cout << MaxStr << endl;
	}

	cout << "#" << endl;
	return 0;
}
