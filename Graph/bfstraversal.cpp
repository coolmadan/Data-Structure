#include<iostream>
#include<queue>
using namespace std;
void print(bool **edges,int n,int sv,bool *visited)
{
    queue<int>adjacentnodes;
    adjacentnodes.push(sv);
    visited[sv]=true;
    while(adjacentnodes.size()!=0)
    {
        int front=adjacentnodes.front();
        adjacentnodes.pop();
        cout<<front<<" ";
        
        for(int i=0;i<n;i++)
        {
            if(edges[front][i]==1)
            {
                if(visited[i]==true)
                continue;
                adjacentnodes.push(i);
                visited[i]=true;
            }
        }

    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    bool **edges=new bool *[n];
    for(int i=0;i<n;i++)
    {
        edges[i]= new bool [n];
        for(int j=0;j<n;j++)
        edges[i][j]=false;
    }
    for(int i=0;i<e;i++)
    {
        int s,v;
        cin>>s>>v;
        edges[s][v]=true;
        edges[v][s]=true;
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    visited[i]=false;
    print(edges,n,0,visited);
    delete []visited;
    for(int i=0;i<n;i++)
    delete []edges[i];
    delete []edges;
}