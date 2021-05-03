#include <bits/stdc++.h>
using namespace std;

int parent[100005];
int rnk[100005];
int n;

//disjoint set using rank and path compression

//note: union and rank keywords can't be used

void makeSet()
{
    for (int i = 1; i <= n; i++)
    {
        rnk[i] = 0;
        parent[i] = i;
    }
}

//o(4alpha) approx o(4) constant time.
int findPar(int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    //path compression
    return parent[node] = findPar(parent[node]);
}

void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (rnk[u] < rnk[v])
    {
        parent[u] = v;
    }
    else if (rnk[v] < rnk[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rnk[u]++;
    }
}

int main()
{
    cin >> n;
    makeSet();
    int m;
    cin >> m;
    //takes just o(m) time to connect the components for m queries,o(1) for each query
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    //check if two nodes are in same components or not
    int u, v;
    cin >> u >> v;
    if (findPar(u) != findPar(v))
    {
        cout << "Different Component" << endl;
    }
    else
    {
        cout << "Same Component" << endl;
    }

    return 0;
}