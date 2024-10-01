#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int find_level(vector<vector<int>>& edge,int j, int x, vector<bool>& visited)
{

    vector<vector<int>>adj(5);
    for(int i=0;i<edge.size();i++)
    {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }


    
    visited[j]=true;
    queue<int> q;
    q.push(j);
    int level=0;

     while(!q.empty())
     {
        int curr = q.front();
        q.pop();
        if(curr==x)
            return level;
        
        level++;

        for(int t: adj[curr])
        {
            if(!visited[t])
            {
                visited[t]=true;
                q.push(t);
                if(x==t)
                    return level;
            }
        }
     }

    return -1;
}

int main()
{
    int V = 5;
    vector<vector<int> > edges
        = { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 2, 4 } };
    int X = 3;
    
    vector<bool> visited(V,false);
    // Function call
    int level = find_level(edges,0,X,visited);
    cout << level << endl;
 
    return 0;
}