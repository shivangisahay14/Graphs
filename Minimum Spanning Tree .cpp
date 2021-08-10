int spanningTree(int V,int E,vector<vector<int> > graph)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    
    bool vis[V];
    for(int i=0; i<V; i++)
        vis[i] = 0;
    int ans = 0;
    while(!pq.empty())
    {
        int w = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(vis[curr])
            continue;
        ans += w;
        vis[curr] = true;
        
        for(int i=0; i<V; i++)
        {
            if(!vis[i] && graph[curr][i] != INT_MAX)
                pq.push({graph[curr][i],i});
        }
        
    }
    
    return ans;
}


int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V], res=0;
        fill(key,key+V,INT_MAX);
        bool mSet[V] = {false};
        
        key[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});
        
        int count=0;
        
        while(count<V) {
            auto temp = q.top();
            q.pop();
            int dist = temp.first;
            int u = temp.second;
            
            if(mSet[u]) continue;
            
            count++;
            mSet[u] = true;
            res+= key[u];
            
            for(int i=0;i<adj[u].size();i++) {
                int v = adj[u][i][0];
                if(key[v]>adj[u][i][1]) {
                    key[v] = adj[u][i][1];
                    q.push({key[v],v});
                }
            }
            
        }
        
        return res;
        // code here
    }
