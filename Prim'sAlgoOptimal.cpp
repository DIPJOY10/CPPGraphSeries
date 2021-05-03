#include <bits/stdc++.h>
using namespace std;

//optimal prim's algo implementation using priority queue.

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        //we consider the graph is undirected and weighted.
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int key[n], parent[n];
    bool mstSet[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX, parent[i] = -1, mstSet[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    //o(NlogN) time complexity
    for (int count = 0; count < n; count++)
    {
        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], u});
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << "--" << i << endl;
    }

    return 0;
}