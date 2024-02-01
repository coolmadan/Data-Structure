#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void insert(int element)
{//min heap
    vector<int>pq;
   // if(pq.size()==0)
    pq.push_back(element);
    int childind=pq.size()-1;
    int parentind=(childind-1)/2;
    while(childind>0)
    {
        if(pq.at(childind)<pq.at(parentind))
        swap(pq[parentind],pq[childind]);
        else
        break;
        childind=parentind;
        parentind=(childind-1)/2;
    }
}
void deleteElem(int element)
{
    insert(element);
    int newind=pq.size()-1;
    

}

int main()
{

}