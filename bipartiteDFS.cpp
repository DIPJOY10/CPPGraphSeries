#include <bits/stdc++.h>
using namespace std;

bool checkBipartite(int node, vector<int> adj[], vector<int> &color)
{
    if (color[node] == -1)
    {
        color[node] = 1;
    }
    for (int x : adj[node])
    {
        if (color[x] == -1)
        {
            color[x] = 1 - color[node];
            if (!checkBipartite(x, adj, color))
            {
                return false;
            }
        }
        else if (color[x] == color[node])
        {
            return false;
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