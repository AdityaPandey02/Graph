#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addedge(vector<vector<int>>& adj ,int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void bfs(vector<vector<int>>& adj, int v, vector<bool>& visited)
{
    queue<int> q;

    visited[v]=true;
    q.push(v);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";

        for(int x : adj[curr])
        {
            if(!visited[x])
            {
                visited[x]=true;
                q.push(x);
            }
        }

    }
    
}

void allvisited(vector<vector<int>>& adj, int x,vector<bool>& visited)
{
    bfs(adj,x,visited);

    for(int i=0;i<adj.size();i++)
    {
        if(!visited[i])
        {
            bfs(adj,i,visited);
        }
    }
}

int main()
{
    int x = 7;

    vector<vector<int>>adj(x);
    vector<bool> visited(adj.size(), false); 

    addedge(adj,0,1);

    addedge(adj,1,3);
    addedge(adj,1,4);
    addedge(adj,2,3);
    addedge(adj,2,4);
    addedge(adj,5,6);
    
    allvisited(adj,0,visited);
    return 0;
}