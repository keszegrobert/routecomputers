class FibonacciDijkstra: public Dijkstra
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

		FibonacciHeap h;
		h.Update(mStart,0);
		while (h.GetCount()>0)
		{
			int index = h.GetTop();
			h.Pop();
			std::map<int,int> changes;
			if (Update(index,changes) == -1)
			{
				std::cout << "Update of " <<index << "FAILED" <<std::endl;
				return false;
			}
			std::map<int,int>::iterator it;
			for (it = changes.begin(); it !=changes.end(); ++it)
				h.Update(it->first,it->second);	
		}
		return true;
	}

};