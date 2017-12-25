#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define all(a) a.begin(),a.end()

class UF 
{
    vector<int> parent;
    vector<int> size;
    int count;

public:

    UF(int n);
    set<int> components();
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

set<int> UF::components()
{
    set<int> comps(all(parent));
    return comps;
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

int main()
{
    int n, t;
    cin >> n >> t;
    UF uf(n);

    while(t--)
    {
        int p, q;
        cin >> p >> q;
        if (uf.connected(p,q)) continue;
        uf.unite(p,q);
        cout << p << " U " << q << endl;
    }
    return 0;
}
