#include<bits/stdc++.h>
using namespace std;
void isConnected(bool **edges,int v,bool *visited,int s)
{
   // bool ans=false;
    visited[s]=true;
    for(int i=0;i<v;i++)
    {
        if(edges[s][i]==1)
        {
            if(visited[i])
            continue;
            isConnected(edges,v,visited,i);
        }
        
    }
   
}
int main()
{
    int v,e;
    cin>>v>>e;
    bool ** edges= new bool *[v];
    for(int i=0;i<v;i++)
    {
        edges[i]=new bool [v];
        for(int j=0;j<v;j++)
        {
            edges[i][j]=false;
        }
    }
    for(int i=0;i<e;i++)
    {
        int s,e;
        cin>>s>>e;
        edges[s][e]=true;
        edges[e][s]=true;
    }
    
    bool *visited= new bool [v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    isConnected(edges,v,visited,0);
    bool flag=0;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
      {  cout<<"false"<<endl;
      flag=1;
      break;
      }
    }
    if(flag==0)
    cout<<"true"<<endl;
    delete []visited;
    for(int i=0;i<v;i++)
    {
        delete []edges[i];
    }
    delete []edges;
    return 0;
}