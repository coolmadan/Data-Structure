#include<bits/stdc++.h>
using namespace std;
bool hasPath(bool **edges,int v,bool *visited,int start,int end)
{
    //hasPath check krne ke liye mei ya to dfs ya bfs try kr rkta hu
    //but better ye rahega ki mei dfs use kru taaki mujhe apne adjacent nodes se pta chle ki wo connected h ke nahi
    if(edges[start][end])
    return true;
    visited[start]=true;
    for(int i=0;i<v;i++)
    {
        if(visited[i])
        continue;
        hasPath(edges,v,visited,i,end);
    }
    return false;
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
    int start,end;
    cin>>start>>end;
    bool *visited= new bool [v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    
    cout<<hasPath(edges,v,visited,start,end);
    delete []visited;
    for(int i=0;i<v;i++)
    {
        delete []edges[i];
    }
    delete []edges;
    return 0;
}