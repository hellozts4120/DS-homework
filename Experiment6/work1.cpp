#include<iostream>
#include<cstring>

using namespace std;

struct HuffmanNode{		//Huffman树的基本定义
	int value;
	int parent;
	int left,right;
	int depth;
}Huffman[1000];

void MovingTree(int index, int deep){		//计算各叶节点的深度
	Huffman[index].depth = deep;
	if(Huffman[index].left > -1){
		MovingTree(Huffman[index].left, deep + 1);
	}
	if(Huffman[index].right > -1){
		MovingTree(Huffman[index].right, deep + 1);
	}
	return;
}

int main(){
	int n,i,weight,ans = 0;
	cin >> n;
	memset(Huffman,0,sizeof(HuffmanNode));
	for(int j = 0; j < n; j++){
		cin >> weight;
		Huffman[j].value = weight;
	}
	for(int j = 0; j < 2 * n + 1; j++){
		Huffman[j].left = Huffman[j].right = -1;
	}
/*		以下循环为计算各个父节点的信息		*/
	for(i = n; i < 2 * n - 1; i++){
		int min1 = 100000, min2 = 100000;
		int minIndex1 = -1, minIndex2 = -1;
		for(int j = 0; j < i; j++){
			if(Huffman[j].parent){
				continue;
			}
			if(Huffman[j].value < min1){
				min2 = min1;
				minIndex2 = minIndex1;
				min1 = Huffman[j].value;
				minIndex1 = j;
			}
			else if(Huffman[j].value < min2){
				min2 = Huffman[j].value;
				minIndex2 = j;
			}
		}
		Huffman[minIndex1].parent = i;
		Huffman[minIndex2].parent = i;
		Huffman[i].value = Huffman[minIndex1].value + Huffman[minIndex2].value;
		Huffman[i].left = minIndex1;
		Huffman[i].right = minIndex2;
	}
/*		循环结束	*/
	MovingTree(i - 1, 0);
	for(int j = 0; j < n; j++){		//计算总权值
		ans += Huffman[j].value * Huffman[j].depth;
	}
	cout << ans << endl;
	return 0;
}