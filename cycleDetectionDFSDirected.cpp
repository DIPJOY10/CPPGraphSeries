#include <bits/stdc++.h>
using namespace std;

//cycle detection in directed graph using DFS.
bool checkCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis)
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (int x : adj[node])
    {
        if (!vis[x])
        {
            if (checkCycle(x, adj, vis, dfsvis))
            {
                return true;
            }
        }
        else if (dfsvis[x])
        {
            return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        //we consider the graph is directed and unweighted.
        adj[u].push_back(v);
    }
    vector<int> vis(n + 1, 0), dfsvis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, adj, vis, dfsvis))
            {
                cout << "Cycle Exists" << endl;
                return 0;
            }
        }
    }
    cout << "Cycle Doesn't Exist" << endl;
    return 0;
}