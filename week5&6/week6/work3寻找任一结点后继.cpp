BiThrNode * PreOrderFindNext(BiThrTree T, BiThrNode *node){
	if(Value(T,node)){	//此结点存在于树中
		if(!node->LTag){
			return node->lchild;
		}
		else{
			return node->rchild;
		}
	}
	else{
		return NULL;	//若此节点不存在于树中，则返回空
	}
}