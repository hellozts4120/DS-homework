BiTNode* CreateBinTree(char *in){
	BiTNode* root = NULL;
	using std::stack;
	stack<char>S;
	BiTNode* p;
	int k;
	while(*in != '#'){
		switch(*in++){
			case '(':
				S.push(*in++);//maybe wrong
				k = 1;
				break;
			case ')':
				S.pop();
				break;
			case ',':
				k = 2;
				break;
			default:
				p = new BiTNode*;
				//
				p->LeftChild = NULL;
				p->RightChild = NULL;
		}
		if(root == NULL){
			p = root;
		}
		else{
			if(k == 1){
				p->LeftChild = S.top();
			}
			else{
				p->RightChild = S.top();
			}
		}
		S.pop();
	}
}