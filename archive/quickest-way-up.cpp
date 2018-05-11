// https://www.hackerrank.com/challenges/the-quickest-way-up/problem

/*
    This is the first time I've had to apply BFS.
*/
#include<bits/stdc++.h>
using namespace std;

int special_BFS(vector<vector<int> > &adj, int s = 0)
{
    vector<bool> color(adj.size(),false);
    vector<int> parent(adj.size(), -1);
    queue<int> Q;
    color[s] = true;
    parent[s] = s;
    Q.push(s);

    bool found = false;
    while(!found && !Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (vector<int>::iterator v = adj[u].begin(); v != adj[u].end(); v++)
        {
            if(!color[*v])
            {
                //cout << *v << " ";
                color[*v] = true;
                parent[*v] = u;
                Q.push(*v);
                if (*v == 99)
                {
                    found = true; 
                    break;
                }
            }
        }
    }

    int rolls = 0;
    if (found)
    {
        vector<int> trace;
        int p = 99;
        trace.push_back(p);    
        while (parent[p] != p)
        {
            p = parent[p];
            trace.push_back(p);
        }
        vector<int>::iterator i;
            //cout << endl;
        for (i = trace.begin(); i < trace.end() - 1; i++)
        {
            //cout << (*i)+1 << "->";
            if ( (*i - *(i+1) <= 6) && (*i - *(i+1) > 0))
            {
                //cout << "adding roll \n ";
                rolls += 1;
            }
        } 
    }
    else rolls = -1;

    return rolls;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector< vector<int> > adj(100);
        int n, m;
        cin >> n;
        while(n--)
        {
            int u, v;
            cin >> u >> v;
            adj[u-1].push_back(v-1);
        }
        cin >> m;
        while(m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u-1].push_back(v-1);
        }
        for (int i = 0; i < 99; i++)
        {
            if (adj[i].empty())
                for (int j = 1; j <= 6; j++)
                    adj[i].push_back(i+j);
        }
        cout << special_BFS(adj) << endl;
    }
    return 0;
}