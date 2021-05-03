#include <bits/stdc++.h>
using namespace std;

//we find the shortest path in a weighted DAG.
//we use dfs to find the topo sort of the graph and then use some kind of modified BFS on the stack
//containing the toposort and find the min distances from a source to every node.

//DFS to find the toposort
void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &stk)
{
    vis[node] = 1;
    for (auto x : adj[node])
    {
        if (!vis[x.first])
        {
            topoSort(x.first, adj, vis, stk);
        }
    }

    stk.push(node);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        //we consider the graph is directed and weighted.
        adj[u].push_back({v, wt});
    }
    int source;
    cin >> source;

    //to store the topo sort
    stack<int> stk;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            topoSort(i, adj, vis, stk);
        }
    }

    int dist[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    while (!stk.empty())
    {
        int node = stk.top();
        stk.pop();
        if (dist[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if (dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        (dist[i] == INT_MAX) ? cout << "INF " : cout << dist[i] << " ";
    }

    return 0;
}