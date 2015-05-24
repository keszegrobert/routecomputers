class SampleGraph : public ::testing::Test
{
public:
	Graph g;
	void SetUp()
	{

		g.SetDistance(0,1,2);
		g.SetDistance(0,3,9);
		g.SetDistance(0,4,6);

		g.SetDistance(1,2,1);
		g.SetDistance(1,4,3);

		g.SetDistance(2,4,1);
		g.SetDistance(2,6,6);

		g.SetDistance(3,7,4);

		g.SetDistance(4,3,2);
		g.SetDistance(4,7,7);
		g.SetDistance(4,5,9);

		g.SetDistance(5,6,5);
		g.SetDistance(5,8,1);

		g.SetDistance(6,8,5);

		g.SetDistance(7,5,1);
		g.SetDistance(7,8,5);

	}
};
