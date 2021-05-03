//Kruskal's algo for minimum spanning tree
//it basically uses a greedy technique with the help of disjoint set data structure.

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int wt;
    int u;
    int v;
    node(int first, int second, int weight)
    {
        wt = weight;
        u = first;
        v = second;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int node, vector<int> parent)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findPar(parent[node], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    // to use a linear data structure of storing the edges, we use node( a struct) rather
    //than using an adjacency list.
    vector<node> edges;
    //take input for m edges
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        //the graph is undirected and weighted
        edges.push_back(node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);

    //The Kruskal's Algo
    //considering 0 based node indexing.
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    //final results
    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findPar(it.u, parent) != findPar(it.v, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            Union(it.u, it.v, parent, rank);
        }
    }

    //print the results
    cout << cost << endl;
    for (auto it : mst)
    {
        cout << it.first << "--" << it.second << endl;
    }
    return 0;
}