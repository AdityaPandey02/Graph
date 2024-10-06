#include<iostream>
#include<vector>

using namespace std;

bool detectCycle(vector<vector<int>>& adj, int x, vector<bool> &visited, vector<bool>& recstack)
{
    visited[x]=true;
    recstack[x]=true;

    for(auto y: adj[x])
    {
        if(!visited[y] && detectCycle(adj,y,visited,recstack))
            return true;
        else if (recstack[y])
            return true;
        
    }

    recstack[x]=false;
    return false;
}

bool isCyclic(vector<vector<int>>& adj, int V)
{
    vector<bool> visited(V,false);
    vector<bool> recstack(V,false);

    for(int i=0;i<V;i++)
    {
        if(!visited[i] && detectCycle(adj,i,visited,recstack))
            return true;
    }
    return false;
}

int main()
{
    int V=4;

    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    if(isCyclic(adj,V))
        cout<<"Cycle present";
    else
        cout<<"Cycle not present";
    return 0;
}