#include <bits/stdc++.h>
using namespace std;

//depth first search traversal in graphs.
//go to the depth of each adjacent node and then visit the next adjacent node.

void dfsOfGraph(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs)
{
    dfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfsOfGraph(it, vis, adj, dfs);
        }
    }
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
        //we consider the graph is undirected and unweighted.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dfs;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfsOfGraph(i, vis, adj, dfs);
        }
    }

    for (auto x : dfs)
    {
        cout << x << " ";
    }

    return 0;
}