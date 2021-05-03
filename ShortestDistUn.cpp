#include <bits/stdc++.h>
using namespace std;

//shortest distance of source node to all other nodes in an undirected graph.
//we use BFS and unit weights on the undirected graph

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
    int source;
    cin >> source;

    int dist[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}