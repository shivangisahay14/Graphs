//method1
int mindist(vector<int>value,vector<bool>processed)
{       int min=INT_MAX,index;
        for(int v=0;v<value.size();v++)
        {   if(!processed[v] && value[v]<=min)
            {   min=value[v];
                index=v;
            }
        }
        return index;
}
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{          
           
            vector<int>value(V,INT_MAX);
            vector<bool>processed(V,false);
            
            value[src]=0;
            
            for(int count=0;count<V-1;count++)
            {   int u=mindist(value,processed);
                processed[u]=true;
                for(int v=0;v<V;v++)
                {   if(g[u][v] && !processed[v] &&  value[v]>value[u]+g[u][v])
                        value[v]=value[u]+g[u][v];
                }
                
            }
            return value;
               
}

//method-2 priority queue

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    int dis[V];
    for(int i=0; i<V; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int curr = pq.top().second;
        pq.pop();
        
        for(int i=0; i<V; i++)
        {
            if(graph[curr][i] && dis[i] > dis[curr] + graph[curr][i])
            {
                dis[i] = dis[curr] + graph[curr][i];
                pq.push({dis[i],i});
            }
        }
    }
    
    for(int i=0; i<V; i++)
        cout<<dis[i]<<" ";
    
}

//method3
int getminindex(vector<int> d, bool vis[], int V){
    int min = INT_MAX, min_vertex = -1;
    
    for(int i=0;i<V;i++){
        if(!vis[i] && d[i]<=min){ 
            min = d[i];
            min_vertex = i;
        }
    }
    
    return min_vertex;
}

vector <int> dijkstra(vector<vector<int>> g, int src, int V) {
    vector<int> d(V);
    fill(d.begin(),d.end(),INT_MAX);
    
    bool vis[V] = { 0 };
    d[src] = 0;
    
    for(int i=0;i<V-1;i++){
        int u = getminindex(d,vis,V);
        
        vis[u] = 1;
        
        for(int j=0;j<V;j++){
            if(!vis[j] && g[u][j] && d[u]!=INT_MAX && d[u]+g[u][j]<d[j])
                d[j] = d[u] + g[u][j];
        }
    }
    
    return d;
}

//method 4 array of adj matrix
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        dist[S]=0;
        pq.push({0,S});
        
        while(!pq.empty()){
            
            int mv = pq.top().second;
            pq.pop();
            
            for(auto j:adj[mv]){
                
                int d = j[0];
                int w = j[1];
                if( w+dist[mv]<dist[d]){
                    dist[d] = w+dist[mv];
                    pq.push({dist[d],d});
                }
            }
        }
        
        return dist;
        
    }
