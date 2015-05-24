const int MAXINT=999999999;

class BellmanFord: public IRouteComputer{
	std::map<int,int> mDistances;
	std::map<int,int> mFromWhere;
	Graph* mGraph;
	int mStart;
public:

	BellmanFord():mGraph(NULL),mStart(-1){}
	void SetGraph(Graph* g){mGraph = g;}

	std::map<int,int>& GetFromWhere(){return mFromWhere;}
	std::map<int,int>& GetDistances(){return mDistances;}

	virtual void SetStart(int start)
	{
		mStart = start;
	}

	bool Compute(){
		if (mGraph == NULL)
			return false;

		mFromWhere.clear();
		mDistances.clear();

		mFromWhere[mStart] = mStart;
		mDistances[mStart] = 0;
		std::map<int,Node*>& nodes = mGraph->GetNodes();
		std::map<int,Node*>::iterator it;
		int count = 0;

		for (it = nodes.begin(); it != nodes.end(); ++it,++count)
		{
	//		std::cout << "Step #"<< count << std::endl;
			std::map<int,int> changes;
			if (!Relax(changes))
				break;
		}
		return IsValid();
	}

	bool Relax(std::map<int,int>& changes)
	{
		bool relaxed = false;
		
		std::map<int,Node*>& nodes = mGraph->GetNodes();
		std::map<int,Node*>::iterator it;
		for (it = nodes.begin(); it != nodes.end(); ++it)
		{	
			std::map<int,int>& adjacent = it->second->GetAdjacent();
			std::map<int,int>::iterator iit;
			for (iit = adjacent.begin(); iit != adjacent.end(); ++iit)
			{
				int u = it->first;
				int du = MAXINT;
				std::map<int,int>::iterator itdu = mDistances.find(u);
				if (itdu != mDistances.end())
					du = itdu->second;

				int v = iit->first;
				int dv = MAXINT;
				std::map<int,int>::iterator itdv = mDistances.find(v);
				if (itdv != mDistances.end())
					dv = itdv->second;

				int wuv = iit->second;
				if (dv > du + wuv)
				{
					mDistances[v] = du + wuv;
					relaxed = true;
					changes[v] = du + wuv;
					mFromWhere[v] = u;
//					std::cout << "CHANGES["<<v<<"]="<<du+wuv<<std::endl;
//					std::cout << "FROMWHERE["<<v<<"]="<<u<<std::endl;
				}
			}
		}
		return relaxed;
	}

	bool IsValid()
	{
		std::map<int,Node*>& nodes = mGraph->GetNodes();
		std::map<int,Node*>::iterator it;
		for (it = nodes.begin(); it != nodes.end(); ++it)
		{
			std::map<int,int>& adjacent = it->second->GetAdjacent();
			std::map<int,int>::iterator iit;
			for (iit = adjacent.begin(); iit != adjacent.end(); ++iit)
			{
				int u = it->first;
				int du = MAXINT;
				std::map<int,int>::iterator itdu = mDistances.find(u);
				if (itdu != mDistances.end())
					du = itdu->second;

				int v = iit->first;
				int dv = MAXINT;
				std::map<int,int>::iterator itdv = mDistances.find(v);
				if (itdv != mDistances.end())
					dv = itdv->second;

				int wuv = iit->second;
				if (dv > du + wuv)
					return false;
			}
		}
		return true;
	}

	int GetDistanceTo(int goal)
	{
		std::map<int,int>::iterator foundIt = mDistances.find(goal);
		if (foundIt == mDistances.end())
			return -1;
		return foundIt->second;
	}

	void GetRouteTo(int goal, std::vector<int>& road)
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