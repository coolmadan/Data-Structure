#include<bits/stdc++.h>
using namespace std;
void print(int **edges,int n,int sv,bool *visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        
        if(edges[sv][i]==1)
        {
            if(visited[i])
            continue;
        print(edges,n,i,visited);
        }
    }
}
int main()
{
    //taking input for number of vertices and number of edges
    int n,e;
    cin>>n>>e;
    int **edges= new int*[n];//dynamically creating a 2D array
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;//initialising every position by 0
        }
    }
    //Now take input for edges like which edge is connected to which edge 
    
    for(int i=0;i<e;i++)
    {
        int s,v;
        cin>>s>>v;
        edges[s][v]=1;
        edges[v][s]=1;
    }
    //Now what we are doing is creating an visited array and initialising it with 0 
    //we created this array because we dont need to call again and again on the same vertex i.e. to remember which has been already printed 
    bool *visited= new bool[n];
    for(int i=0;i<n;i++)
    visited[i]=false;
    print(edges,n,0,visited);
    delete []visited;
    for(int i=0;i<n;i++)
    delete[]edges[i];
    delete []edges;
}