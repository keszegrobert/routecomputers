
TEST_F(SampleGraph,bellmanford_relax)
{
	BellmanFord d;
	d.SetGraph(&g);
	
	std::map<int,int> changes;

	d.GetFromWhere()[0] = 0;
	d.GetDistances()[0] = 0;

//	std::cout << "step #1" << std::endl;
	ASSERT_TRUE(d.Relax(changes));

	ASSERT_EQ(8,changes.size());
	ASSERT_EQ(2,changes[1]);
	ASSERT_EQ(3,changes[2]);
	ASSERT_EQ(6,changes[3]);
	ASSERT_EQ(4,changes[4]);
	ASSERT_EQ(12,changes[5]);
	ASSERT_EQ(9,changes[6]);
	ASSERT_EQ(11,changes[7]);
	ASSERT_EQ(14,changes[8]);

	ASSERT_EQ(9,d.GetFromWhere().size());
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
	ASSERT_EQ(2,d.GetFromWhere()[6]);
	ASSERT_EQ(4,d.GetFromWhere()[7]);
	ASSERT_EQ(5,d.GetFromWhere()[8]);

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
	ASSERT_EQ(6,d.GetDistances()[3]);
	ASSERT_EQ(4,d.GetDistances()[4]);

	changes.clear();
//	std::cout << "step #2" << std::endl;
	ASSERT_TRUE(d.Relax(changes));
	ASSERT_EQ(3,changes.size());
	ASSERT_EQ(11,changes[5]);
	ASSERT_EQ(10,changes[7]);
	ASSERT_EQ(13,changes[8]);

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
	ASSERT_EQ(10,d.GetDistances()[7]);
	ASSERT_EQ(13,d.GetDistances()[8]);

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
	ASSERT_EQ(2,d.GetFromWhere()[6]);
	ASSERT_EQ(3,d.GetFromWhere()[7]);
	ASSERT_EQ(5,d.GetFromWhere()[8]);

	changes.clear();

//	std::cout << "step #3" << std::endl;

	ASSERT_TRUE(d.Relax(changes));
	ASSERT_EQ(1,changes.size());
	ASSERT_EQ(12,changes[8]);
	
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
	ASSERT_EQ(10,d.GetDistances()[7]);
	ASSERT_EQ(12,d.GetDistances()[8]);


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
	ASSERT_EQ(2,d.GetFromWhere()[6]);
	ASSERT_EQ(3,d.GetFromWhere()[7]);
	ASSERT_EQ(5,d.GetFromWhere()[8]);


	changes.clear();

//	std::cout << "step #4" << std::endl;

	ASSERT_FALSE(d.Relax(changes));
	ASSERT_EQ(0,changes.size());
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
	ASSERT_EQ(10,d.GetDistances()[7]);
	ASSERT_EQ(12,d.GetDistances()[8]);

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
	ASSERT_EQ(2,d.GetFromWhere()[6]);
	ASSERT_EQ(3,d.GetFromWhere()[7]);
	ASSERT_EQ(5,d.GetFromWhere()[8]);

	changes.clear();
	ASSERT_TRUE(d.IsValid());
}

