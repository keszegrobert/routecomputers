#include <boost/heap/fibonacci_heap.hpp>

struct Data
{
    int mIndex;
    int mPriority;
    Data(int index,int priority)
      : mIndex(index),mPriority(priority)
    { }
};

struct compare_node
{
    bool operator()(const Data& n1, const Data& n2) const
    {
        return n1.mPriority > n2.mPriority;
    }
};

typedef boost::heap::compare<compare_node> comparetype;
typedef boost::heap::fibonacci_heap<Data, comparetype > heaptype;
typedef boost::heap::fibonacci_heap<Data, comparetype >::handle_type handle_type;


class FibonacciHeap{
  std::map<int,int>	mapData;
  std::map<int,handle_type> mapHandles;
  heaptype mHeap;

public:
	FibonacciHeap(){
	}

	~FibonacciHeap()
	{
	}

	int GetUniqueCount(){ return mapData.size();}
	int GetCount(){return mHeap.size();}

	virtual void Update(int aIndex,int aPriority){
      mapData[aIndex] = aPriority;
      std::map<int,handle_type>::iterator foundIt = mapHandles.find(aIndex);
      if (foundIt == mapHandles.end())
      {
		handle_type h = mHeap.push(Data(aIndex,aPriority));
		mapHandles[aIndex] = h;
	  }
	  else
	  {
	  	mHeap.update(foundIt->second,Data(aIndex,aPriority));
	  }
	}

	virtual int GetTop(){
		if (mHeap.size() == 0)
			return -1;
		return mHeap.top().mIndex;
	}

	virtual void Pop(){
		if (mHeap.size() == 0)
			return;
		int index = GetTop();
		mapData.erase(index);
		mHeap.pop();
	}

	virtual void Clear(){
		mHeap.clear();
	}	

	virtual void Print(std::ostream& out)
	{
		out << "[";
		out << "]" << std::endl;
	}
};