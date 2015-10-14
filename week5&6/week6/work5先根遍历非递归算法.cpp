void PreOrder(BiTNode *root){
	using std::stack;
	stack<BiTNode*>S;
	BiTNode* pointer = root;
	if(root == NULL){
		return;
	}
	while(pointer){
		putchar(root->data);	//������ǰ���
		if(pointer->RightChild){	//�Һ�����ջ
			S.push(pointer->RightChild);
		}
		if(pointer->LeftChild){		//�½���������
			point = point->LeftChild;
		}
		else{	//�������������,��ʼ��¼��������Ϣ
			pointer = S.top();
			S.pop();
		}
	}
}