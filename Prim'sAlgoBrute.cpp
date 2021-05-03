#include <bits/stdc++.h>
using namespace std;

//creating the Minimum Spanning Tree(MST) from a graph.
//A Spanning Tree is a tree created from a given graph such that the tree has all the N nodes and Exactly
//N-1 edges such that every node is reachable from every other node.

//The Minimum Spanning Tree has the minimum sum of weights of edges among all possible spanning trees
//of a given graph.

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    //considering 0 based indexing
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        //we consider the graph is undirected and weighted.
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int parent[n], key[n];
    bool mstSet[n];

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;

    key[0] = 0;
    //O(N^2) complexity
    for (int count = 0; count < n; count++)
    {
        int mn = INT_MAX, u;
        for (int v = 0; v < n; v++)
        {
            if (mstSet[v] == false && mn > key[v])
            {
                mn = key[v];
                u = v;
            }
        }
        mstSet[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << "--" << i << endl;
    }

    return 0;
}