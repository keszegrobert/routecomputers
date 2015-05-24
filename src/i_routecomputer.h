class IRouteComputer{
	virtual bool Compute() = 0;
	virtual void SetStart(int start)=0;
	virtual void SetGraph(Graph* g)=0;
	virtual int GetDistanceTo(int goal) = 0;
	virtual void GetRouteTo(int goal, std::vector<int>& road) = 0;

};