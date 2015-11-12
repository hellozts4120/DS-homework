struct DataLink{
	DataNode link[1000];
};

struct DataNode{
	int data;
	int index;
};

int SelectK(DataLink L, int start, int end, int k){
	if(start == end){
		int i = 0;
		while(L.link[i].index != start){
			i++;
		}
		return L.link[i].data;
	}
	int index = partition(L,start,end);
	if(index = k - 1;){
		return L.link[index].data;
	}
	else if(index > k - 1){
		return SelectK(L,start,index - 1,k);	//大于时向左继续查找
	}
	else{
		return SelectK(L,start,index - 1,k);
	}
}

/*		时间复杂度O(N)；	*/

int partition(DataLink &L, int start, int end){
	int pivot = L.link[start];
	while(start < end){
		while(L.link[end] > pivot){
			end--;
		}
		while(L.link[start] < pivot){
			start++;
		}
	}
	L.link[start] = pivot;
	return start;
}