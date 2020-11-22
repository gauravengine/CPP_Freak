#include<vector>
using namespace std;
class PriorityQueue
{
private:
    vector<int> pq;
public:
    PriorityQueue();
    ~PriorityQueue();
    bool isempty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(!isempty())
        {
            return pq[0];
        }
        else return 0;

    }

    void insert(int element){
        pq.push_back(element);
        int childIndex= pq.size()-1;
        int parentIndex= (childIndex-1) /2;
        while(childIndex > 0 && pq[childIndex] < pq[parentIndex]){  //min heap
            // swap
            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex]= temp;
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
            
        }

    }

    int removeMin(){
        // todo if pq is empty
        if(pq.size()>0){
            int lastIndex = pq.size() - 1;
            int elementRemoved = pq[0];
            pq[0] = pq[lastIndex];
            pq.pop_back();
            int parentIndex = 0; // initial element index
            int lci = 2 * parentIndex + 1;
            int rci = 2 * parentIndex + 2; // right child index
            int minIndex;
            while (lci < pq.size() && rci < pq.size())
            {
                if (pq[parentIndex] > pq[lci] && pq[parentIndex] > pq[rci])
                {
                    if (pq[lci] < pq[rci])
                    {
                        minIndex = lci;
                        // swap minIndex and ParentIndex
                        int temp = pq[parentIndex];
                        pq[parentIndex] = pq[minIndex];
                        pq[minIndex] = temp;
                    }
                    else
                    {
                        minIndex = rci;
                        int temp = pq[parentIndex];
                        pq[parentIndex] = pq[minIndex];
                        pq[minIndex] = temp;
                    }
                }
                else if (pq[parentIndex] > pq[lci])
                {
                    minIndex = lci;
                    // swap minIndex and ParentIndex
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[minIndex];
                    pq[minIndex] = temp;
                }
                else if (pq[parentIndex] > pq[rci])
                {
                    minIndex = rci;
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[minIndex];
                    pq[minIndex] = temp;
                }
                else
                {
                    break; // break from while loop;
                }
                parentIndex = minIndex;
                lci = (2 * parentIndex) + 1;
                rci = (2 * parentIndex) + 2;
            }
            if (lci < pq.size() && pq[parentIndex] > pq[lci])
            {
                minIndex = lci;
                // swap minIndex and ParentIndex
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[minIndex];
                pq[minIndex] = temp;
            }
            
            return elementRemoved;
        }
        else return -1;
    }
};

PriorityQueue::PriorityQueue()
{
}

PriorityQueue::~PriorityQueue()
{
}
