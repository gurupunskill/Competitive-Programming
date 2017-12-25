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

class Graph
{
    vector<long> *adj;
    vector<long> components;
    bool *color;
    long V;

public:

    Graph(long n);
    void addEdge(long u, long v);
    void DFS();
    void DFS_visit(long v, long comp_no);
    vector<long> component();
};

Graph::Graph(long n)
{
    adj = new vector<long>[n+1];
    color = new bool[n+1];
    V = n;
}

void Graph::addEdge(long u, long v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::DFS_visit(long v, long comp_no)
{
    color[v] = true;
    components[comp_no]++;
    for(vector<long>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if (!color[*it])
            DFS_visit(*it, comp_no);
    }
}

void Graph::DFS()
{
    long comp_no = -1;
    for (long v = 1; v < V+1; v++)
        color[v] = false;
    for (long v = 1; v < V+1; v++)
    {
        if(!color[v])
        {
            components.push_back(0);
            comp_no++;
            DFS_visit(v, comp_no);
        }
    }
}

vector<long> Graph::component()
{
    return components;
}

int main()
{
    long q;
    cin >> q;
    while(q--)
    {
        long n, m, clib, croad;
        cin >> n >> m >> clib >> croad;
        long cost = 0;

        Graph G(n);
        while(m--)
        {
            long u, v;
            cin >> u >> v;
            G.addEdge(u, v);
        }

        if (clib <= croad)
        {
            cost = clib*n;
        }

        else
        {
            G.DFS();
            vector<long> components = G.component();
            for (vector<long>::iterator i = components.begin(); i != components.end(); i++)
            {
                cost = cost + clib + (croad*(*i - 1));
            }
        }
        cout << cost << endl;

    }
    return 0;
}