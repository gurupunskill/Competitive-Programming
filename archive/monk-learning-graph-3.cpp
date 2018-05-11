    #include<bits/stdc++.h>
    using namespace std;
    int val[10005];
    bool compare(int a,int b)
    {
        if(val[a]==val[b])
            return a>b;
        else
            return val[a]>val[b];
    }
    int main()
    {
    	int n,m,k,x,y;
    	scanf("%d%d%d",&n,&m,&k);
    	vector< vector<int> > graph(n+1);
    	for(int i=1;i<=n;i++)
    	    scanf("%d",&val[i]);
    	while(m--)
    	{
    	    scanf("%d%d",&x,&y);
    	    graph[x].push_back(y);
    	    graph[y].push_back(x);
    	}
    	for(int i=1;i<n+1;i++)
    	{
    	    nth_element(graph[i].begin(),graph[i].begin()+k-1,graph[i].end(),compare);
    	    //vector<int>::iterator it=graph[i].begin()+k-1;
    	    if(graph[i].size()<k)
    	        printf("-1\n");
    	    else
    	        printf("%d\n",graph[i][k-1]);
    	}
    	return 0;
    }