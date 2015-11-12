/*	�������˼��:���ö��ֲ��ҵ�˼�룬ÿ�ηֱ��ҳ������ȳ��������е���λ�������Ƚ����Ǵ�С��
	(1):middle1 = middle2:��ֱ�ӷ��������������ֵ���˼�Ϊ�������е���λ��
	(2):middle1 < middle2:����1���еĽ�С��κ�2���еĽϴ��Σ��ٷֱ��ҳ����������е���λ�����ظ��������裻
	(3):middle1 > middle2:����1���еĽϴ��κ�2���еĽ�С��Σ��ٷֱ��ҳ����������е���λ�����ظ��������裻
	��ʵ��(1)�������������и�ֻʣһ��Ԫ��ʱ�������ȽϽ�ʣ������Ԫ�أ��������еĽ�Сֵ���˼�Ϊ������λ��
*/

#include<iostream>
#include<algorithm>
using namespace std;

int GetMiddle(int *a, int *b, int n){		//���㷨
	int left1 = 0, right1 = n - 1, left2 = 0, right2 = n - 1;
	int middle1,middle2;
	while((left1 != right1) || (left2 != right2)){
		middle1 = left1 + ((right1 - left1) >> 1);	//ʹ��λ���㣬�ӿ������ٶ�
		middle2 = left2 + ((right2 - left2) >> 1);
		if(a[middle1] == b[middle2]){	//��ʱ��λ����Ϊ����ֱ�ӷ��ؼ���
			return a[middle1];
		}
		else if(a[middle1] < b[middle2]){
			if((left1 + right1) % 2 == 0){		//���鳤Ϊ��������ʱֱ����������ǰ��μ���
				left1 = middle1;
				right2 = middle2;
			}
			else{
				left1 = middle1 + 1;	//���鳤Ϊż������ʱ��С��λ��������Ҫ������һ��Ԫ�أ�����С��λ��ҲҪ����
				right2 = middle2;
			}
		}
		else{
			if((left1 + right1) % 2 == 0){		//���鳤Ϊ������ͬ��
				left2 = middle2 + 1;
				right1 = middle1;
			}
			else{
				left2 = middle2;	//���鳤Ϊż����ͬ��
				right1 = middle1;
			}
		}
	}
	return (a[middle1] > b[middle2] ? b[middle2] : a[middle1]);
}

/*		���㷨��ʱ�临�Ӷȣ���O��ʾ����ΪO(logN),�������ɴﵽO(1)
		���㷨�Ŀռ临�Ӷȣ���O��ʾ����ΪO(1)
*/

int main(){
	int str1[100],str2[100];
	int n;
	cout << "�������������Ԫ�ظ�����" ;
	cin >> n;
	cout << "��������1��ÿ��Ԫ�أ�" ;
	for(int i = 0; i < n; i++){
		cin >> str1[i];
	}
	cout << "��������2��ÿ��Ԫ�أ�" ;
	for(int i = 0; i < n; i++){
		cin >> str2[i];
	}
	sort(str1,str1 + n);
	sort(str2,str2 + n);
	int ans = GetMiddle(str1,str2,n);
	cout << "�������е���λ��Ϊ��" << ans << endl;
	return 0;
}