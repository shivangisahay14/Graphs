void dfs(vector<int> adj[],int V,int start,vector<int>&v,bool vis[]){
        
        v.push_back(start);
        vis[start]=true;
        
        for(auto x:adj[start]){
            if(!vis[x]){
                dfs(adj,V,x,v,vis);
            }
        }
        
    }
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    bool vis[V];
	    for(int i=0;i<V;i++){
	        vis[i]=false;
	    }
	    vector<int>v;
	    int start=0;
	    dfs(adj,V,start,v,vis);
	    return v;
	    
	}
