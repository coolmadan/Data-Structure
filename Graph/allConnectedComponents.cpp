#include<bits/stdc++.h>
using namespace std;

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
    
    
    delete []visited;
    for(int i=0;i<v;i++)
    {
        delete []edges[i];
    }
    delete []edges;
    return 0;
}