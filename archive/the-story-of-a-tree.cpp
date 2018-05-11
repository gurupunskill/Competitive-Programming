// https://www.hackerrank.com/challenges/the-story-of-a-tree/problem

#include<bits/stdc++.h>

using namespace std;

#define WHITE false
#define BLACK true

vector<int> BFS(vector< vector<int> > adj, int s)
{
    vector<bool> color(adj.size(), WHITE);
    vector<int> parent(adj.size());

    for (int i = 0; i < adj.size(); i++)
    {
        parent[i] = i;
    }

    queue<int> Q;
    color[s] = BLACK;
    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (vector<int>::iterator v = adj[u].begin(); v != adj[u].end(); v++)
        {
            if (color[*v] == WHITE)
            {
                color[*v] = BLACK;
                parent[*v] = u;
                Q.push(*v);
            }
        }
        color[u] = BLACK;
    }

    return parent;
}

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        vector< vector<int> > adj(n);
        
        int k = n-1;
        while(k--)
        {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << "\n           ";
        for (int i = 0; i < n; i++)
            cout << i+1 << " ";
        for(int i = 0; i < n; i++)
        {
            vector<int> parent = BFS(adj, i);
            cout << "\nRoot as " << i+1 << ": ";
            for(int j = 0; j < n; j++)
            {
                cout << parent[j] + 1 << " ";
            }
        }
        cout << endl;
    }
    

    return 0;
}