#include <bits/stdc++.h>
using namespace std;

bool cycleDetectDFS(int node, int prev, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            //on directly returning a true or false, we do most of the visits from main function
            // return cycleDetectDFS(it, node, adj, vis);

            //on returning only true case, we go through all adjacent nodes and most of the visits are done in this function.
            if (cycleDetectDFS(it, node, adj, vis))
                return true;
        }
        else if (it != prev)
        {
            return true;
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
            if (cycleDetectDFS(i, -1, adj, vis))
            {
                cout << "Cycle Exists" << endl;
                return 0;
            }
        }
    }
    cout << "Cycle Doesn't Exist" << endl;

    return 0;
}