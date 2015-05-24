TEST_F(SampleGraph,dijkstra_update)
{

	Dijkstra d;
	d.SetGraph(&g);
	int pos = 0;

	std::vector<int> route;
	route.push_back(0);

	std::map<int,int> changes;

	d.GetFromWhere()[0] = 0;
	d.GetDistances()[0] = 0;

//step #1
	pos = d.Update(pos,changes);
	ASSERT_EQ(1,pos);
	route.push_back(pos);
	ASSERT_EQ(4,d.GetDistances().size());
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(0));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(1));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(2));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(3));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(4));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(5));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(6));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(7));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(8));

	ASSERT_EQ(0,d.GetFromWhere()[0]);
	ASSERT_EQ(0,d.GetFromWhere()[1]);
	ASSERT_EQ(0,d.GetFromWhere()[3]);
	ASSERT_EQ(0,d.GetFromWhere()[4]);

	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(0));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(1));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(2));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(3));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(4));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(5));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(6));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(7));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(8));

	ASSERT_EQ(0,d.GetDistances()[0]);
	ASSERT_EQ(2,d.GetDistances()[1]);
	ASSERT_EQ(9,d.GetDistances()[3]);
	ASSERT_EQ(6,d.GetDistances()[4]);


	ASSERT_EQ(3,changes.size());
	ASSERT_EQ(2,changes[1]);
	ASSERT_EQ(9,changes[3]);
	ASSERT_EQ(6,changes[4]);

	changes.clear();
//step #2
	pos = d.Update(pos,changes);
	ASSERT_EQ(2,pos);
	route.push_back(pos);
	ASSERT_EQ(5,d.GetDistances().size());
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(0));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(1));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(2));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(3));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(4));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(5));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(6));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(7));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(8));

	ASSERT_EQ(0,d.GetDistances()[0]);
	ASSERT_EQ(2,d.GetDistances()[1]);
	ASSERT_EQ(3,d.GetDistances()[2]);
	ASSERT_EQ(9,d.GetDistances()[3]);
	ASSERT_EQ(5,d.GetDistances()[4]);

	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(0));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(1));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(2));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(3));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(4));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(5));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(6));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(7));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(8));


	ASSERT_EQ(0,d.GetFromWhere()[0]);
	ASSERT_EQ(0,d.GetFromWhere()[1]);
	ASSERT_EQ(1,d.GetFromWhere()[2]);
	ASSERT_EQ(0,d.GetFromWhere()[3]);
	ASSERT_EQ(1,d.GetFromWhere()[4]);

	ASSERT_EQ(2,changes.size());
	ASSERT_EQ(3,changes[2]);
	ASSERT_EQ(5,changes[4]);

	changes.clear();

//step #3

	pos = d.Update(pos,changes);
	ASSERT_EQ(4,pos);
	route.push_back(pos);
	ASSERT_EQ(6,d.GetDistances().size());
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(0));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(1));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(2));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(3));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(4));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(5));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(6));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(7));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(8));

	ASSERT_EQ(0,d.GetDistances()[0]);
	ASSERT_EQ(2,d.GetDistances()[1]);
	ASSERT_EQ(3,d.GetDistances()[2]);
	ASSERT_EQ(9,d.GetDistances()[3]);
	ASSERT_EQ(4,d.GetDistances()[4]);
	ASSERT_EQ(9,d.GetDistances()[6]);

	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(0));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(1));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(2));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(3));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(4));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(5));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(6));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(7));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(8));


	ASSERT_EQ(0,d.GetFromWhere()[0]);
	ASSERT_EQ(0,d.GetFromWhere()[1]);
	ASSERT_EQ(1,d.GetFromWhere()[2]);
	ASSERT_EQ(0,d.GetFromWhere()[3]);
	ASSERT_EQ(2,d.GetFromWhere()[4]);
	ASSERT_EQ(2,d.GetFromWhere()[6]);

	ASSERT_EQ(2,changes.size());
	ASSERT_EQ(4,changes[4]);
	ASSERT_EQ(9,changes[6]);

	changes.clear();
