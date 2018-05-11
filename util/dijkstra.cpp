#include<bits/stdc++.h>

using namespace std;

/*
    I have realized a few things.
    STL priority Queue is crap.
    Sets are lit af.
        - Deletion of position in amortized constant
        - Insertion in log(n)
        - They store info in a sorted manner.
        - BST/Heaps i guess?
*/

vector<long> dijkstra(vector< vector < pair<long, long> > > adj, long s)
{
    vector<long> dist(adj.size(), 1e9);
    vector<bool> visited(adj.size(), false);
    dist[s] = 0;
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> Q;
    Q.push({0, s});
    while(!Q.empty())
    {
        long v = Q.top().second;
        long d = Q.top().first;
        Q.pop();
        if(!visited[v])
        {
            visited[v] = true;
            for(auto it: adj[v])
            {
                long u = it.first;
                long w = it.second;
                if(dist[v] + w < dist[u])
                {
                    dist[u] = dist[v] + w;
                    Q.push({dist[u], u});
                }
            }
        }
    }
    return dist;
}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long t = 1;
    while(t--)
    {
        long n, m;
        cin >> n >> m;
        vector< vector < pair<long, long> > > adj(n);
        while(m--)
        {
            long x, y, r;
            cin >> x >> y >> r;
            x--; y--;
            adj[x].push_back(make_pair(y, r));
            adj[y].push_back(make_pair(x, r));
        }
        long s;
        cin >> s;
        s--;
        vector<long> answer = dijkstra(adj, s);
        for (long i = 0; i < n; i++)
        {
            if (i == s)
                continue;
            if (answer[i] == 1e9)
                answer[i] = -1;
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}