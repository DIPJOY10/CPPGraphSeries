#include <bits/stdc++.h>
using namespace std;

//detecting cycle in undirected graph using bfs
bool check(int node, int n, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;
    q.push({node, -1});
    vis[node] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, node});
            }
            else if (prev != it)
            {
                return true;
            }
        }
    }
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
        //we consider the graph is undirected and unweighted.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (check(i, n, adj, vis))
            {
                cout << "Cycle exists" << endl;
                return 0;
            }
        }
    }
    cout << "Cycle Doesn't exist" << endl;
    return 0;
}