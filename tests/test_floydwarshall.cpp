TEST_F(SampleGraphFloydWarshall,floydwarshall_update)
{

	FloydWarshall d;
	d.SetGraph(&g);
	int pos = 1;

	std::vector<int> route;
	route.push_back(0);

	std::map<int,Node*>& nodes = g.GetNodes();	
	disttable changes = new int*[nodes.size()];
	for (size_t i = 0; i != nodes.size(); ++i)
	{
		changes[i] = new int[nodes.size()];
		for (size_t j = 0; j != nodes.size(); ++j)
			changes[i][j] = 0;
	}
	

	d.SetStart(1);
	ASSERT_EQ(0,d.GetDistanceTo(1));
	ASSERT_EQ(3,d.GetDistanceTo(2));
	ASSERT_EQ(8,d.GetDistanceTo(3));
	ASSERT_EQ(999999999,d.GetDistanceTo(4));
	ASSERT_EQ(-4,d.GetDistanceTo(5));

	d.SetStart(2);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(0,d.GetDistanceTo(2));
	ASSERT_EQ(999999999,d.GetDistanceTo(3));
	ASSERT_EQ(1,d.GetDistanceTo(4));
	ASSERT_EQ(7,d.GetDistanceTo(5));

	d.SetStart(3);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(4,d.GetDistanceTo(2));
	ASSERT_EQ(0,d.GetDistanceTo(3));
	ASSERT_EQ(999999999,d.GetDistanceTo(4));
	ASSERT_EQ(999999999,d.GetDistanceTo(5));

	d.SetStart(4);
	ASSERT_EQ(2,d.GetDistanceTo(1));
	ASSERT_EQ(999999999,d.GetDistanceTo(2));
	ASSERT_EQ(-5,d.GetDistanceTo(3));
	ASSERT_EQ(0,d.GetDistanceTo(4));
	ASSERT_EQ(999999999,d.GetDistanceTo(5));

	d.SetStart(5);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(999999999,d.GetDistanceTo(2));
	ASSERT_EQ(999999999,d.GetDistanceTo(3));
	ASSERT_EQ(6,d.GetDistanceTo(4));
	ASSERT_EQ(0,d.GetDistanceTo(5));

//step #1
	pos = d.Update(1,changes);
	d.ApplyChanges(changes);

	ASSERT_EQ(1,pos);
	route.push_back(pos);

	d.SetStart(1);
	ASSERT_EQ(0,d.GetDistanceTo(1));
	ASSERT_EQ(3,d.GetDistanceTo(2));
	ASSERT_EQ(8,d.GetDistanceTo(3));
	ASSERT_EQ(999999999,d.GetDistanceTo(4));
	ASSERT_EQ(-4,d.GetDistanceTo(5));

	d.SetStart(2);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(0,d.GetDistanceTo(2));
	ASSERT_EQ(999999999,d.GetDistanceTo(3));
	ASSERT_EQ(1,d.GetDistanceTo(4));
	ASSERT_EQ(7,d.GetDistanceTo(5));

	d.SetStart(3);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(4,d.GetDistanceTo(2));
	ASSERT_EQ(0,d.GetDistanceTo(3));
	ASSERT_EQ(999999999,d.GetDistanceTo(4));
	ASSERT_EQ(999999995,d.GetDistanceTo(5));

	d.SetStart(4);
	ASSERT_EQ(2,d.GetDistanceTo(1));
	ASSERT_EQ(5,d.GetDistanceTo(2));
	ASSERT_EQ(-5,d.GetDistanceTo(3));
	ASSERT_EQ(0,d.GetDistanceTo(4));
	ASSERT_EQ(-2,d.GetDistanceTo(5));

	d.SetStart(5);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(999999999,d.GetDistanceTo(2));
	ASSERT_EQ(999999999,d.GetDistanceTo(3));
	ASSERT_EQ(6,d.GetDistanceTo(4));
	ASSERT_EQ(0,d.GetDistanceTo(5));

//step #2
	pos = d.Update(2,changes);
	d.ApplyChanges(changes);
	
	ASSERT_EQ(1,pos);
	route.push_back(pos);

	d.SetStart(1);
	ASSERT_EQ(0,d.GetDistanceTo(1));
	ASSERT_EQ(3,d.GetDistanceTo(2));
	ASSERT_EQ(8,d.GetDistanceTo(3));
	ASSERT_EQ(4,d.GetDistanceTo(4));
	ASSERT_EQ(-4,d.GetDistanceTo(5));

	d.SetStart(2);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(0,d.GetDistanceTo(2));
	ASSERT_EQ(999999999,d.GetDistanceTo(3));
	ASSERT_EQ(1,d.GetDistanceTo(4));
	ASSERT_EQ(7,d.GetDistanceTo(5));

	d.SetStart(3);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(4,d.GetDistanceTo(2));
	ASSERT_EQ(0,d.GetDistanceTo(3));
	ASSERT_EQ(5,d.GetDistanceTo(4));
	ASSERT_EQ(11,d.GetDistanceTo(5));

	d.SetStart(4);
	ASSERT_EQ(2,d.GetDistanceTo(1));
	ASSERT_EQ(5,d.GetDistanceTo(2));
	ASSERT_EQ(-5,d.GetDistanceTo(3));
	ASSERT_EQ(0,d.GetDistanceTo(4));
	ASSERT_EQ(-2,d.GetDistanceTo(5));

	d.SetStart(5);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(999999999,d.GetDistanceTo(2));
	ASSERT_EQ(999999999,d.GetDistanceTo(3));
	ASSERT_EQ(6,d.GetDistanceTo(4));
	ASSERT_EQ(0,d.GetDistanceTo(5));

//step #3
	pos = d.Update(3,changes);
	d.ApplyChanges(changes);
	
	ASSERT_EQ(1,pos);
	route.push_back(pos);

	d.SetStart(1);
	ASSERT_EQ(0,d.GetDistanceTo(1));
	ASSERT_EQ(3,d.GetDistanceTo(2));
	ASSERT_EQ(8,d.GetDistanceTo(3));
	ASSERT_EQ(4,d.GetDistanceTo(4));
	ASSERT_EQ(-4,d.GetDistanceTo(5));

	d.SetStart(2);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(0,d.GetDistanceTo(2));
	ASSERT_EQ(999999999,d.GetDistanceTo(3));
	ASSERT_EQ(1,d.GetDistanceTo(4));
	ASSERT_EQ(7,d.GetDistanceTo(5));

	d.SetStart(3);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(4,d.GetDistanceTo(2));
	ASSERT_EQ(0,d.GetDistanceTo(3));
	ASSERT_EQ(5,d.GetDistanceTo(4));
	ASSERT_EQ(11,d.GetDistanceTo(5));

	d.SetStart(4);
	ASSERT_EQ(2,d.GetDistanceTo(1));
	ASSERT_EQ(-1,d.GetDistanceTo(2));
	ASSERT_EQ(-5,d.GetDistanceTo(3));
	ASSERT_EQ(0,d.GetDistanceTo(4));
	ASSERT_EQ(-2,d.GetDistanceTo(5));

	d.SetStart(5);
	ASSERT_EQ(999999999,d.GetDistanceTo(1));
	ASSERT_EQ(999999999,d.GetDistanceTo(2));
	ASSERT_EQ(999999999,d.GetDistanceTo(3));
	ASSERT_EQ(6,d.GetDistanceTo(4));
	ASSERT_EQ(0,d.GetDistanceTo(5));

//step #4
	pos = d.Update(4,changes);
	d.ApplyChanges(changes);
	
	ASSERT_EQ(1,pos);
	route.push_back(pos);

	d.SetStart(1);
	ASSERT_EQ(0,d.GetDistanceTo(1));
	ASSERT_EQ(3,d.GetDistanceTo(2));
	ASSERT_EQ(-1,d.GetDistanceTo(3));
	ASSERT_EQ(4,d.GetDistanceTo(4));
	ASSERT_EQ(-4,d.GetDistanceTo(5));

	d.SetStart(2);
	ASSERT_EQ(3,d.GetDistanceTo(1));
	ASSERT_EQ(0,d.GetDistanceTo(2));
	ASSERT_EQ(-4,d.GetDistanceTo(3));
	ASSERT_EQ(1,d.GetDistanceTo(4));
	ASSERT_EQ(-1,d.GetDistanceTo(5));

	d.SetStart(3);
	ASSERT_EQ(7,d.GetDistanceTo(1));
	ASSERT_EQ(4,d.GetDistanceTo(2));
	ASSERT_EQ(0,d.GetDistanceTo(3));
	ASSERT_EQ(5,d.GetDistanceTo(4));
	ASSERT_EQ(3,d.GetDistanceTo(5));

	d.SetStart(4);
	ASSERT_EQ(2,d.GetDistanceTo(1));
	ASSERT_EQ(-1,d.GetDistanceTo(2));
	ASSERT_EQ(-5,d.GetDistanceTo(3));
	ASSERT_EQ(0,d.GetDistanceTo(4));
	ASSERT_EQ(-2,d.GetDistanceTo(5));

	d.SetStart(5);
	ASSERT_EQ(8,d.GetDistanceTo(1));
	ASSERT_EQ(5,d.GetDistanceTo(2));
	ASSERT_EQ(1,d.GetDistanceTo(3));
	ASSERT_EQ(6,d.GetDistanceTo(4));
	ASSERT_EQ(0,d.GetDistanceTo(5));

//step #5
	pos = d.Update(5,changes);
	d.ApplyChanges(changes);
	
	ASSERT_EQ(1,pos);
	route.push_back(pos);

	d.SetStart(1);
	ASSERT_EQ(0,d.GetDistanceTo(1));
	ASSERT_EQ(1,d.GetDistanceTo(2));
	ASSERT_EQ(-3,d.GetDistanceTo(3));
	ASSERT_EQ(2,d.GetDistanceTo(4));
	ASSERT_EQ(-4,d.GetDistanceTo(5));

	d.SetStart(2);
	ASSERT_EQ(3,d.GetDistanceTo(1));
	ASSERT_EQ(0,d.GetDistanceTo(2));
	ASSERT_EQ(-4,d.GetDistanceTo(3));
	ASSERT_EQ(1,d.GetDistanceTo(4));
	ASSERT_EQ(-1,d.GetDistanceTo(5));

	d.SetStart(3);
	ASSERT_EQ(7,d.GetDistanceTo(1));
	ASSERT_EQ(4,d.GetDistanceTo(2));
	ASSERT_EQ(0,d.GetDistanceTo(3));
	ASSERT_EQ(5,d.GetDistanceTo(4));
	ASSERT_EQ(3,d.GetDistanceTo(5));

	d.SetStart(4);
	ASSERT_EQ(2,d.GetDistanceTo(1));
	ASSERT_EQ(-1,d.GetDistanceTo(2));
	ASSERT_EQ(-5,d.GetDistanceTo(3));
	ASSERT_EQ(0,d.GetDistanceTo(4));
	ASSERT_EQ(-2,d.GetDistanceTo(5));

	d.SetStart(5);
	ASSERT_EQ(8,d.GetDistanceTo(1));
	ASSERT_EQ(5,d.GetDistanceTo(2));
	ASSERT_EQ(1,d.GetDistanceTo(3));
	ASSERT_EQ(6,d.GetDistanceTo(4));
	ASSERT_EQ(0,d.GetDistanceTo(5));

	for (size_t j = 0; j<nodes.size(); ++j)
		delete[] changes[j];
	delete[] changes;

}

