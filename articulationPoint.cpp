#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &tin, vector<int> &low, int timer, set<int> &artPoints)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, adj, vis, tin, low, timer, artPoints);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && parent != -1)
            {
                artPoints.insert(node);
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
    if (child > 1 && parent == -1)
    {
        artPoints.insert(node);
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
    set<int> artPoints;
    //1-based indexing of nodes
    vector<int> tin(n + 1, -1);
    vector<int> low(n + 1, -1);
    vector<int> vis(n + 1, 0);
    int timer = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, adj, vis, tin, low, timer, artPoints);
        }
    }
    for (auto x : artPoints)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}