//step #4

	pos = d.Update(pos,changes);
	ASSERT_EQ(3,pos);
	route.push_back(pos);
	ASSERT_EQ(8,d.GetDistances().size());
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(0));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(1));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(2));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(3));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(4));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(5));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(6));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(7));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(8));

	ASSERT_EQ(0,d.GetDistances()[0]);
	ASSERT_EQ(2,d.GetDistances()[1]);
	ASSERT_EQ(3,d.GetDistances()[2]);
	ASSERT_EQ(6,d.GetDistances()[3]);
	ASSERT_EQ(4,d.GetDistances()[4]);
	ASSERT_EQ(13,d.GetDistances()[5]);
	ASSERT_EQ(9,d.GetDistances()[6]);

	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(0));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(1));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(2));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(3));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(4));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(5));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(6));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(7));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(8));


	ASSERT_EQ(0,d.GetFromWhere()[0]);
	ASSERT_EQ(0,d.GetFromWhere()[1]);
	ASSERT_EQ(1,d.GetFromWhere()[2]);
	ASSERT_EQ(4,d.GetFromWhere()[3]);
	ASSERT_EQ(2,d.GetFromWhere()[4]);
	ASSERT_EQ(4,d.GetFromWhere()[5]);

	ASSERT_EQ(3,changes.size());
	ASSERT_EQ(6,changes[3]);
	ASSERT_EQ(13,changes[5]);
	ASSERT_EQ(11,changes[7]);

	changes.clear();
//step #5

	pos = d.Update(pos,changes);
	ASSERT_EQ(7,pos);
	route.push_back(pos);
	ASSERT_EQ(8,d.GetDistances().size());
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(0));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(1));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(2));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(3));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(4));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(5));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(6));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(7));
	ASSERT_TRUE(d.GetDistances().end()==d.GetDistances().find(8));

	ASSERT_EQ(0,d.GetDistances()[0]);
	ASSERT_EQ(2,d.GetDistances()[1]);
	ASSERT_EQ(3,d.GetDistances()[2]);
	ASSERT_EQ(6,d.GetDistances()[3]);
	ASSERT_EQ(4,d.GetDistances()[4]);
	ASSERT_EQ(13,d.GetDistances()[5]);
	ASSERT_EQ(9,d.GetDistances()[6]);

	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(0));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(1));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(2));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(3));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(4));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(5));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(6));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(7));
	ASSERT_TRUE(d.GetFromWhere().end()==d.GetFromWhere().find(8));


	ASSERT_EQ(0,d.GetFromWhere()[0]);
	ASSERT_EQ(0,d.GetFromWhere()[1]);
	ASSERT_EQ(1,d.GetFromWhere()[2]);
	ASSERT_EQ(4,d.GetFromWhere()[3]);
	ASSERT_EQ(2,d.GetFromWhere()[4]);
	ASSERT_EQ(4,d.GetFromWhere()[5]);

	ASSERT_EQ(1,changes.size());
	ASSERT_EQ(10,changes[7]);

	changes.clear();
//step #6

	pos = d.Update(pos,changes);
	ASSERT_EQ(5,pos);
	route.push_back(pos);
	ASSERT_EQ(9,d.GetDistances().size());
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(0));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(1));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(2));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(3));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(4));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(5));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(6));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(7));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(8));

	ASSERT_EQ(0,d.GetDistances()[0]);
	ASSERT_EQ(2,d.GetDistances()[1]);
	ASSERT_EQ(3,d.GetDistances()[2]);
	ASSERT_EQ(6,d.GetDistances()[3]);
	ASSERT_EQ(4,d.GetDistances()[4]);
	ASSERT_EQ(11,d.GetDistances()[5]);
	ASSERT_EQ(9,d.GetDistances()[6]);

	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(0));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(1));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(2));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(3));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(4));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(5));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(6));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(7));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(8));


	ASSERT_EQ(0,d.GetFromWhere()[0]);
	ASSERT_EQ(0,d.GetFromWhere()[1]);
	ASSERT_EQ(1,d.GetFromWhere()[2]);
	ASSERT_EQ(4,d.GetFromWhere()[3]);
	ASSERT_EQ(2,d.GetFromWhere()[4]);
	ASSERT_EQ(7,d.GetFromWhere()[5]);

	ASSERT_EQ(2,changes.size());
	ASSERT_EQ(15,changes[8]);
	ASSERT_EQ(11,changes[5]);

	changes.clear();
