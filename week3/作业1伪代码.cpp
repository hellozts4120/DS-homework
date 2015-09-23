class Stack{
	public:
		int Push(int x);
		int Pop();
		void IsEmpty();
		void IsFull();
};

void test(int &sum){
	int x;
	scanf(x);
	Stack S;
	while(x!=0){
		S.Push(x);
		scanf(x);
	}
	int sum = 0;
	print(sum);
	while(!S.IsEmpty()){
		sum += S.Pop();
		print(sum);
	}
}