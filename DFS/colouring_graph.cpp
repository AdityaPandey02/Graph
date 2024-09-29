#include <iostream>
#include <vector>

#define V 4

using namespace std;


void addEdge(vector<vector<int>>& adj,vector<vector<int>>& edge)
{
    for(int i=0;i<edge.size();i++)
    {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
}

bool isSafe(vector<int> &adjList,int colour[],int c)
{
    for(int x: adjList)
        if(c==colour[x])
            return false;

    return true;
}

bool graphcolour(vector<vector<int>>& adj,int m , int colour[], int v)
{
    if(v==V)
    {
        return true;
    }
    for(int c=1;c<=m;c++)
    {
        if(isSafe(adj[v],colour,c))
        {
            colour[v]=c;

            if(graphcolour(adj,m,colour,v+1))
                return true;
            
            colour[v]=0;
        }
    }

    return false;
}


void printSolution(int color[])
{
    cout << "Solution Exists:"
         << " Following are the assigned colors"
         << "\n";
    for (int i = 0; i < V; i++)
        cout << " " << color[i] << " ";

    cout << "\n";
}

int main()
{

    vector<vector<int>> adj(V);
    vector<vector<int>> edge; 
    edge={{0,1},{0,2},{0,3},{1,0},{1,2},{2,0},{2,1},{2,3},{3,0},{3,2}};

    addEdge(adj,edge);

    int m = 3;

    int colour[V];
    for(int i=0;i<V;i++)
    {
        colour[i]=0;
    }

    if(graphcolour(adj,m,colour,0)==false)
    {
        cout<<"No soloution";
        return 0;
    }

    printSolution(colour);


}