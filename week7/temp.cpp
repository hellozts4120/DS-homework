template<Type> void Graph<Type> :: DFS_Tree ( const int v,  int visited [ ],  TreeNode<Type> *t ) {
//从图的顶点v出发, 深度优先遍历图, 建立以t (已在上层算法中建立)为根的生成树。
	Visited[v] = 1;  int first = 1;  TreeNode<Type> * p, * q;
	int w = GetFirstNeighbor ( v ); 					//取第一个邻接顶点
	while ( w != -1 ) {								//若邻接顶点存在
	if ( vosited[w] == 0 ) {							//且该邻接结点未访问过
	p = new TreeNode<Type> ( GetValue (w) );		//建立新的生成树结点
	if ( first == 1 ){ 						//若根*t还未链入任一子女
		t->setFirstChild ( p );
		first = 0; 
	}			//新结点*p成为根*t的第一个子女
	else q->setNextSibling ( p );					//否则新结点*p成为*q的下一个兄弟
		   q = p;									//指针q总指示兄弟链最后一个结点
		   DFS_Tree ( w, visited, q );					//从*q向下建立子树
		 }
		 w = GetNextNeighbor ( v, w );					//取顶点v排在邻接顶点w的下一个邻接顶点
	   }
	}
	下一个算法用于建立以左子女-右兄弟链表为存储表示的生成森林。
	template<Type> void Graph<Type> :: DFS_Forest ( Tree<Type> & T ) {
	//从图的顶点v出发, 深度优先遍历图, 建立以左子女-右兄弟链表表示的生成森林T。
	   T.root = NULL;  int n = NumberOfVertices ( );			//顶点个数
	   TreeNode<Type> * p, * q;
	   int * visited = new int [ n ];						//建立访问标记数组
	   for ( int v = 0; v < n; v++ ) visited[v] = 0;
	   for ( v = 0; v < n; v++ ) 							//逐个顶点检测
		 if ( visited[v] == 0 ) {							//若尚未访问过
		   p = new TreeNode<Type> ( GetValue ( v ) );		//建立新结点*p
		   if ( T.root == NULL ) T.root = p;				//原来是空的生成森林, 新结点成为根
		   else q-> setNextSibling ( p );					//否则新结点*p成为*q的下一个兄弟
		   q = p;
		   DFS_Tree ( v, visited, p );					//建立以*p为根的生成树
		 }
	} 