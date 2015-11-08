#include<iostream>
using namespace std;

int str[1000010];
int queue[1000010];

int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> str[i];
	}
	int head = 0, rear = -1;
	for(int i = 0; i < n; i++){
		while(rear >= head && str[i] <= str[queue[rear]]){
			rear--;		//��������д�����Ԫ�صľ�Ԫ��
		}
		queue[++rear] = i;	//������Ԫ���±�
		while(rear >= head && queue[head] < i+1-k){		//��ʱ��Ļ������ѻ��������Ҷ�
			head++;		//������׳�����Χ��Ԫ��
		}
		if(i+1 >= k){
			cout << str[queue[head]] << " ";	//�������
		}
	}
	cout << endl;
	head = 0; rear = -1;
	for(int i = 0; i < n; i++){
		while(rear >= head && str[i] >= str[queue[rear]]){
			rear--;		
		}
		queue[++rear] = i;
		while(rear >= head && queue[head] < i+1-k){
			head++;
		}
		if(i+1 >= k){
			cout << str[queue[head]] << " ";
		}
	}
	cout << endl;
	return 0;
}