/*		��������Floyd�㷨������һ����Pre��¼ǰ����ͬʱ����ջ���.	*/
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
int Dist[MAXP][MAXP];	//��¼������̾���
int Pre[MAXP][MAXP];	//prev[x][y]����x-->y������̾��룬��ֵΪx����ͨ���м�u��x-->u-->y���̣���ֵΪu����֮������y��ǰ�����㡣

void InitDist(int v){	//��ʼ״̬��ͼ�ж��ǹ����ĵ㣬û�бߣ��Լ����Լ��ľ���Ϊ0����������ľ���Ϊ�����
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
		for(int j = 0;j < v;j++){
			Pre[i][j] = -1;
		}
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
	Pre[i][j] = i;
	Pre[j][i] = j;}
}

void Floyd(int v){	//use Floyd Algorithm
	for(int k = 0;k < v;k++){
		for(int i = 0;i < v;i++){
			for(int j = 0;j < v;j++){
				if(Dist[i][j] > (Dist[i][k] + Dist[k][j])){
					Dist[i][j] = (Dist[i][k] + Dist[k][j]);
					Pre[i][j] = Pre[k][j];
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
		current = Pre[i][current];
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
	int p,q,r;
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