TEST_F(SampleGraphFloydWarshall,floydwarshall_compute)
{
	FloydWarshall d;
	d.SetGraph(&g);

	ASSERT_TRUE(d.Compute());

	d.SetStart(1);
	ASSERT_EQ(0,d.GetDistanceTo(1));
	ASSERT_EQ(1,d.GetDistanceTo(2));
	ASSERT_EQ(-3,d.GetDistanceTo(3));
	ASSERT_EQ(2,d.GetDistanceTo(4));
	ASSERT_EQ(-4,d.GetDistanceTo(5));

	d.SetStart(2);
	ASSERT_EQ(3,d.GetDistanceTo(1));
	ASSERT_EQ(0,d.GetDistanceTo(2));
	ASSERT_EQ(-4,d.GetDistanceTo(3));
	ASSERT_EQ(1,d.GetDistanceTo(4));
	ASSERT_EQ(-1,d.GetDistanceTo(5));

	d.SetStart(3);
	ASSERT_EQ(7,d.GetDistanceTo(1));
	ASSERT_EQ(4,d.GetDistanceTo(2));
	ASSERT_EQ(0,d.GetDistanceTo(3));
	ASSERT_EQ(5,d.GetDistanceTo(4));
	ASSERT_EQ(3,d.GetDistanceTo(5));

	d.SetStart(4);
	ASSERT_EQ(2,d.GetDistanceTo(1));
	ASSERT_EQ(-1,d.GetDistanceTo(2));
	ASSERT_EQ(-5,d.GetDistanceTo(3));
	ASSERT_EQ(0,d.GetDistanceTo(4));
	ASSERT_EQ(-2,d.GetDistanceTo(5));

	d.SetStart(5);
	ASSERT_EQ(8,d.GetDistanceTo(1));
	ASSERT_EQ(5,d.GetDistanceTo(2));
	ASSERT_EQ(1,d.GetDistanceTo(3));
	ASSERT_EQ(6,d.GetDistanceTo(4));
	ASSERT_EQ(0,d.GetDistanceTo(5));

/*
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
*/
}
