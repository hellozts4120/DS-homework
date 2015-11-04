/*		方法：在Dijkstra算法中增加一数组Pre记录前驱，同时利用栈解决输出结点顺序的问题.	*/
#include<iostream>
#include<string>
#include<map>
#include<stack>
using namespace std;

map<string,int> vertex_index;
map<int,string> index_vertex;
stack<int> route;

const int MAXP = 30,INFINITE = 100000;
int map_index = 0;
int Dist[MAXP][MAXP];	//记录两点最短距离
int Final[MAXP];		//记录每个顶点的最短路径
int Pre[MAXP];	//prev[x][y]：若x-->y已是最短距离，此值为x；若通过中继u，x-->u-->y更短，此值为u。总之，储存y的前驱顶点。
int p,q,r;

void InitDist(int v){	//初始状态，图中都是孤立的点，没有边；自己到自己的距离为0，到其他点的距离为无穷大。
	for(int i = 0;i < v;i++){
		for(int j = 0;j < v;j++){
			Dist[i][j] = INFINITE;
		}
	}
	for(int i = 0;i < v;i++){
		Dist[i][i] = 0;
	}
}

void InitPre(int v){
	for(int i = 0;i < v;i++){
		Pre[i] = -1;
	}
}

void BuildPath(string from, string to, int dist){
	if(vertex_index.count(from) == 0){
		vertex_index[from] = map_index;
		index_vertex[map_index] = from;
		map_index++;
	}
	if(vertex_index.count(to) == 0){
		vertex_index[to] = map_index;
		index_vertex[map_index] = to;
		map_index++;
	}
	int i,j;
	i = vertex_index[from];
	j = vertex_index[to];
	if(Dist[i][j] > dist){
	Dist[i][j] = dist;
	Dist[j][i] = dist;
	Pre[i] = j;
	Pre[j] = i;}
}

void Diljkstra(int v){	//use Floyd Algorithm
	bool visited[MAXP];
	for(int i = 0; i < p; i++){
		Final[i] = Dist[v][i];
		visited[i] = false;
		if(Final[i] == INFINITE){
			Pre[i] = -1;
		}
		else{
			Pre[i] = v;
		}
	}
	Final[v] = 0;
	visited[v] = true;
	for(int i = 1; i < p; i++){
		int midist = INFINITE;
		int u = v;
		for(int j = 0; j < p; j++){
			if((!visited[j]) && Final[j] < midist){
				u = j;
				midist = Final[j];
			}
		}
		visited[u] = true;
		for(int j = 0; j < p; j++){
			if((!visited[j]) && Dist[u][j] < INFINITE){
				if(Final[u] + Dist[u][j] < Final[j]){
					Final[j] = Final[u] + Dist[u][j];
					Pre[j] = u;
				}
			}
		}
	}
}

void GetRoute(string from, string to){	//Get Route;
	int i = vertex_index[from];
	int j = vertex_index[to];
	int current = j;
	while(current != i){
		route.push(current);
		current = Pre[current];
	}
	cout << from;
	int Pre_Node = vertex_index[from];
	while(!route.empty()){
		current = route.top();
		cout << "->(" << Dist[Pre_Node][current] << ")->" << index_vertex[current];
		Pre_Node = current;
		route.pop();
	}
	cout << endl;
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string from,to;
	int dist;
	cin >> p;
	InitDist(p);
	InitPre(p);
	for(int i = 0;i < p;i++){
		cin >> from;	//useless loop;
	}
	cin >> q;
	for(int i = 0;i < q;i++){
		cin >> from >> to >> dist;
		BuildPath(from,to,dist);
	}
	Floyd(p);
	cin >> r;
	for(int i = 0;i < r;i++){
		cin >> from >> to;
		GetRoute(from,to);
	}
	return 0;
}