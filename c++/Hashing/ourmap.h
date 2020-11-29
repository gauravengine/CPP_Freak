#include <bits/stdc++.h>
using namespace std;

template <typename V>
class MapNode
{
    string key;
    V value;
    MapNode *next;
    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    MapNode<V> **bucket;
    int count;
    int numBuckets;

    ourmap()
    {
        count = 0;
        numBuckets = 5;
        bucket = new MapNode<V>*[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            bucket[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete bucket[i];
        }
        delete [] bucket;
    }
    int size(){
        return count;
    }

    V getvalue(string key){
        
    }
    private:
    int getBucketIndex(string key){
        int hashCode=0;
        int currentCoeff= 1;
        for(int i=key.length()-1;i>=0;i--){
            hashCode += (key[i] * currentCoeff)%numBuckets;
            currentCoeff *= 43;
            currentCoeff %= numBuckets;
        }

        return hashCode%numBuckets;
    }
    public:

    void insert(string key ,V value){
        int bucketIndex= getBucketIndex(key);
        MapNode<V>* head= bucket[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                
            }
            else
                head= head->next;
        } 
        // if not found that key
        if(head == NULL){
            MapNode<V> * temp = new MapNode<V> ( key,value);
            temp->next = bucket[bucketIndex];
            bucket[bucketIndex]= temp;
            count++;
        }

    }

    V remove(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> * head= bucket[bucketIndex];
        MapNode<V> *prev =NULL;
        while(head!=NULL){
            if(head->key== key){
                if(prev !=NULL){
                    prev->next = head->next;
                }
                else{
                    bucket[bucketIndex]= head->next;
                    
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            else{
                prev= head;
                head = head->next;
            }
        } 

        return 0; // signifies value not found
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V> * head= bucket[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head= head-> next;
        }

        return 0; // when not found
    }
};