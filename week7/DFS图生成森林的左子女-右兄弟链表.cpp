template<typename T>
void DFS_Tree(const int i, int visited[], TreeNode<T> *root){	//建立生成树
	visited[i] = 1;
	int first = 1;
	TreeNode<T> *p, *q;
	int j = GetFirstNeighbor(i);		//取j为i的第一个邻接顶点;
	while(j != -1){				//若邻接结点存在
		if(visited[j] == 0){		//j仍然没有被访问;
			p = new TreeNode<T>*；
			GetValue(p);
			if(first == 1){			//若根*root还未链入任一子女
				root->SetFirstChild(p);		//p成为root的第一个子
				first = 0;
			}
			else{
				q->NewNextSibling(p);		//p成为q的下一个兄弟;
			}
			q = p;					//指针q总指示兄弟链最后一个结点
			DFS_Tree(j,visited,q);	//从q向下建立子树
		}
		j = GetNextNeighbor(i,j);	//取顶点v排在邻接顶点w的下一个邻接顶点
	}
}

void DFS_Forest(Tree<T> &t){		//建立左子女-右兄弟链表为存储表示的生成森林
	t.root = NULL;
	int n = NumOfVertices();
	TreeNode<T> *p, *q;
	int *visited = new int[n];
	for(int i = 0; i < n; i++){
		visited[i] = 0;
	}
	for(int i = 0; i < n; i++){
		if(visited[i] == 0){
			p = new TreeNode<T>*;
			GetValue(p);
			if(t.root == NULL){		//原来是空的森林，则新节点成为根
				t.root = p;
			}
			else{
				q->SetNextSibling	//否则新结点*p成为*q的下一个兄弟
			}
			q = p;
			DFS_Tree(i,visited,p);	//建立以*p为根的生成树
		}
	}
}