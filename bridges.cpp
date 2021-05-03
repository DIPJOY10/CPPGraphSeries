#include <bits/stdc++.h>
using namespace std;

//we find the bridges in a graph using DFS.
//bridges are those edges in a graph such that on removing the edge, it creates two or more separate components.

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &tin, vector<int> &low, int timer)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, vis, adj, tin, low, timer);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node])
            {
                cout << node << "--" << it << endl;
            }
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
}

int main()
{
    //considering 1-based indexing of nodes.
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

    vector<int> tin(n + 1, -1);
    vector<int> low(n + 1, -1);
    vector<int> vis(n + 1, 0);

    int timer = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, adj, tin, low, timer);
        }
    }

    return 0;
}