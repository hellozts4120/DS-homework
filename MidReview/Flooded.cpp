#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int cmp(const void *a, const void *b){  
    return (*(int*)a) - (*(int*)b);  
}

int main(){
	int m,n;
	int Room[905];
	int RegionNum = 0;
	int Number;
	double WaterHeight;
	double WaterAll;
	double WaterCur;
	while(cin >> m >> n){
		if(!m && !n){
			break;
		}
		RegionNum++;
		cout << "Region " << RegionNum << endl;
		Number = m * n;
		for(int i = 0; i < Number; i++){
			cin >> Room[i];
		}
		cin >> WaterAll;
		qsort(Room,Number,sizeof(int),cmp);
		int WaterSum = 0;
		int i;
		WaterHeight = Room[0];
		if(WaterAll > 0){
			for(i = 1; i < Number; i++){
				WaterCur = 100 * (Room[i] - Room[i - 1]) * i;
				if(WaterSum + WaterCur < WaterAll){
					WaterSum += WaterCur;
					WaterHeight = Room[i];
				}
				else{
					WaterHeight += (WaterAll - WaterSum) / (100 * i);
					WaterSum = WaterAll;
					cout <<setiosflags(ios::fixed);
					cout << "Water level is " << setprecision(2) << WaterHeight << " meters." << endl;
					cout <<setiosflags(ios::fixed);
					cout << setprecision(2) << (100.0 * i) / Number << " percent of the region is under water." << endl;
					break;
				}
			}
			if(i == Number && WaterSum < WaterAll){
				WaterHeight += (WaterAll -WaterSum) / (100 * Number);
				cout <<setiosflags(ios::fixed);
				cout << "Water level is " << setprecision(2) << WaterHeight << " meters." << endl;
				cout <<setiosflags(ios::fixed);
				cout << setprecision(2) << (100.0 * i) / Number << " percent of the region is under water." << endl;
			}
		}
		else{
			cout <<setiosflags(ios::fixed);
			cout << "Water level is " << setprecision(2) << 0 << " meters." << endl;
			cout << setprecision(2) << 0 << " percent of the region is under water." << endl;
		}
	}
	return 0;
}