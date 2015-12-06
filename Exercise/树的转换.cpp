#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 40010;
char str[MAX];

int main(){
	cin >> str;
	int TreeDepth = 0, TransDepth = 0, OrigDepth = 0;
	int far[MAX], son[MAX], depth[MAX];
	memset(far,0,sizeof(far));
	memset(son,0,sizeof(son));
	memset(depth,0,sizeof(depth));
	for(int i = 0; str[i]; i++){
		char ch = str[i];
		if(ch == 'd'){
			TreeDepth++;
			if(TreeDepth > OrigDepth){
				OrigDepth = TreeDepth;
			}
			far[i+1] = i;
			son[i]++;
			depth[i+1] = depth[i] + son[i];
			if(depth[i+1] > TransDepth){
				TransDepth = depth[i+1];
			}
		}
		else if(ch == 'u'){
			TreeDepth--;
			depth[i+1] = depth[far[i]];
			far[i+1] = far[far[i]];
			son[i+1] = son[far[i]];
		}
	}
	cout << OrigDepth << " => " << TransDepth << endl;
	return 0;
}