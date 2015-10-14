void PreOrder(BiTNode *root){
	using std::stack;
	stack<BiTNode*>S;
	BiTNode* pointer = root;
	if(root == NULL){
		return;
	}
	while(pointer){
		putchar(root->data);	//遍历当前结点
		if(pointer->RightChild){	//右孩子入栈
			S.push(pointer->RightChild);
		}
		if(pointer->LeftChild){		//下降至左子树
			point = point->LeftChild;
		}
		else{	//左子树遍历完毕,开始记录右子树信息
			pointer = S.top();
			S.pop();
		}
	}
}