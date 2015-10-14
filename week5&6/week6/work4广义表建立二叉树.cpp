BiTNode* CreateBinTree(char *in){
	BiTNode* root = NULL;
	BiTNode* re = NULL;
	using std::stack;
	stack<char>S;
	BiTNode* p;
	int k;	//k=1:为当前根节点的左子树；k=2:为当前根节点的右子树
	while(*in != '#'){
		switch(*in){
			case '(':	//压栈：压入当前父节点，并准备植入左子树
				S.push(root);
				k = 1;
				*in++;
				break;
			case ')':	//出栈：弹出当前父节点
				S.pop();
				*in++;
				break;
			case ',':	//准备植入右子树
				k = 2;
				*in++;
				break;
			default:
				p = new BiTNode*;
				p->data = *in;
				p->LeftChild = NULL;
				p->RightChild = NULL;
				*in++;
				if(root == NULL){	//新建根节点
					root->LeftChild = p;
					re = root;	//保存根节点
				}
				else{
					if(k == 1){
						S.top()->LeftChild = p;
					}
					else{
						S.top()->RightChild = p;
					}
				}
		}
		root = p;	//将当前结点假设为父节点，若真如此可直接压栈
	}
	return re;
}