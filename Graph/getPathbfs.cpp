#include<bits/stdc++.h>
using namespace std;
void getPath(bool **edges,int v,bool *visited,int start,int end,vector<int>&path)
{
    if(start==end)
    {
        path.push_back(start);
        return;
    }
    visited[start]=true;
    queue<int>pendingVertices;
    unordered_map<int,int>Map;
    pendingVertices.push(start);
    while(pendingVertices.size()!=0)
    {
        int front=pendingVertices.front();
        pendingVertices.pop();
        for(int i=0;i<v;i++)
        {
            if(edges[front][i]==1)
            {
                if(visited[i])
                continue;
                pendingVertices.push(i);
                Map[i]=front;
                visited[i]=true;
                if(i==end)
                {
                    while(end!=start)
                    {
                       // cout<<end<<endl;    
                        path.push_back(end);
                        int x=Map[end];
                        end=x;
                    }
                   // cout<<end<<endl;
                    path.push_back(end);
                    return;
                }
            }
        }
        
    }
    return ;
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
    
    vector<int>path;
    getPath(edges,v,visited,start,end,path);
    for(auto it :path)
    {
        cout<<it<<" ";
    }
    delete []visited;
    for(int i=0;i<v;i++)
    {
        delete []edges[i];
    }
    delete []edges;
    return 0;
}