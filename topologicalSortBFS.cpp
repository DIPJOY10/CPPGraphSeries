#include <bits/stdc++.h>
using namespace std;

//Kahn's Algorithm
//--Topological Sort using BFS.

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        //we consider the graph is directed,acyclic and unweighted.
        adj[u].push_back(v);
    }

    vector<int> sorted;
    queue<int> q;
    vector<int> indegrees(n + 1, 0);

    //calculate and store indegrees for each node.
    for (int i = 1; i <= n; i++)
    {
        for (int x : adj[i])
        {
            indegrees[x]++;
        }
    }

    //push all nodes with indegree=0 in the queue.
    for (int i = 1; i <= n; i++)
    {
        if (indegrees[i] == 0)
            q.push(i);
    }

    //BFS algo
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        sorted.push_back(node);
        for (int i : adj[node])
        {
            indegrees[i]--;
            if (indegrees[i] == 0)
            {
                q.push(i);
            }
        }
    }

    for (auto x : sorted)
    {
        cout << x << " ";
    }

    return 0;
}