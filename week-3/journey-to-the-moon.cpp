#include <bits/stdc++.h>
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
    adj = new vector<long>[n];
    color = new bool[n];
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
    for (long v = 0; v < V; v++)
        color[v] = false;
    for (long v = 0; v < V; v++)
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
    long n, p;
    cin >> n >> p;
    Graph G(n);
    while(p--)
    {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }
    G.DFS();
    vector<long> comps = G.component();
    long sum = accumulate(all(comps), 0);
    long possibilities = 0;
    for (vector<long>::iterator i = comps.begin(); i != comps.end(); i++)
    {
        //cout << *i << " ";
        possibilities += ((sum - *i)*(*i));
    }
    cout << possibilities/2 << endl;
    return 0;
}

