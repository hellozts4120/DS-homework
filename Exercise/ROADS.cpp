#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int k,n,r;
int num;
const int MAX = 10010, INFINITE = 1000000;
int head[MAX];

struct Edge{
	int end,next;
	int dis,cost;
}Road[MAX];

struct Node{
	int id,cost,dis;
	bool operator < (const Node &a)const {
		return (a.dis < dis);
	};
};

void AddEdge(int a, int b, int c, int d){
	Road[num].dis = c;
	Road[num].end = b;
	Road[num].cost = d;
	Road[num].next = head[a];
	head[a] = num++;
}

int Dijkstra(){
	Node cur, next;
	priority_queue<Node> q;
	cur.id = 1; cur.cost = 0; cur.dis = 0;
	q.push(cur);
	int ans = INFINITE;

	while(!q.empty()){
		cur = q.top();
		q.pop();
		if(cur.id == n){
			ans = cur.dis;
			break;
		}
		for(int i = head[cur.id]; i != -1; i = Road[i].next){
			if(cur.cost + Road[i].cost <= k){
				next.id = Road[i].end;
				next.cost = cur.cost + Road[i].cost;
				next.dis = cur.dis + Road[i].dis;
				q.push(next);
			}
		}
	}
	return ans;
}

int main(){
	cin >> k >> n >> r;
	num = 0;
	memset(head,-1,sizeof(head));
	for(int i = 0; i < r; i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		AddEdge(a,b,c,d);
	}
	int ans = Dijkstra();
	if(ans == INFINITE){
		cout << -1 << endl;
	}
	else{
		cout << ans << endl;
	}
	return 0;
}