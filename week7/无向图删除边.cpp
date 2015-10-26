void delArc(ALGraph &g, int i,int j){
	ArcNode *temp;
	temp = g.vertices[i].firstarc;		//指向顶点i，删除i的边(i,j);
	while(temp){
		if(temp->nextarc->adjvex == j){
			g.vertices[i].firstarc = temp->nextarc;		//删除i的边;
			delete temp;
		}
		else{
			temp = temp->nextarc;		//继续查找
		}
	}
	temp = g.vertices[j].firstarc;		//指向顶点j，删除j的边(i,j);
	while(temp){
		if(temp->nextarc->adjvex == i){
			g.vertices[j].firstarc = temp->nextarc;		//删除i的边;
			delete temp;
		}
		else{
			temp = temp->nextarc;		//继续查找
		}
	}
}