
class Node{
	std::map<int,int> mAdjacent;
public:
	int GetDistance(int goal){
		std::map<int,int>::iterator foundIt = mAdjacent.find(goal);
		if (foundIt == mAdjacent.end())
			return -1;
		return foundIt->second;
	}
	void SetDistance(int goal,int distance){
		mAdjacent[goal] = distance;
	}

	std::map<int,int>& GetAdjacent(){return mAdjacent;}
};


class Graph{
	std::map<int,Node*> mNodes;
public:
	virtual std::map<int,Node*>& GetNodes(){return mNodes;}
	virtual void SetDistance(int start, int goal, int distance)
	{
//		std::cout << "SetDistance("<<start<<","<<end<<")="<<distance<<std::endl;
		std::map<int,Node*>::iterator foundGoal = mNodes.find(goal);
		if (foundGoal == mNodes.end())
			mNodes[goal] = new Node();

		std::map<int,Node*>::iterator foundIt = mNodes.find(start);
		if (foundIt != mNodes.end())
		{
			if (foundIt->second != NULL)
			{
				foundIt->second->SetDistance(goal,distance);
				return;
			}
		}
		Node* node = new Node();
		node->SetDistance(goal,distance);
		mNodes[start] = node;
	}

	virtual int GetDistance(int start,int end)
	{
		std::map<int,Node*>::iterator foundIt = mNodes.find(start);
		if (foundIt != mNodes.end())
		{
			if (foundIt->second != NULL)
			{
				return foundIt->second->GetDistance(end);
			}
		}
		return -1;
	}

	virtual Node* GetNode(int node)
	{
		std::map<int,Node*>::iterator it = mNodes.find(node);
		if (it != mNodes.end())
			return it->second;
		return NULL;
	}

	virtual void RemoveAll(){
		std::map<int,Node*>::iterator it;
		for (it = mNodes.begin(); it != mNodes.end(); ++it)
		{
			Node* node = it->second;
			delete node;			
		}
		mNodes.clear();
	}
};