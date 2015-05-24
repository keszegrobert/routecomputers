#include <queue>
#include <map>

struct PriorityItem{
	int index;
	int priority;
	int counter;
};

class ComparePriorityItem{
public:
	bool operator()(PriorityItem& t1, PriorityItem& t2)
    {
    	return t1.priority < t2.priority;
    }
};

class PriorityQueue{
private:
	std::priority_queue<PriorityItem, std::vector<PriorityItem>, ComparePriorityItem> 
		mPriorities;
	std::map<int,int> 
		mLastValid;


	bool IsValid(PriorityItem item){
		std::map<int,int>::iterator foundIt = mLastValid.find(item.index);
		if (foundIt == mLastValid.end())
			return false;
		return foundIt->second == item.counter;
	}

	void PopToValid(){
		if (mPriorities.size() == 0)
			return;			

		do {
			PriorityItem item = mPriorities.top();
			if (IsValid(item))
				break;
			mPriorities.pop();
		} while (!mPriorities.empty());
	}

public:
	PriorityQueue(){}

	int GetUniqueCount(){return mLastValid.size();}
	int GetCount(){return mPriorities.size();}

	virtual void Update(int aIndex,int aTime){
		static int counter = 0;
		PriorityItem t;
		t.index = aIndex;
		t.priority = aTime;
		t.counter = counter;
		mLastValid[aIndex] = counter;
		++counter;
		PopToValid();
		mPriorities.push(t);
	}

	virtual int GetTop(){
		if (mPriorities.empty())
			return -1;

		PriorityItem chosen = mPriorities.top();
		return chosen.index;
	}

	virtual void Pop(){
		if (mPriorities.size() == 0)
			return;

		int index = GetTop();
		mLastValid.erase(index);
		mPriorities.pop();
		PopToValid();
	}

	virtual void Clear(){
		mLastValid.clear();
		while (!mPriorities.empty())
		{
			mPriorities.pop();
		}
	}
};