vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        
        vector<int>path;
        for(int i=0;i<V;i++){
            path[i]=INT_MAX;
        }
        path[S]=0;
        
        
        for(int i=0;i<V-1;i++){
            for(int j=0;j<adj.size();j++){
                
                int u=adj[j][0];
                int v=adj[j][1];
                int wt=adj[j][2];
                
                if(path[u]==INT_MAX){
                    continue;
                }
            
                else if(path[u]+wt<path[v]){
                    path[v]=path[u]+wt;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(path[i]==INT_MAX){
                path[i]=100000000;
            }
        }
        return path;
        
    }


vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        
        int m = adj.size();
        vector<int> value(V,100000000);
        // distance of source is zero;
        value[S]=0;
        
        // update to break loop if we got answer before processing the loop n-1 times;
        //update will break when we get same shortest path continuouslhy twice ..hence nothing  updated
        bool update;
        
        for(int i=0;i<V-1;i++)
        {
            update = false;
            // we will process every edge v-1 times
            for(int j=0;j<m;j++)
            {
                int u = adj[j][0];
                int v = adj[j][1];
                int w = adj[j][2];
                if(value[u]!=100000000 && value[u]+w<value[v])
                {
                    value[v]=value[u]+w;
                    update =true;
                }
            }
            if(update==false)
                break;
        }
        return value;     
        
    }
