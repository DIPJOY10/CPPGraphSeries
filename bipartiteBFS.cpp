#include <bits/stdc++.h>
using namespace std;

//checking if a graph is bipartite with the help of BFS.
bool checkBipartite(int node, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(node);
    color[node] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int x : adj[cur])
        {
            if (color[x] == -1)
            {
                q.push(x);
                color[x] = 1 - color[cur];
            }
            else if (color[cur] == color[x])
            {
                return false;
            }
        }
    }
    return true;
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

    vector<int> color(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!checkBipartite(i, adj, color))
            {
                cout << "Not Bipartite Graph" << endl;
                return 0;
            }
        }
    }
    cout << "Bipartite Graph" << endl;

    return 0;
}