//step #7

	pos = d.Update(pos,changes);
	ASSERT_EQ(8,pos);
	route.push_back(pos);
	ASSERT_EQ(9,d.GetDistances().size());
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(0));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(1));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(2));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(3));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(4));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(5));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(6));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(7));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(8));

	ASSERT_EQ(0,d.GetDistances()[0]);
	ASSERT_EQ(2,d.GetDistances()[1]);
	ASSERT_EQ(3,d.GetDistances()[2]);
	ASSERT_EQ(6,d.GetDistances()[3]);
	ASSERT_EQ(4,d.GetDistances()[4]);
	ASSERT_EQ(11,d.GetDistances()[5]);
	ASSERT_EQ(9,d.GetDistances()[6]);

	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(0));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(1));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(2));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(3));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(4));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(5));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(6));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(7));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(8));


	ASSERT_EQ(0,d.GetFromWhere()[0]);
	ASSERT_EQ(0,d.GetFromWhere()[1]);
	ASSERT_EQ(1,d.GetFromWhere()[2]);
	ASSERT_EQ(4,d.GetFromWhere()[3]);
	ASSERT_EQ(2,d.GetFromWhere()[4]);
	ASSERT_EQ(7,d.GetFromWhere()[5]);

	ASSERT_EQ(1,changes.size());
	ASSERT_EQ(12,changes[8]);
	changes.clear();

	ASSERT_EQ(8,route.size());
	ASSERT_EQ(8,route[7]);
	ASSERT_EQ(5,route[6]);
	ASSERT_EQ(7,route[5]);
	ASSERT_EQ(3,route[4]);
	ASSERT_EQ(4,route[3]);
	ASSERT_EQ(2,route[2]);
	ASSERT_EQ(1,route[1]);
	ASSERT_EQ(0,route[0]);

}

TEST_F(SampleGraph,dijkstra_compute)
{
	Dijkstra d;
	d.SetGraph(&g);
	d.SetStart(0);

	ASSERT_TRUE(d.Compute());

	ASSERT_EQ(9,d.GetDistances().size());
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(0));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(1));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(2));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(3));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(4));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(5));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(6));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(7));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(8));

	ASSERT_EQ(0,d.GetDistances()[0]);
	ASSERT_EQ(2,d.GetDistances()[1]);
	ASSERT_EQ(3,d.GetDistances()[2]);
	ASSERT_EQ(6,d.GetDistances()[3]);
	ASSERT_EQ(4,d.GetDistances()[4]);
	ASSERT_EQ(11,d.GetDistances()[5]);
	ASSERT_EQ(9,d.GetDistances()[6]);

	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(0));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(1));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(2));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(3));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(4));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(5));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(6));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(7));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(8));


	ASSERT_EQ(0,d.GetFromWhere()[0]);
	ASSERT_EQ(0,d.GetFromWhere()[1]);
	ASSERT_EQ(1,d.GetFromWhere()[2]);
	ASSERT_EQ(4,d.GetFromWhere()[3]);
	ASSERT_EQ(2,d.GetFromWhere()[4]);
	ASSERT_EQ(7,d.GetFromWhere()[5]);

	ASSERT_EQ(12,d.GetDistanceTo(8));

	std::vector<int> route;
	d.GetRouteTo(8,route);

	ASSERT_EQ(8,route.size());
	ASSERT_EQ(0,route[7]);
	ASSERT_EQ(1,route[6]);
	ASSERT_EQ(2,route[5]);
	ASSERT_EQ(4,route[4]);
	ASSERT_EQ(3,route[3]);
	ASSERT_EQ(7,route[2]);
	ASSERT_EQ(5,route[1]);
	ASSERT_EQ(8,route[0]);

}


