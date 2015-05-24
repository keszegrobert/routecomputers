TEST(FibonacciHeap,empty){

	FibonacciHeap fh;
	ASSERT_EQ(-1,fh.GetTop());
	ASSERT_EQ(-1,fh.GetTop());
	ASSERT_EQ(0,fh.GetCount());
}

TEST(FibonacciHeap,addremove){
	FibonacciHeap fh;
	ASSERT_EQ(-1,fh.GetTop());
	ASSERT_EQ(0,fh.GetCount());

	int index = 1;

	fh.Update(index, 1);
	ASSERT_EQ(index,fh.GetTop());
	ASSERT_EQ(1,fh.GetCount());
}

TEST(FibonacciHeap,GetTop){
	int index1 = 1;
	int index2 = 2;
	int index3 = 3;

	FibonacciHeap fh;
	fh.Update(index1,2);
	fh.Update(index2,3);
	fh.Update(index3,1);

	ASSERT_EQ(3,fh.GetCount());
	ASSERT_EQ(index3,fh.GetTop());
	ASSERT_EQ(index3,fh.GetTop());

	fh.Pop();
	ASSERT_EQ(2,fh.GetCount());

	ASSERT_EQ(index1,fh.GetTop());
	ASSERT_EQ(index1,fh.GetTop());

	fh.Pop();
	ASSERT_EQ(1,fh.GetCount());
	ASSERT_EQ(index2,fh.GetTop());
	ASSERT_EQ(index2,fh.GetTop());
	
	fh.Pop();
	ASSERT_EQ(0,fh.GetCount());
	ASSERT_EQ(-1,fh.GetTop());
	ASSERT_EQ(-1,fh.GetTop());
}



TEST(FibonacciHeap,runningtimefor100updatedcars)
{
	const int MAXCOUNT = 10000;
	srand(time(NULL));
	FibonacciHeap fh;
	std::map<int,int> priorities;

	//add 100 elements
	for (int i = 0; i < MAXCOUNT; ++i)
	{
		int index = i;
		int r = rand()%100;
		priorities[index] = r;
		fh.Update(index,r);		
//		std::cout << "index:" << index << ",r:" << r << std::endl;
	}

	//update 100 randomly chosen elements
	for (int i = 0; i < MAXCOUNT; ++i)
	{
		int index = rand()%MAXCOUNT;
		int r = rand()%100;
		priorities[index] = r;
		fh.Update(index,r);
		ASSERT_EQ(priorities.size(),fh.GetUniqueCount());
//		std::cout << "UPDATE:index:" << index << ",r:" << r << std::endl;
	}

	//remove 100 elements one by one
	int min = 0;
	int prevcount = fh.GetCount();
	for (int i = 0; i < MAXCOUNT; ++i)
	{
		int index = fh.GetTop();
		int priority = priorities[index];
//		std::cout << "CHECK:index:" << index << ",r:" << priority << std::endl;

		priorities.erase(index);
		ASSERT_GE(priority,min);
		min = priority;
		fh.Pop();
		ASSERT_EQ(priorities.size(),fh.GetUniqueCount());
		ASSERT_LT(fh.GetCount(),prevcount);
		prevcount = fh.GetCount();
	}

	//on the end every element must be removed
	ASSERT_EQ(0,fh.GetCount());
	ASSERT_EQ(0,fh.GetUniqueCount());
}

TEST(FibonacciHeap,sample)
{
	FibonacciHeap fh;
	ASSERT_EQ(-1,fh.GetTop());
	fh.Update(1,2);
	ASSERT_EQ(1,fh.GetTop());
	fh.Update(2,5);
	ASSERT_EQ(1,fh.GetTop());
	fh.Update(3,12);
	ASSERT_EQ(1,fh.GetTop());
	fh.Update(4,3);
	ASSERT_EQ(1,fh.GetTop());
	fh.Update(5,6);
	ASSERT_EQ(1,fh.GetTop());

	fh.GetTop();
	fh.Pop();
	fh.Update(6,2);
	fh.Update(7,34);
	fh.GetTop();
	fh.Pop();
	fh.GetTop();
	fh.Pop();
	fh.Update(8,6);
	fh.Update(9,14);
	fh.GetTop();
	fh.Pop();
	fh.GetTop();
	fh.Pop();
	fh.GetTop();
	fh.Pop();
	fh.GetTop();
	fh.Pop();
	fh.GetTop();
	fh.Pop();
	fh.GetTop();
	fh.Pop();
	fh.GetTop();
	fh.Pop();
	fh.GetTop();
	fh.Pop();
	fh.GetTop();
	fh.Pop();
	fh.GetTop();
	fh.Pop();
}