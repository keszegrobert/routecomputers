class SampleWithNegativeWeights : public ::testing::Test
{
public:
	Graph g;
	void SetUp(){

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

	}
};
