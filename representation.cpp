#include <bits/stdc++.h>
using namespace std;

void representMatrix(int n, int m, int **adj)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            adj[i][j] = 0;
        }
    }
    while (m--)
    {
        //m rows will provide every edge detail
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    //n is the number of nodes and m is the number of edges

    //first method is to use an adjacency matrix.
    //space complexity is o(n^2);
    // int **adj = new int *[n + 1];
    // for (int i = 0; i < n + 1; i++)
    //     adj[i] = new int[n + 1];
    // representMatrix(n, m, adj);
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //second method is to store it in a adjacency list.
    //this is used in general.
    //space complexity is o(2e) where e is the number of edges
    // vector<int> adj[n + 1];
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     //we consider the graph is undirected.
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }

    // for (int i = 1; i < n + 1; i++)
    // {
    //     for (auto x : adj[i])
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    //for weighted undirected graph
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        //we consider the graph is undirected and weighted with weight wt for each edge
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    return 0;
}