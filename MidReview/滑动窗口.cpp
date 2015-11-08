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
			rear--;		//清除队列中大于新元素的旧元素
		}
		queue[++rear] = i;	//插入新元素下标
		while(rear >= head && queue[head] < i+1-k){		//此时屏幕最左侧已滑到队首右端
			head++;		//清除队首超过范围的元素
		}
		if(i+1 >= k){
			cout << str[queue[head]] << " ";	//输出队守
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