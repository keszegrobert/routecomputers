class QuickDijkstra: public Dijkstra
{

public:

	virtual bool Compute()
	{
		if (mGraph == NULL)
			return false;

		mFromWhere.clear();
		mDistances.clear();

		mFromWhere[mStart] = mStart;
		mDistances[mStart] = 0;

		std::queue<int> q;
		q.push(mStart);
		while (!q.empty())
		{
			int index = q.front();
			q.pop();
			std::map<int,int> changes;
			if (Update(index,changes) == -1)
			{
				std::cout << "Update of " <<index << "FAILED" <<std::endl;
				return false;
			}
			std::map<int,int>::iterator it;
			for (it = changes.begin(); it !=changes.end(); ++it)
				q.push(it->first);	
		}
		return true;
	}

};