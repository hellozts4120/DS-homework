int maxDis = 0;		//全局变量，保存所求值
int maxDistance(BiTNode * root){
	if(root == NULL){
		return 0;
	}
	int leftDis,rightDis;		//可看做是左右子树最大深度之和
	if(root->LeftChild){	//求左子树最大深度
		leftDis = maxDistance(root->LeftChild) + 1;
	}
	else{
		leftDis = 0;
	}
	if(root->RightChild){	//求右子树最大深度
		rightDis = maxDistance(root->RightChild) + 1;
	}
	else{
		rightDis = 0;
	}
	if(maxDis < leftDis + rightDis){
		maxDis = leftDis + rightDis;
	}
	return (leftDis > rightDis ? leftDis ; rightDis);
}