TEST_F(SampleGraph,bellmanford_compute)
{
	BellmanFord d;
	d.SetGraph(&g);
	d.SetStart(0);
	d.Compute();

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
	ASSERT_EQ(2,d.GetFromWhere()[6]);
	ASSERT_EQ(3,d.GetFromWhere()[7]);
	ASSERT_EQ(5,d.GetFromWhere()[8]);

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

TEST_F(SampleWithNegativeWeights,bellmanford_relax_negative)
{
	Graph g;

	g.SetDistance(1,2,6);
	g.SetDistance(1,4,7);

	g.SetDistance(2,3,5);
	g.SetDistance(2,4,8);
	g.SetDistance(2,5,-4);

	g.SetDistance(3,2,-2);

	g.SetDistance(4,3,-3);
	g.SetDistance(4,5,9);

	g.SetDistance(5,1,2);
	g.SetDistance(5,3,7);

	BellmanFord d;
	d.SetGraph(&g);
	
	std::map<int,int> changes;

	d.GetFromWhere()[1] = 1;
	d.GetDistances()[1] = 0;

//	std::cout << "step #1" << std::endl;
	ASSERT_TRUE(d.Relax(changes));
	ASSERT_EQ(4,changes.size());
	ASSERT_EQ(6,changes[2]);
	ASSERT_EQ(4,changes[3]);
	ASSERT_EQ(7,changes[4]);
	ASSERT_EQ(2,changes[5]);

	ASSERT_EQ(5,d.GetDistances().size());
	ASSERT_EQ(0,d.GetDistances()[1]);
	ASSERT_EQ(6,d.GetDistances()[2]);
	ASSERT_EQ(4,d.GetDistances()[3]);
	ASSERT_EQ(7,d.GetDistances()[4]);
	ASSERT_EQ(2,d.GetDistances()[5]);

	ASSERT_EQ(5,d.GetFromWhere().size());
	ASSERT_EQ(1,d.GetFromWhere()[1]);
	ASSERT_EQ(1,d.GetFromWhere()[2]);
	ASSERT_EQ(4,d.GetFromWhere()[3]);
	ASSERT_EQ(1,d.GetFromWhere()[4]);
	ASSERT_EQ(2,d.GetFromWhere()[5]);

	changes.clear();
//	std::cout << "step #2" << std::endl;
	ASSERT_TRUE(d.Relax(changes));
	ASSERT_EQ(1,changes.size());
	ASSERT_EQ(2,changes[2]);

	ASSERT_EQ(5,d.GetDistances().size());
	ASSERT_EQ(0,d.GetDistances()[1]);
	ASSERT_EQ(2,d.GetDistances()[2]);
	ASSERT_EQ(4,d.GetDistances()[3]);
	ASSERT_EQ(7,d.GetDistances()[4]);
	ASSERT_EQ(2,d.GetDistances()[5]);

	ASSERT_EQ(5,d.GetFromWhere().size());
	ASSERT_EQ(1,d.GetFromWhere()[1]);
	ASSERT_EQ(3,d.GetFromWhere()[2]);
	ASSERT_EQ(4,d.GetFromWhere()[3]);
	ASSERT_EQ(1,d.GetFromWhere()[4]);
	ASSERT_EQ(2,d.GetFromWhere()[5]);

	changes.clear();
//	std::cout << "step #3" << std::endl;
	ASSERT_TRUE(d.Relax(changes));
	ASSERT_EQ(1,changes.size());
	ASSERT_EQ(-2,changes[5]);

	ASSERT_EQ(5,d.GetDistances().size());
	ASSERT_EQ(0,d.GetDistances()[1]);
	ASSERT_EQ(2,d.GetDistances()[2]);
	ASSERT_EQ(4,d.GetDistances()[3]);
	ASSERT_EQ(7,d.GetDistances()[4]);
	ASSERT_EQ(-2,d.GetDistances()[5]);

	ASSERT_EQ(5,d.GetFromWhere().size());
	ASSERT_EQ(1,d.GetFromWhere()[1]);
	ASSERT_EQ(3,d.GetFromWhere()[2]);
	ASSERT_EQ(4,d.GetFromWhere()[3]);
	ASSERT_EQ(1,d.GetFromWhere()[4]);
	ASSERT_EQ(2,d.GetFromWhere()[5]);
	
	changes.clear();
//	std::cout << "step #4" << std::endl;
	ASSERT_FALSE(d.Relax(changes));
	ASSERT_EQ(0,changes.size());

	ASSERT_EQ(5,d.GetDistances().size());
	ASSERT_EQ(0,d.GetDistances()[1]);
	ASSERT_EQ(2,d.GetDistances()[2]);
	ASSERT_EQ(4,d.GetDistances()[3]);
	ASSERT_EQ(7,d.GetDistances()[4]);
	ASSERT_EQ(-2,d.GetDistances()[5]);

	ASSERT_EQ(5,d.GetFromWhere().size());
	ASSERT_EQ(1,d.GetFromWhere()[1]);
	ASSERT_EQ(3,d.GetFromWhere()[2]);
	ASSERT_EQ(4,d.GetFromWhere()[3]);
	ASSERT_EQ(1,d.GetFromWhere()[4]);
	ASSERT_EQ(2,d.GetFromWhere()[5]);

	ASSERT_TRUE(d.IsValid());

	ASSERT_EQ(2,d.GetDistanceTo(2));

	std::vector<int> route;
	d.GetRouteTo(2,route);

	ASSERT_EQ(4,route.size());
	ASSERT_EQ(1,route[3]);
	ASSERT_EQ(4,route[2]);
	ASSERT_EQ(3,route[1]);
	ASSERT_EQ(2,route[0]);

}