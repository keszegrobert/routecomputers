const int HEIGHT=10;
const int WIDTH=10;

class GridSample : public ::testing::Test
{
public:
	Graph g;
	void SetUp(){
		for (int i = 0; i < HEIGHT; ++i)
		{
			for (int j = 0; j < WIDTH; ++j)
			{				
				if (i != 0)
					g.SetDistance(i*WIDTH+j,(i-1)*WIDTH+j,1);
				if (j != 0)
					g.SetDistance(i*WIDTH+j,(i)*WIDTH+j-1,1);
				if (i != HEIGHT-1)
					g.SetDistance(i*WIDTH+j,(i+1)*WIDTH+j,1);
				if (j != WIDTH-1)
					g.SetDistance(i*WIDTH+j,(i)*WIDTH+j+1,1);
			}
		}

	}

};