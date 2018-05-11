// This is the first time I'm doing a graph question

/*
    The idea is to:
    Use DFS to find connected components first. Or, I can use union find.
    Which is better cuz log*n.
    And it gives me the component list directly.
    So fuck you, DFS.
*/

// I spent some time revising graph algos and implementing it nicely in C++
// While I do have my /util functions I'm going to try and implement
// the algorithm manually as much as I can so I get a hold of
// the algorithms.

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define all(a) a.begin(),a.end()

class UF
{
    long *parent;
    long *size;
    long nn;

public:

    UF(long n);
    long find(long p);
    bool connected(long p, long q);
    void unite(long p, long q);
    map<long,long> components();
    vector<long> forest();
};

UF::UF(long n)
{
    nn = n;
    parent = new long[n];
    size = new long[n];
    for (long i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

long UF::find(long p)
{
    long root = p;
    while (root != parent[root])
        root = parent[root];
    while (p != root)
    {
        long newp = parent[p];
        parent[p] = root;
        p = newp;
    }
    return root;
}
void UF::unite(long p, long q)
{
    long rootP = find(p);
    long rootQ = find(q);
    
    if (rootP != rootQ)
    {
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
    }
}

map<long, long> UF::components()
{
    map <long, long> comps;
    for (long i = 0; i < nn; i++)
    {
        if (comps.count(parent[i]) == 0)
        {
            comps.insert(make_pair(parent[i], 1));
        }
        else
        {
            comps[parent[i]]++;
        }
    }
    return comps;
}

vector<long> UF::forest()
{
    vector<long> forests(parent, parent+nn-1);
    return forests;
}

int main()
{
    long q;
    cin >> q;
    while (q--)
    {
        long n, m, clib, croad;
        long cost = 0;
        cin >> n >> m >> clib >> croad;
        UF cities(n);
        while (m--)
        {
            long u, v;
            cin >> u >> v;
            u--;
            v--;
            cities.unite(u,v);
        }
        
        if (clib <= croad)
        {
            cost = n*clib;
        }
        else
        {
            map<long, long> comps = cities.components();
            cost += clib*comps.size();
            map<long, long>::iterator i;
            for (i = comps.begin(); i != comps.end(); i++)
            {
                cost += (((*i).second - 1)*croad);
            }
        }
        cout << cost << endl;
    }
    return 0;
}
