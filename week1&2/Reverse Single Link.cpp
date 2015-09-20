Node *Reverse(Node *head){
	Node *p,*temp1,*temp2;
	temp1 = NULL;
	temp2 = hea;
	while(temp2 != NULL){
		p = temp2->next;
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = p;
	}
	return temp1;
}

