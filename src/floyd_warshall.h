typedef std::map<int,int> distrow;
typedef int** disttable;

class FloydWarshall: public IRouteComputer
{
private:
	int mStart;
	Graph* mGraph;
//	std::map<int,int> mFromWhere;
//	std::map<int,int> mDistances;
	std::map<int,int> mNodeMapping;
	int** mDistTable;
	size_t mNodeCount;

public:
	FloydWarshall():mStart(-1),mGraph(NULL),mDistTable(NULL),mNodeCount(0){}
	virtual ~FloydWarshall(){
		for (size_t i = 0; i < mNodeCount; ++i)
		{
			delete[] mDistTable[i];
			mDistTable[i] = NULL;
		}
		delete[] mDistTable;
	}
	virtual void SetGraph(Graph* g){
		mGraph = g;
		std::map<int,Node*>& nodes = mGraph->GetNodes();
		mNodeCount = nodes.size();
		mDistTable = new int*[mNodeCount];
		std::map<int,Node*>::iterator it;
		int i = 0;
		for (it = nodes.begin(); it != nodes.end(); ++it)
			mNodeMapping[it->first] = i++;

		for (it = nodes.begin(); it != nodes.end(); ++it)
		{
			int i = mNodeMapping[it->first];
			mDistTable[i] = new int[mNodeCount];
			std::map<int,Node*>::iterator itj;
			for (itj = nodes.begin(); itj != nodes.end(); ++itj)
			{
				int j = mNodeMapping[itj->first];
				mDistTable[i][j] = 999999999;
			}
			mDistTable[i][i] = 0;
			Node* node = it->second;
			std::map<int,int>& adjacent = node->GetAdjacent();
			std::map<int,int>::iterator it2;
			for (it2 = adjacent.begin(); it2 != adjacent.end(); ++it2)
			{
				int j = mNodeMapping[it2->first];
				mDistTable[i][j] = it2->second;
			}
		}

	}

	virtual void SetStart(int start){
		if (mNodeMapping.empty() || mNodeMapping.find(start) == mNodeMapping.end())
		{
			std::cout << "SetStart start=" <<start<< " not found" <<std::endl;
		}
		mStart = mNodeMapping[start];
	}

//	std::map<int,int>& GetFromWhere(){return mFromWhere;}
//	std::map<int,int>& GetDistances(){return mDistances;}

	int Update(int pos, disttable changes)
	{
		if (mDistTable == NULL)
		{
			std::cout << "mDistTable is NULL"<<std::endl;
			return -1;
		}
		int k = mNodeMapping[pos];

		for (size_t i = 0; i < mNodeCount; ++i)
		{
			int dik = mDistTable[i][k];
			for (size_t j = 0; j < mNodeCount; ++j)
			{
//				std::cout << "k:" << k << ", i:" << i << ", j:"<< j;
				int dij = mDistTable[i][j];
				int dkj = mDistTable[k][j];
//				std::cout << ", dij:" << dij << ", dik:" << dik << ", dkj:" << dkj << std::endl;
				changes[i][j] = std::min(dij,dik+dkj);
			}
		}

		return 1;
	}

	void ApplyChanges(disttable changes)
	{
		for (size_t i = 0; i < mNodeCount; ++i)
		{
			for (size_t j = 0; j<mNodeCount; ++j)
			{
				mDistTable[i][j] = changes[i][j];
			}
		}
	}

	virtual bool Compute()
	{
		if (mGraph == NULL)
			return false;

		std::map<int,Node*>& nodes = mGraph->GetNodes();
		for (std::map<int,Node*>::iterator i = nodes.begin(); i != nodes.end(); ++i)
		{
			disttable changes = new int*[mNodeCount];
			for (size_t j = 0; j<mNodeCount; ++j)
				changes[j] = new int[mNodeCount];

			if (Update(i->first,changes) == -1)
			{
//				std::cout << "Update of " <<i->first << "FAILED" <<std::endl;
				return false;
			}
			ApplyChanges(changes);
			for (size_t j = 0; j<mNodeCount; ++j)
				delete[] changes[j];
			delete[] changes;
		}
		return true;
	}
	virtual int GetDistanceTo(int goal)
	{
		int mGoal = mNodeMapping[goal];
		return mDistTable[mStart][mGoal];
	}

	virtual void GetRouteTo(int , std::vector<int>& )
	{
	}

};