#include <bits/stdc++.h>
using namespace std;

//cycle detection in a directed graph using bfs---kahn's algorithm.
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
    }

    queue<int> q;
    vector<int> indegrees(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            indegrees[x]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegrees[i] == 0)
            q.push(i);
    }

    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (int i : adj[node])
        {
            indegrees[i]--;
            if (indegrees[i] == 0)
            {
                q.push(i);
            }
        }
    }

    if (cnt != n)
    {
        cout << "Cycle Exists" << endl;
    }
    else
    {
        cout << "Cycle Doesn't Exist" << endl;
    }

    return 0;
}