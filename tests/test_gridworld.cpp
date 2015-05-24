
TEST_F(GridSample, dijkstra)
{	

	Dijkstra rc;
	rc.SetGraph(&g);

	for (int i=0; i<HEIGHT*WIDTH; ++i)
	{
		rc.SetStart(i);
		rc.Compute();
		for (int j=0; j<HEIGHT*WIDTH; ++j)
		{
			int sor1 = i/HEIGHT;
			int sor2 = j/WIDTH;
			int sorok = (sor1>sor2?sor1-sor2:sor2-sor1);
			int oszlop1 = i%HEIGHT;
			int oszlop2 = j%WIDTH;
			int oszlopok = (oszlop1>oszlop2?oszlop1-oszlop2:oszlop2-oszlop1);
			int tavolsag = sorok + oszlopok;
//			std::cout << "i:"<<i<<",j:"<<j<<",tavolsag:"<<tavolsag<<std::endl;
//			SCOPED_TRACE(testing::Message() << "Computing route from "<<i<<" to "<<j<<std::endl);
			ASSERT_EQ(tavolsag,rc.GetDistanceTo(j));
//			std::vector<int> route;
//			rc.GetRouteTo(j,route);
//			EXPECT_EQ(tavolsag,route.size()-1);
		}
	}
}

TEST_F(GridSample, quickdijkstra)
{	

	QuickDijkstra rc;
	rc.SetGraph(&g);

	for (int i=0; i<HEIGHT*WIDTH; ++i)
	{
		rc.SetStart(i);
		rc.Compute();
		for (int j=0; j<HEIGHT*WIDTH; ++j)
		{
			int sor1 = i/HEIGHT;
			int sor2 = j/WIDTH;
			int sorok = (sor1>sor2?sor1-sor2:sor2-sor1);
			int oszlop1 = i%HEIGHT;
			int oszlop2 = j%WIDTH;
			int oszlopok = (oszlop1>oszlop2?oszlop1-oszlop2:oszlop2-oszlop1);
			int tavolsag = sorok + oszlopok;
//			std::cout << "i:"<<i<<",j:"<<j<<",tavolsag:"<<tavolsag<<std::endl;
//			SCOPED_TRACE(testing::Message() << "Computing route from "<<i<<" to "<<j<<std::endl);
			ASSERT_EQ(tavolsag,rc.GetDistanceTo(j));
//			std::vector<int> route;
//			rc.GetRouteTo(j,route);
//			EXPECT_EQ(tavolsag,route.size()-1);
		}
	}
}

TEST_F(GridSample, floyd_warshall)
{
	FloydWarshall rc;
	rc.SetGraph(&g);
	rc.Compute();

	for (int i=0; i<HEIGHT*WIDTH; ++i)
	{
		rc.SetStart(i);
		for (int j=0; j<HEIGHT*WIDTH; ++j)
		{
			int sor1 = i/HEIGHT;
			int sor2 = j/WIDTH;
			int sorok = (sor1>sor2?sor1-sor2:sor2-sor1);
			int oszlop1 = i%HEIGHT;
			int oszlop2 = j%WIDTH;
			int oszlopok = (oszlop1>oszlop2?oszlop1-oszlop2:oszlop2-oszlop1);
			int tavolsag = sorok + oszlopok;
//			std::cout << "i:"<<i<<",j:"<<j<<",tavolsag:"<<tavolsag<<std::endl;
//			SCOPED_TRACE(testing::Message() << "Computing route from "<<i<<" to "<<j<<std::endl);
			ASSERT_EQ(tavolsag,rc.GetDistanceTo(j));
//			std::vector<int> route;
//			rc.GetRouteTo(j,route);
//			EXPECT_EQ(tavolsag,route.size()-1);
		}
	}
}

TEST_F(GridSample, dijkstra_with_fibonacciheap)
{	

	FibonacciDijkstra rc;
	rc.SetGraph(&g);

	for (int i=0; i<HEIGHT*WIDTH; ++i)
	{
		rc.SetStart(i);
		rc.Compute();
		for (int j=0; j<HEIGHT*WIDTH; ++j)
		{
			int sor1 = i/HEIGHT;
			int sor2 = j/WIDTH;
			int sorok = (sor1>sor2?sor1-sor2:sor2-sor1);
			int oszlop1 = i%HEIGHT;
			int oszlop2 = j%WIDTH;
			int oszlopok = (oszlop1>oszlop2?oszlop1-oszlop2:oszlop2-oszlop1);
			int tavolsag = sorok + oszlopok;
//			std::cout << "i:"<<i<<",j:"<<j<<",tavolsag:"<<tavolsag<<std::endl;
//			SCOPED_TRACE(testing::Message() << "Computing route from "<<i<<" to "<<j<<std::endl);
			ASSERT_EQ(tavolsag,rc.GetDistanceTo(j));
//			std::vector<int> route;
//			rc.GetRouteTo(j,route);
//			EXPECT_EQ(tavolsag,route.size()-1);
		}
	}
}

TEST_F(GridSample, bellmanford)
{	
	BellmanFord rc;
	rc.SetGraph(&g);

	for (int i=0; i<HEIGHT*WIDTH; ++i)
	{
		rc.SetStart(i);
		rc.Compute();
		for (int j=0; j<HEIGHT*WIDTH; ++j)
		{
			int sor1 = i/HEIGHT;
			int sor2 = j/WIDTH;
			int sorok = (sor1>sor2?sor1-sor2:sor2-sor1);
			int oszlop1 = i%HEIGHT;
			int oszlop2 = j%WIDTH;
			int oszlopok = (oszlop1>oszlop2?oszlop1-oszlop2:oszlop2-oszlop1);
			int tavolsag = sorok + oszlopok;
//			std::cout << "i:"<<i<<",j:"<<j<<",tavolsag:"<<tavolsag<<std::endl;
//			SCOPED_TRACE(testing::Message() << "Computing route from "<<i<<" to "<<j<<std::endl);
			ASSERT_EQ(tavolsag,rc.GetDistanceTo(j));
//			std::vector<int> route;
//			rc.GetRouteTo(j,route);
//			EXPECT_EQ(tavolsag,route.size()-1);
		}
	}
}
