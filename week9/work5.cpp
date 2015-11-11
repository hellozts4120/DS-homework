bool IsAVL(BiNode *root){		//主函数
	if(IsBST(root) && IsBalanced(root,)){
		return true;
	}
	return false;
}

bool IsBST(BiNode *root){		//判断是否为BST
	if(!root){
		return true;
	}
	if(!IsBST(root->lchild)){
		return false;
	}
	if(!IsBST(root->rchild)){
		return false;
	}
	BiNode *left = root->lchild, *right = root->rchild;
	if((left->data > root-> data) || (right->data < root->data)){
		return false;
	}
	return true;
}

int Depth(BiNode *root){		//递归求树的深度
	if(!root){
		return 0;
	}
	int l,r;
	l = Depth(root->lchild);
	r = Depth(root->rchild);
	return 1 + (l > r ? l : r);
}

bool IsBalanced(BiNode *root){	//判断是否平衡
	if(!root){
		return true;
	}
	int MaxLong = Depth(root->lchild) - Depth(root->rchild);
	if(MaxLong > 1 || MaxLong < -1){
		return false;
	}
	else{
		return (IsBalanced(root->lchild) && IsBalanced(root->rchild));
	} 
}