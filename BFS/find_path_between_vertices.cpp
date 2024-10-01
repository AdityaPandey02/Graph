#include <iostream>
#include<vector>
#include<queue>

using namespace std;

void addEdge(vector<vector<int>>& adj, int u,int v)
{
    adj[u].push_back(v);
}

bool findPath(vector<vector<int>> adj, int x, int y)
{
    if(x==y)
        true;
    
    vector<bool> visited(adj.size(),false);

    queue<int> q;
    q.push(x);
    visited[x]=true;

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();

        for(auto z: adj[curr])
        {
            if(z==y)
                return true;
            else if(!visited[z])
            {
                visited[z]=true;
                q.push(z);
            }
            
        }
    }
    return false;
}

int main()
{
    int v=5;

    vector<vector<int>> edge = {{0,1},{1,2},{2,3},{0,2},{1,3}};
    vector<vector<int>> adj(v);

    for(auto x: edge)
    {
        addEdge(adj,x[0],x[1]);
    }
    findPath(adj,0,3)?cout<<"Path Available":cout<<"Path nor possible";
    return 0;
}