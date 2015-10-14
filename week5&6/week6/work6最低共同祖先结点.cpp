/*	核心思路：当存在这样一个结点：
			  此结点的左子树中存在X所属的结点，右子树中存在Y所属的结点；
			  这样的结点即为所求的最低共同祖先结点	
*/
bool IsHere(BiTNode* root,char tar){	//预处理函数，判断该结点是否在子树内，若不能单独开函数的话用lambda表达式嵌套到getLCA函数里面
	if(root == NULL){
		return false;
	}
	if(root->data == tar){
		return true;
	}
	bool flag = IsHere(root->LeftChild,tar);
	if(!flag){
		flag = IsHere(root->RightChild,tar);
	}
	return flag;
}

BiTNode* getLCA(BiTNode* root, char X, char Y){
	if(IsHere(root->LeftChild,X)){		//如果不能写第二个函数的话这里直接用lambda表达式嵌套
		if(IsHere(root->RightChild,Y)){
			return root;
		}
		else{
			return getLCA(root->LeftChild,X,Y);
		}
	}
	else{
		if(!IsHere(root->RightChild,X)){
			return NULL;
		}
		if(IsHere(root->LeftChild,Y)){
			return root;
		}
		else{
			return getLCA(root->RightChild,X,Y)
		}
	}
}