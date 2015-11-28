#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

/*	������������	*/
char WrongList[27][5] = {"qsz","vgn","xdv","sefc","wdr","drgv","fthb","gyjn","uko","hukm","jil","ko","nj","bhm","il","o","aw","eft","awdx","rgy","yji","cfb","qse","zsc","thu","ax"};

struct Dict{		//�洢��ȷ������ÿ���ʵĴʵ�
	char str[300];
	int sum;
	bool visit;
	Dict(){
		str[0] = '\0';
		sum = 0;
		visit = false;
	}
}Dic[100107];

int Hash(char str[]){		//��ȡ��ȷ������ÿ���ʵ�hashֵ
    unsigned int seed = 131;  
    unsigned int key = 0;  
    for(int i = 0; str[i]; i++){
        key = key * seed + str[i];  
    }  
    return (key & 0x7FFFFFFF)%100107;  
}

int SearchNum(int key, char word[]){	//���Һ��������ֵ��з���ָ�����ʵĳ��ִ���
	int times;
	while((strcmp(Dic[key].str,word)) != 0 && Dic[key].visit){
		key += 3;		//�������Է������ͻ
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
	freopen("word.txt","r",stdin);		//����freopen������ʹ�ò�������
	freopen("right.txt","w",stdout);
	while(scanf("%s",word) != EOF){		//������ȷ���������еĵ��ʣ������ʵ�
		int key = Hash(word);
		while((strcmp(Dic[key].str,word)) != 0 && Dic[key].visit){
			key += 3;		//�������Է������ͻ
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
	while(scanf("%s",word) != EOF){		//����Ӵ��󵥴��б��ж�ȡ����
		if(word[0] == '#' && word[1] == '\0'){
			break;
		}
		int key = Hash(word);
		int times = SearchNum(key, word);	//��¼�����ƴ��󵥴ʱ����������еĳ��ִ���
		int MaxTime = times;
		char MaxStr[50],TempStr[50];
		memcpy(MaxStr,word,sizeof(word));
		memcpy(TempStr,word,sizeof(word));

		for(int i = 0; word[i]; i++){	//�����ֵ䣬����ÿ�ֿ��ܵĴ�������Ŀ����ԣ���ֻ�������ֵ
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

		int j = 1;TempStr[0] = word[0];		//��ѯ�Ƿ��ж������������У����ش�������Ŀ�����
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
		cout << MaxStr << endl;		//��������ܵ��ַ���
	}

	cout << "#" << endl;
	return 0;
}
