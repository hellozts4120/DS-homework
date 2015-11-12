/*	基本设计思想:利用二分查找的思想，每次分别找出两个等长上升序列的中位数，并比较他们大小：
	(1):middle1 = middle2:则直接返回它们所代表的值，此即为整个序列的中位数
	(2):middle1 < middle2:舍弃1序列的较小半段和2序列的较大半段，再分别找出两个新序列的中位数，重复上述步骤；
	(3):middle1 > middle2:舍弃1序列的较大半段和2序列的较小半段，再分别找出两个新序列的中位数，重复上述步骤；
	当实现(1)或者两个数组中各只剩一个元素时跳出，比较仅剩的两个元素，返回其中的较小值，此即为所求中位数
*/

#include<iostream>
#include<algorithm>
using namespace std;

int GetMiddle(int *a, int *b, int n){		//主算法
	int left1 = 0, right1 = n - 1, left2 = 0, right2 = n - 1;
	int middle1,middle2;
	while((left1 != right1) || (left2 != right2)){
		middle1 = left1 + ((right1 - left1) >> 1);	//使用位运算，加快运算速度
		middle2 = left2 + ((right2 - left2) >> 1);
		if(a[middle1] == b[middle2]){	//此时中位数即为所求，直接返回即可
			return a[middle1];
		}
		else if(a[middle1] < b[middle2]){
			if((left1 + right1) % 2 == 0){		//数组长为奇数，此时直接舍弃两个前半段即可
				left1 = middle1;
				right2 = middle2;
			}
			else{
				left1 = middle1 + 1;	//数组长为偶数，此时较小中位数的序列要多舍弃一个元素，即较小中位数也要舍弃
				right2 = middle2;
			}
		}
		else{
			if((left1 + right1) % 2 == 0){		//数组长为奇数，同上
				left2 = middle2 + 1;
				right1 = middle1;
			}
			else{
				left2 = middle2;	//数组长为偶数，同上
				right1 = middle1;
			}
		}
	}
	return (a[middle1] > b[middle2] ? b[middle2] : a[middle1]);
}

/*		此算法的时间复杂度（大O表示法）为O(logN),最好情况可达到O(1)
		此算法的空间复杂度（大O表示法）为O(1)
*/

int main(){
	int str1[100],str2[100];
	int n;
	cout << "输入两个数组的元素个数：" ;
	cin >> n;
	cout << "输入数组1的每个元素：" ;
	for(int i = 0; i < n; i++){
		cin >> str1[i];
	}
	cout << "输入数组2的每个元素：" ;
	for(int i = 0; i < n; i++){
		cin >> str2[i];
	}
	sort(str1,str1 + n);
	sort(str2,str2 + n);
	int ans = GetMiddle(str1,str2,n);
	cout << "两个序列的中位数为：" << ans << endl;
	return 0;
}