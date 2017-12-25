#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> edge;

#define all(a) a.begin(),a.end()

class UF 
{
    vector<int> parent;
    vector<int> size;
    int count;

public:

    UF(int n);
    int find(int p);
    bool connected(int p, int q);
    void unite (int p, int q);
};

UF::UF(int n)
{
    count = n;
    parent.resize(n);
    size.resize(n);
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int UF::find(int p)
{
    int root = p;
    while (root != parent[root])
        root = parent[root];
    while (p != root)
    {
        int newp = parent[p];
        parent[p] = root;
        p = newp;
    }
    return root;
}

void UF::unite(int p, int q) 
{
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ) return;

    // make smaller root point to larger one
    if (size[rootP] < size[rootQ]) 
    {
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
    }
    else 
    {
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
    }
    count--;
}

bool UF::connected(int p, int q)
{
    return (find(p) == find(q));
}

vector< pair<int, edge> > kruskal_MST(vector< pair<int, edge> > &edges, int n)
{
    UF disjoint_set(n);
    vector< pair<int, edge> > MST;
    sort(all(edges));
    int sum = 0;
    for(vector< pair<int, edge> >::iterator i = edges.begin(); i != edges.end(); i++)
    {
        int u = i->second.first;
        int v = i->second.second;

        if (!disjoint_set.connected(u,v))
        {
            MST.push_back(*i);
            disjoint_set.unite(u,v);
            //sum += i->first;
        }
    }
    return MST;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector< pair<int, edge> > edges(m);
    
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {z,{x,y}};
    }

    
}