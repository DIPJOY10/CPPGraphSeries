#include <bits/stdc++.h>
using namespace std;

//Breadth first search traversal in graphs
//we traverse the adjacent nodes first and then move to the next node.
//time complexity is o(n) && space complexity is o(n)-we use a queue and a visited array

int main()
{
    int n, m;
    cin >> n >> m;
    //n is the number of nodes and m is the number of edges
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        //we consider the graph is undirected and unweighted.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfs;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }

    for (auto x : bfs)
    {
        cout << x << " ";
    }

    return 0;
}