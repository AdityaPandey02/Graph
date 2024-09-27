#include<iostream>
#include<vector>

using namespace std;

void addedge(vector<vector<int>>& graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void findDFS(vector<vector<int>>& graph, vector<bool>& visited, int s)
{
    visited[s]=true;
    cout<<s<<" ";
    for(int x: graph[s])
    {
        if(!visited[x])
        {
            visited[x]=true;
            findDFS(graph,visited,x);
        }
    }
}

int main()
{
    int V = 5;
    vector<vector<int>> edge(5);
    addedge(edge,1,2);
    addedge(edge,1,0);
    addedge(edge,2,0);
    addedge(edge,2,3);
    addedge(edge,2,4);

    vector<bool> visited(edge.size(), false);
    findDFS(edge,visited,1);

}