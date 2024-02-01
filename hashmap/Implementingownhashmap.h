#include<bits/stdc++.h>
using namespace std;
template<typename V> 
class MapNode
{
    public:
        string key;
        V value;
        MapNode * next;

        MapNode(string key, V value){
            this->key=key;
            this->value=value;
        }
        ~MapNode(){
            delete next;
        }
};
template<typename V>
class ourMap
{
    public:
    int count;
    int numBuckets;
    MapNode<V>** bucket= new MapNode<V>*[numBuckets];
    ourMap()
    {
        count=0;
        numBuckets=5;
        for(int i=0;i<numBuckets;i++)
            {
                bucket[i]=NULL;
            }
    }
    ~ourMap() // destructor for whole map
    {
        for(int i=0;i<numBuckets;i++)
        {
            delete bucket[i];
        }
        delete []bucket;
    }

    int size()
    {
        return count;
    }

    private :
    int getBucketIndex(string key)
    {
        int currentcoeff=1;
        int hashcode=0;
        for(int i=key.length()-1;i>=0;i--)
        {
            //abc= a*(p^2)+b*(p^1)+c*(p^0)
            hashcode=hashcode+key[i]*currentcoeff;
            hashcode=hashcode%numBuckets;//ye hmne isliye kiya taaki hm h hashcode ki value zyada na bdne de or range mei laye
            currentcoeff=currentcoeff*37;
            currentcoeff=currentcoeff%numBuckets;
        }
        return hashcode%numBuckets;//ye line meri compression function ki tarah kaam kr rahi h
    }
    void rehash()
    {
        MapNode<V>**temp=bucket;
        bucket= new MapNode<V>*[2*numBuckets];
        for(int i=0;i<numBuckets*2;i++)
        {
            bucket[i]=NULL;
        }
        int oldnumBuckets=numBuckets;
        numBuckets=2*oldnumBuckets;
        count=0;
        for(int i=0;i<oldnumBuckets;i++)
        {
            MapNode<V>*head= temp[i];
            while(head!=NULL)
            {
                string key= head->key;
                V value=head->value;
                insert(key,value);
              //  count++; inset ke andr count++ h hi to yaha daalne ki zrurat nahi
                head=head->next;
            }
        }
        for(int i=0;i<oldnumBuckets;i++)
        {
            MapNode<V>*head= temp[i];
            delete head;
        }
        delete [] temp;
    }
    public :
    double getLoadFactor()
    {
        return (1.0*count)/numBuckets;
    }
    void insert(string key, V value)
    {
        //insert krne ke liye mujhe cahiye hoga ek hash function or ek compression function
        //mer hash function mei hashcode return hoyega or is hashcode ki hme hr time zrurat pdegi jab hme us key ya uski value chahiye ho
        //to mei ek hashcode wala function bna deta hu getBucketindex ka naam se
        int bucketIndex= getBucketIndex(key);
        MapNode<V> *head= bucket[bucketIndex];
        while(head!=NULL)
        {
            if(head->key==key)//ye to mera tab hoga na jab meri key already exist krti hogi
            {
                head->value=value;
                return;
            }
            head=head->next;
        }
        //lets says your head iterated all over the loop and was not able to find the key
        // that means ki you need to insert the key and its corresponding value 
        head= bucket[bucketIndex];
        MapNode<V>* newNode= new MapNode<V>(key,value);
        newNode->next=head;
        bucket[bucketIndex]=newNode;
        count++;
        double loadFactor= (1.0*count)/numBuckets;
        if(loadFactor>0.7)
        {
            rehash();
        }
    }
    V getvalue(string key)
    {
        int bucketIndex= getBucketIndex(key);
        MapNode<V>*head=bucket[bucketIndex];
        while(head!=NULL)
        {
            if(head->key==key)
            {
               // cout<<head->value;
                return head->value;
            }
            head=head->next;
        }
        
        return 0;
    }
    V  remove( string key)
    {
        int bucketIndex= getBucketIndex(key);
        MapNode<V>*head= bucket[bucketIndex];
        MapNode<V>*prev=NULL;
        while(head!=NULL)
        {
            if(head->key==key)
            {
                if(prev==NULL)
                {
                    bucket[bucketIndex]=head->next;
                }else{
                prev->next=head->next;
                }
                V value= head->value;
                head->next=NULL;//yaha pe mei head->next mei NULL isliye daal raha hu kyunki agar mei iske bina head wali node delete krunga to wo apne aage wali saari node ko bhi delete krdega  kyunki hmara destructor recursive h
                delete head;
                count--;
                return value;
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }
};