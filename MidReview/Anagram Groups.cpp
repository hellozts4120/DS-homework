#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct word{
	char str[50];
	char tras[50];
}WordIn[30005];

struct collect{
	char str[50];
	int size;
	int start;
}WordGroup[30005];

int cmp1(word a, word b){
	if(strcmp(a.tras,b.tras) != 0){
		return (strcmp(a.tras,b.tras) < 0);
	}
	else{
		return (strcmp(a.str,b.str) < 0);
	}
}

int cmp2(collect a, collect b){
	if(a.size != b.size){
		return (a.size > b.size);	//按容量大小降序排序
	}
	else{
		return (strcmp(a.str,b.str) < 0);		//容量相同时按照字符串字典序排序
	}
}

int main(){
	int count = 0;
	while(scanf("%s",WordIn[count].str) != EOF){
		strcpy(WordIn[count].tras,WordIn[count].str);
		int len = strlen(WordIn[count].str);
		sort(WordIn[count].tras,WordIn[count].tras + len);
		count++;
		//if(count == 16) break;
	}
	sort(WordIn,WordIn + count,cmp1);
	WordGroup[0].size = 1;
	WordGroup[0].start = 0;
	strcpy(WordGroup[0].str,WordIn[0].str);
	int cur = 1;
	for(int i = 1; i < count; i++){
		if(strcmp(WordIn[i].tras,WordIn[i - 1].tras) == 0){
			WordGroup[cur - 1].size++;
		}
		else{
			WordGroup[cur].size = 1;
			WordGroup[cur].start = i;
			strcpy(WordGroup[cur].str,WordIn[i].str);
			cur++;
		}
	}
	sort(WordGroup,WordGroup + cur,cmp2);
	int temp;
	for(int i = 0; i < 5; i++){
		cout << "Group of size " << WordGroup[i].size << ": ";
		int p = WordGroup[i].start; 
		for(int j = 0; j < WordGroup[i].size; j++){		//注意以下的操作，否则WA
			for(temp = j - 1; temp >=0; temp--){	//题目要求print equal words only once，不断比较当前位置到起始位置的单词，一旦发现重复则直接跳出
				if(!strcmp(WordIn[temp].str,WordIn[j].str)){
					break;
				}
			}
			if(temp < 0 || j == 0){
				cout << WordIn[p + j].str << " ";
			}
		}
			cout << "." << endl;
	}
	return 0;
}