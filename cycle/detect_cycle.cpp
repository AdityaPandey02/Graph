#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool detectCycleBFS(vector<vector<int>>& adj, int v, vector<int>& visited) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int x : adj[curr]) {
            if (visited[x] == 1) {
                return true;
            }
            if (visited[x] == 0) {

                visited[x] = 1;
                q.push(x);
            }
        }
        visited[curr] = 2;
    }
    return false;
}

bool hasCycle(vector<vector<int>>& adj) {
    vector<int> visited(adj.size(), 0);

    for (int i = 0; i < adj.size(); i++) {
        if (visited[i] == 0) {
            if (detectCycleBFS(adj, i, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    if (hasCycle(adj))
        cout << "Contains Cycle" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}
