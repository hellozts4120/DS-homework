#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX = 1510;
int link[MAX],visit[MAX],n;
vector<int>map[MAX];

int DFS(int i){
	for(int j = 0; j < map[i].size(); j++){
		if(!visit[map[i][j]]){
			visit[map[i][j]] = 1;
			if(link[map[i][j]] == -1 || DFS(link[map[i][j]])){
				link[map[i][j]] = i;
				return 1;
			}
		}
	}
	return 0;
}


int main(){
	while(scanf("%d",&n) != EOF){
		int a,b,c;
		for(int i = 0; i < n; i++){
			map[i].clear();
		}
		for(int i = 0; i < n; i++){
			scanf("%d:(%d)",&a,&b);
			while(b--){
				scanf("%d",&c);
				map[a].push_back(c);
				map[c].push_back(a);
			}
		}
		int ans = 0;
		memset(link,-1,sizeof(link));
		for(int i = 0; i < n; i++){
			memset(visit,0,sizeof(visit));
			if(DFS(i)){
				ans++;
			}
		}
		printf("%d\n",ans/2);
	}
	return 0;
}
