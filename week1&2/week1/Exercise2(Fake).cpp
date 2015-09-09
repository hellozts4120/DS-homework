ListType ListAdd(LinkList ha,LinkList hb,LinkList listOut){
	ha = headA;
	hb = headB;
	listOut = ha;
	while((listOut -> next) != NULL){
		listOut = listOut -> next;
	}
	listOut -> next = hb;
	return listOut
}

/*	Exercise3(Fake)	*/

ListType LoopSearch(LinkList L){
	ListType chaser;
	bool looper = false;
	L = head;
	chaser = head;
	while(L -> next && chaser -> next){
		L = L -> next;
		chaser = chaser -> next;
		chaser = chaser -> next;
		if(L == chaser){
			looper = true;
			break;
		}
	}
	if(looper == false){
		return NULL;
	}
	else
		return L;
}