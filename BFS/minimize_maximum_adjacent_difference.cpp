#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool isValid(int x, int y, int n, int m) 
{
    return x >= 0 && x < n && y >= 0 && y < m;
}


bool can_reach(vector<vector<int>>& graph, int mid)
{
    int m = graph.size();
    int n = graph[0].size();

    vector<vector<bool>> visited(m,vector<bool>(n, false));
    queue<pair<int,int>> q;

    q.push({0,0});
    visited[0][0] = true;

    while(!q.empty())
    {
        auto [x, y]= q.front();
        q.pop();

        if (x == m - 1 && y == n - 1) 
            return true;

        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(isValid(nx,ny,m,n) && !visited[nx][ny] && abs(graph[nx][ny] - graph[x][y]) <= mid)
            {
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }

    }
    return false;

}

int minimise_max_diff(vector<vector<int>>& graph)
{
    int m = graph.size();
    int n = graph[0].size();

    int minVal = graph[0][0];
    int maxVal = graph[0][0];

    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            minVal = min(minVal,graph[i][j]);
            maxVal = max(maxVal,graph[i][j]);
        }
    }

    int maxDiff = maxVal-minVal;
    int low = 0,high = maxDiff;
    
    while(low<high)
    {
        int mid = (high+low)/2;
        if(can_reach(graph, mid))
            high = mid;
        else
            low = mid+1;
    }

    return low;

}

int main()
{
    vector<vector<int>> grid = {
        {1, 3, 5},
        {2, 8, 4},
        {5, 6, 7}
    };
    
    int result = minimise_max_diff(grid);
    cout<<"Minimum maximum adjacent difference: "<<result<<endl;

    return 0;
}