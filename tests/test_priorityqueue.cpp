TEST(PriorityQueue,empty){

	PriorityQueue pq;
	ASSERT_EQ(-1,pq.GetTop());
	ASSERT_EQ(-1,pq.GetTop());
	ASSERT_EQ(0,pq.GetCount());
}

TEST(PriorityQueue,addremove){
	PriorityQueue pq;
	ASSERT_EQ(-1,pq.GetTop());
	ASSERT_EQ(0,pq.GetCount());

	int index = 1;

	pq.Update(index, 1);
	ASSERT_EQ(index,pq.GetTop());
	ASSERT_EQ(1,pq.GetCount());
}

TEST(PriorityQueue,GetTop){
	int index1 = 1;
	int index2 = 2;
	int index3 = 3;

	PriorityQueue pq;
	pq.Update(index1,2);
	pq.Update(index2,3);
	pq.Update(index3,1);

	ASSERT_EQ(3,pq.GetCount());
	ASSERT_EQ(index2,pq.GetTop());
	ASSERT_EQ(index2,pq.GetTop());

	pq.Pop();
	ASSERT_EQ(2,pq.GetCount());

	ASSERT_EQ(index1,pq.GetTop());
	ASSERT_EQ(index1,pq.GetTop());

	pq.Pop();
	ASSERT_EQ(1,pq.GetCount());
	ASSERT_EQ(index3,pq.GetTop());
	ASSERT_EQ(index3,pq.GetTop());
	
	pq.Pop();
	ASSERT_EQ(0,pq.GetCount());
	ASSERT_EQ(-1,pq.GetTop());
	ASSERT_EQ(-1,pq.GetTop());
}



TEST(PriorityQueue,runningtimefor100updatedcars)
{
	const int MAXCOUNT = 10000;
	srand(time(NULL));
	PriorityQueue pq;
	std::map<int,int> priorities;

	//add 100 elements
	for (int i = 0; i < MAXCOUNT; ++i)
	{
		int index = i;
		int r = rand()%100;
		priorities[index] = r;
		pq.Update(index,r);		
	}

	//update 100 randomly chosen elements
	for (int i = 0; i < MAXCOUNT; ++i)
	{
		int index = rand()%MAXCOUNT;
		int r = rand()%100;
		priorities[index] = r;
		pq.Update(index,r);
		ASSERT_EQ(priorities.size(),pq.GetUniqueCount());
	}

	//remove 100 elements one by one
	int min = 1000;
	int prevcount = pq.GetCount();
	for (int i = 0; i < MAXCOUNT; ++i)
	{
		int index = pq.GetTop();
		int priority = priorities[index];
		priorities.erase(index);
		ASSERT_LE(priority,min);
		min = priority;
		pq.Pop();
		ASSERT_EQ(priorities.size(),pq.GetUniqueCount());
		ASSERT_LT(pq.GetCount(),prevcount);
		prevcount = pq.GetCount();
	}

	//on the end every element must be removed
	ASSERT_EQ(0,pq.GetCount());
	ASSERT_EQ(0,pq.GetUniqueCount());
}

