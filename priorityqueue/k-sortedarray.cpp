#include<iostream>
#include<queue>
using namespace std;
void KSortedArray(int input[],int n ,int k)
{
    //creating a priority queue
    priority_queue<int>pq;
    //inserting in priority queue
    for(int i=0;i<k;i++)
    pq.push(input[i]);
    //dequeuing
    int j=0; 
    for(int i=k;i<n;i++)
    {
        input[j]=pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while(!pq.empty())
    {
        input[j]=pq.top();
        pq.pop();
        j++;
    }

}
int main()
{
    int input[]={10,12,6,7,9};
    KSortedArray(input,5,3);
    for(int i=0;i<5;i++)
    {
        cout<<input[i]<<" ";
    }
    return 0;
}