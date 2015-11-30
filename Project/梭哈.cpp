#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

int Card[4][13];

char YourC[4];
char DealC[4];
int AllCompare = 0;
int WinCompare = 0;
double percent;

void GetCard(int x,int N){		//���ļ��ж�ȡ�Ƶ���Ϣ
	char color[10], num[5];
	for(int i = 0; i < N; i++){
		cin >> color >> num;
		int curC,curN;
		if(!strcmp("spades",color)){
			curC = 3;
		}
		else if(!strcmp("hearts",color)){
			curC = 2;
		}
		else if(!strcmp("clubs",color)){
			curC = 1;
		}
		else{
			curC = 0;
		}
		if(num[0] == '1'){
			curN = 8;
		}
		else if(num[0] == 'J'){
			curN = 9;
		}
		else if(num[0] == 'Q'){
			curN = 10;
		}
		else if(num[0] == 'K'){
			curN = 11;
		}
		else if(num[0] == 'A'){
			curN = 12;
		}
		else{
			curN = num[0] - '2';
		}
		Card[curC][curN] = x;
	}
}

struct HandCard{
	int color[5];
	int num[5];
};

int cmp(const void *a, const void *b){
	return *((int *)a) - *((int *)b);
}

int CountSame(int *a, int n){	//��������������м�����ͬ��
	int count = 1;
	int Max = 1;
	for(int i = 0; i < n-1; i++){
		if(a[i] == a[i+1]){
			count++;
		}
		else{
			if(Max < count){Max = count;}
			count = 1;
		}
	}
	return Max;
}

int CountLiangDui(int *a, int n){	 //���������Ի��Ƕ���
	int count = 0;
	int pos[2];
	for(int i = 0; i < n-1; i++){
		if(a[i] == a[i+1]){
			pos[count] = i;
			count++;
		}
	}
	if(count == 2){
		return (pos[0]*10 + pos[1]);
	}
	if(count == 1){
		return -1;
	}
}

void GetYourType(HandCard &YourCard, int value, char *Your){	//�������ƣ���Ϊ���ĵĴ���
	int cur = 0;
	for(int i = 0; i < 4; i++){		 //�õ�����
		for(int j = 0; j < 13; j++){
			if(Card[i][j] == value){
				YourCard.color[cur] = i;
				YourCard.num[cur] = j;
				cur++;
			}
		}
	}
	qsort(YourCard.num, 5, sizeof(int), cmp);	//�����ư����Ƶĵ�������

	if(YourCard.color[0]==YourCard.color[1] && YourCard.color[0]==YourCard.color[2] && YourCard.color[0]==YourCard.color[3] && YourCard.color[0]==YourCard.color[4]){
		if((YourCard.num[1]-YourCard.num[0]==1) && (YourCard.num[2]-YourCard.num[1]==1) && (YourCard.num[3]-YourCard.num[2]==1) && ((YourCard.num[4]-YourCard.num[3]==1)||((YourCard.num[0]==0)&&(YourCard.num[4]==12)))){
			Your[0] = 9; Your[1] = YourCard.color[0]; Your[2] = YourCard.num[4];	//ͬ��˳
			//cout << "ͬ��˳" << endl;
		}
		else{
			Your[0] = 6; Your[1] = YourCard.color[0]; Your[2] = YourCard.num[4];	//ͬ��
			//cout << "ͬ��" << endl;
		}
	}
	else{
		int same = CountSame(YourCard.num, 5);
		if(same == 4){		//��֧
			if(YourCard.num[0] == YourCard.num[2]){
				Your[0] = 8; Your[1] = YourCard.num[2]; Your[2] = YourCard.num[4];
			}
			else{
				Your[0] = 8; Your[1] = YourCard.num[2]; Your[2] = YourCard.num[0];
			}
		}
		else if(same == 3){
			if(YourCard.num[0] == YourCard.num[2] && YourCard.num[3] == YourCard.num[4]){		//���ֺ�«
				Your[0] = 7; Your[1] = YourCard.num[2]; Your[2] = YourCard.num[4];
			}
			else if(YourCard.num[4] == YourCard.num[2] && YourCard.num[0] == YourCard.num[1]){	//���ֺ�«
				Your[0] = 7; Your[1] = YourCard.num[2]; Your[2] = YourCard.num[0];
			}
			else{		//����
				Your[0] = 4; Your[1] = YourCard.num[2];  Your[2] = 0;
			}
		}
		else if(same == 2){
			int temp = CountLiangDui(YourCard.num, 5);
			if(temp > 0){
				int a = temp%10, b = temp/10;		//����
				Your[0] = 3; Your[1] = max(YourCard.num[a], YourCard.num[b]); Your[2] = min(YourCard.num[a], YourCard.num[b]); Your[3] = YourCard.color[max(YourCard.num[a], YourCard.num[b])];
			}
			else{		//����
				int x;
				for(x = 0; x < 4; x++){
					if(YourCard.num[x] == YourCard.num[x+1]){
						break;
					}
				}
				Your[0] = 2; Your[1] = YourCard.num[x]; Your[2] = YourCard.color[x];
			}
		}
		else{
			if((YourCard.num[1]-YourCard.num[0]==1) && (YourCard.num[2]-YourCard.num[1]==1) && (YourCard.num[3]-YourCard.num[2]==1) && ((YourCard.num[4]-YourCard.num[3]==1)||((YourCard.num[0]==0)&&(YourCard.num[4]==12)))){
				//˳��
				Your[0] = 5; Your[1] = YourCard.num[4]; Your[2] = YourCard.color[4];
			}
			else{
				//ɢ��
				Your[0] = 1; Your[1] = YourCard.num[4]; Your[2] = YourCard.color[4];
			}
		}
	}
}

void Compare(){		//�ȽϺ���
	for(int i = 0; YourC[i]; i++){
		if(YourC[i] > DealC[i]){
			WinCompare += 1;
			return;
		}
		else if(YourC[i] < DealC[i]){
			return;
		}
	}
}

int main(){
	freopen("card.txt","r",stdin);
	freopen("answer.txt","w",stdout);
	memset(Card,0,sizeof(Card));
	GetCard(1,4);
	GetCard(2,5);
	HandCard YourCard, DealCard;	//�ֱ����������ƺ�ׯ�ҵ�����
	GetYourType(YourCard,2,YourC);
	for(int i = 0; i < 4; i++){		//ö��ׯ�����п��ܵ��������
		for(int j = 0; j < 13; j++){
			if(!Card[i][j]){
				AllCompare += 1;
				Card[i][j] = 1;
				GetYourType(DealCard,1,DealC);
				Compare();
				Card[i][j] = 0;
			}
		}
	}
	percent = (1.0 * WinCompare) / AllCompare;	//���ʤ��
	if(percent >= 0.5){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}