#include<iostream>
#include<cstring>
using namespace std;

short Hash[25000001];

int main(){
	int a1,a2,a3,a4,a5,x1,x2,x3,x4,x5;
	cin >> a1 >> a2 >> a3 >> a4 >> a5;
	memset(Hash,0,sizeof(Hash));
	int ans = 0;
	for(x1 = -50; x1 <= 50; x1++){
		if(!x1){
			continue;
		}
		for(x2 = -50; x2 <= 50; x2++){
			if(!x2){
				continue;
			}
			int sum = -(a1*(x1*x1*x1) + a2*(x2*x2*x2));
			if(sum < 0){
				sum += 25000000;
			}
			Hash[sum]++;
		}
	}
	for(x3 = -50; x3 <= 50; x3++){
		if(!x3){
			continue;
		}
		for(x4 = -50; x4 <= 50; x4++){
			if(!x4){
				continue;
			}
			for(x5 = -50; x5 <= 50; x5++){
				if(!x5){
					continue;
				}
				int sum = a3*(x3*x3*x3) + a4*(x4*x4*x4) + a5*(x5*x5*x5);
				if(sum < 0){
					sum += 25000000;
				}
				if(Hash[sum]){
					ans += Hash[sum];
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}