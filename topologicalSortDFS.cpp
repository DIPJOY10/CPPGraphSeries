#include <bits/stdc++.h>
using namespace std;

//topological sort using DFS algorithm.
//topological sort is defined as a linear ordering of vertices such that if there exists and edge u->v
//then u appears before v in the ordering.
//topo sort is possible only in DAG(Directed Acyclic Graph)

void topoSort(int node, vector<int> adj[], vector<int> &vis, stack<int> &stk)
{
    vis[node] = 1;
    for (int x : adj[node])
    {
        if (!vis[x])
        {
            topoSort(x, adj, vis, stk);
        }
    }
    stk.push(node);
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
        //we consider the graph is directed,acyclic and unweighted.
        adj[u].push_back(v);
    }

    stack<int> stk;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            topoSort(i, adj, vis, stk);
        }
    }

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    return 0;
}