TEST_F(SampleGraph,quick_dijkstra_compute)
{
	QuickDijkstra d;
	d.SetGraph(&g);
	d.SetStart(0);
	ASSERT_TRUE(d.Compute());

	ASSERT_EQ(9,d.GetDistances().size());
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(0));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(1));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(2));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(3));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(4));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(5));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(6));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(7));
	ASSERT_FALSE(d.GetDistances().end()==d.GetDistances().find(8));

	ASSERT_EQ(0,d.GetDistances()[0]);
	ASSERT_EQ(2,d.GetDistances()[1]);
	ASSERT_EQ(3,d.GetDistances()[2]);
	ASSERT_EQ(6,d.GetDistances()[3]);
	ASSERT_EQ(4,d.GetDistances()[4]);
	ASSERT_EQ(11,d.GetDistances()[5]);
	ASSERT_EQ(9,d.GetDistances()[6]);

	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(0));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(1));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(2));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(3));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(4));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(5));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(6));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(7));
	ASSERT_FALSE(d.GetFromWhere().end()==d.GetFromWhere().find(8));


	ASSERT_EQ(0,d.GetFromWhere()[0]);
	ASSERT_EQ(0,d.GetFromWhere()[1]);
	ASSERT_EQ(1,d.GetFromWhere()[2]);
	ASSERT_EQ(4,d.GetFromWhere()[3]);
	ASSERT_EQ(2,d.GetFromWhere()[4]);
	ASSERT_EQ(7,d.GetFromWhere()[5]);

	ASSERT_EQ(12,d.GetDistanceTo(8));

	std::vector<int> route;
	d.GetRouteTo(8,route);

	ASSERT_EQ(8,route.size());
	ASSERT_EQ(0,route[7]);
	ASSERT_EQ(1,route[6]);
	ASSERT_EQ(2,route[5]);
	ASSERT_EQ(4,route[4]);
	ASSERT_EQ(3,route[3]);
	ASSERT_EQ(7,route[2]);
	ASSERT_EQ(5,route[1]);
	ASSERT_EQ(8,route[0]);

}


TEST_F(SampleWithNegativeWeights,dijkstra_compute)
{

	Dijkstra d;
	d.SetGraph(&g);
	
	std::map<int,int> changes;

	d.GetFromWhere()[1] = 1;
	d.GetDistances()[1] = 0;

	int pos = 1;
//	std::cout << "step #1" << std::endl;
	pos = d.Update(pos,changes);
	ASSERT_EQ(2,pos);
	ASSERT_EQ(2,changes.size());
	ASSERT_EQ(6,changes[2]);
	ASSERT_EQ(7,changes[4]);

	ASSERT_EQ(3,d.GetDistances().size());
	ASSERT_EQ(0,d.GetDistances()[1]);
	ASSERT_EQ(6,d.GetDistances()[2]);
	ASSERT_EQ(7,d.GetDistances()[4]);

	ASSERT_EQ(3,d.GetFromWhere().size());
	ASSERT_EQ(1,d.GetFromWhere()[1]);
	ASSERT_EQ(1,d.GetFromWhere()[2]);
	ASSERT_EQ(1,d.GetFromWhere()[4]);

	changes.clear();
//	std::cout << "step #2" << std::endl;
	pos = d.Update(pos,changes);
	ASSERT_EQ(-1,pos);
	ASSERT_EQ(1,changes.size());
	ASSERT_EQ(0,changes[2]);

	ASSERT_EQ(4,d.GetDistances().size());
	ASSERT_EQ(0,d.GetDistances()[1]);
	ASSERT_EQ(6,d.GetDistances()[2]);
	ASSERT_EQ(11,d.GetDistances()[3]);
	ASSERT_EQ(7,d.GetDistances()[4]);

	ASSERT_EQ(4,d.GetFromWhere().size());
	ASSERT_EQ(1,d.GetFromWhere()[1]);
	ASSERT_EQ(1,d.GetFromWhere()[2]);
	ASSERT_EQ(2,d.GetFromWhere()[3]);
	ASSERT_EQ(1,d.GetFromWhere()[4]);

	ASSERT_EQ(6,d.GetDistanceTo(2));

	std::vector<int> route;
	d.GetRouteTo(2,route);

	ASSERT_EQ(2,route.size());
	ASSERT_EQ(1,route[1]);
	ASSERT_EQ(2,route[0]);

}