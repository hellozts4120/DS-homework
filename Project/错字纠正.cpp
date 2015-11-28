#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

/*	错输的情况集合	*/
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

int SearchNum(int key, char word[]){	//查找函数，从字典中返回指定单词的出现次数
	int times;
	while((strcmp(Dic[key].str,word)) != 0 && Dic[key].visit){
		key += 3;		//采用线性法解决冲突
	}
	if(!Dic[key].visit){
		times = 0;
	}
	else{
		times = Dic[key].sum;
	}
	return times;
}

int main(){
	char word[50];
	freopen("word.txt","r",stdin);		//采用freopen函数，使得操作大大简化
	freopen("right.txt","w",stdout);
	while(scanf("%s",word) != EOF){		//输入正确文章中所有的单词，建立词典
		int key = Hash(word);
		while((strcmp(Dic[key].str,word)) != 0 && Dic[key].visit){
			key += 3;		//采用线性法解决冲突
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
		int key = Hash(word);
		int times = SearchNum(key, word);	//记录此疑似错误单词本身在文章中的出现次数
		int MaxTime = times;
		char MaxStr[50],TempStr[50];
		memcpy(MaxStr,word,sizeof(word));
		memcpy(TempStr,word,sizeof(word));

		for(int i = 0; word[i]; i++){	//遍历字典，返回每种可能的错输情况的可能性，并只保留最大值
			int id = word[i] - 'a';
			for(int j = 0; WrongList[id][j]; j++){
				word[i] = WrongList[id][j];
				int Key1 = Hash(word);
				times = SearchNum(Key1, word);
				if(times > MaxTime){
					MaxTime = times;
					memcpy(MaxStr,word,sizeof(word));
				}
			}
			memcpy(word,TempStr,sizeof(TempStr));
		}

		int j = 1;TempStr[0] = word[0];		//查询是否有多输的情况，若有，返回此种情况的可能性
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
		times = SearchNum(Key1, TempStr);
		if(times > MaxTime){
			MaxTime = times;
			memcpy(MaxStr,TempStr,sizeof(word));
		}
		cout << MaxStr << endl;		//输出最大可能的字符串
	}

	cout << "#" << endl;
	return 0;
}
