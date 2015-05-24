class SampleGraphFloydWarshall : public ::testing::Test
{
public:
	Graph g;
	void SetUp()
	{
/*
		g.SetDistance(1,5,-1);

		g.SetDistance(2,1,1);
		g.SetDistance(2,4,2);

		g.SetDistance(3,2,2);
		g.SetDistance(3,6,-8);

		g.SetDistance(4,1,-4);
		g.SetDistance(4,5,3);

		g.SetDistance(5,2,7);

		g.SetDistance(6,2,5);
		g.SetDistance(6,3,10);
*/
		g.SetDistance(1,2,3);
		g.SetDistance(1,3,8);
		g.SetDistance(1,5,-4);

		g.SetDistance(2,4,1);
		g.SetDistance(2,5,7);

		g.SetDistance(3,2,4);

		g.SetDistance(4,1,2);
		g.SetDistance(4,3,-5);

		g.SetDistance(5,4,6);
	}
};
