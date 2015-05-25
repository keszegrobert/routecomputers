class Dijkstra: public IRouteComputer
{
protected:
	int mStart;
	Graph* mGraph;
	std::map<int,int> mFromWhere;
	std::map<int,int> mDistances;	

public:
	Dijkstra():mGraph(NULL),mStart(-1){}
	void SetGraph(Graph* g){mGraph = g;}

	std::map<int,int>& GetFromWhere(){return mFromWhere;}
	std::map<int,int>& GetDistances(){return mDistances;}

	int Update(int pos,	std::map<int,int>& changes)
	{
		Node* node = mGraph->GetNode(pos);
		if (node == NULL)
		{
			std::cout << "node for "<<pos<<"is NULL"<<std::endl;
			return -1;
		}
		std::map<int,int>::iterator foundDistanceIt = mDistances.find(pos);
		if (foundDistanceIt == mDistances.end())
		{
			std::cout << "distance for "<<pos<<" was not found"<<std::endl;
			return -1;
		}
		int distance = foundDistanceIt->second;
		int mindist = 999999999;
		int minpos = pos;

		std::map<int,int>& adjacent = node->GetAdjacent();
		std::map<int,int>::iterator it;
		for (it = adjacent.begin(); it != adjacent.end(); ++it)
		{
			if (it->second < 0)
				return -1;
			std::map<int,int>::iterator foundDistanceIt = mDistances.find(it->first);
			if (foundDistanceIt == mDistances.end() ||
				foundDistanceIt->second > distance + it->second)
			{
				mDistances[it->first] = distance + it->second;
				mFromWhere[it->first] = pos;
				changes[it->first] = distance + it->second;
				if (mindist > distance+it->second)
				{
					mindist = distance+it->second;
					minpos = it->first;
				}
			}
		}
		return minpos;
	}

	virtual bool Compute()
	{
		if (mGraph == NULL)
			return false;

		if (mStart < 0)
			return false;

		mFromWhere.clear();
		mDistances.clear();

		mFromWhere[mStart] = mStart;
		mDistances[mStart] = 0;

		PriorityQueue q;
		q.Update(mStart,0);
		while (q.GetCount()>0)
		{
			int index = q.GetTop();
			q.Pop();
			std::map<int,int> changes;
			if (Update(index,changes) == -1)
			{
				std::cout << "Update of " <<index << "FAILED" <<std::endl;
				return false;
			}
			std::map<int,int>::iterator it;
			for (it = changes.begin(); it !=changes.end(); ++it)
				q.Update(it->first,it->second);	
		}
		return true;
	}

	virtual void SetStart(int start)
	{
		mStart = start;
	}

	virtual int GetDistanceTo(int goal)
	{
		std::map<int,int>::iterator foundIt = mDistances.find(goal);
		if (foundIt == mDistances.end())
			return -1;
		return foundIt->second;
	}

	virtual void GetRouteTo(int goal, std::vector<int>& road)
	{
		int pos = goal;
		int prevpos = -1;
		while (pos != prevpos)
		{
			road.push_back(pos);
			prevpos = pos;
			pos=mFromWhere[pos];
		}
	}
};