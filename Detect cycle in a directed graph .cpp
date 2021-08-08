bool dfs(vector<int> adj[],int V,bool vis[],int start,bool anc[]){
        
        vis[start]=true;
        anc[start]=true;
        
        for(auto x:adj[start]){
            if(!vis[x]){
                if(dfs(adj,V,vis,x,anc)){
                    return true;
                }
            }
            else if(anc[x]){
                return true;
            }
        }
        anc[start]=false;
        return false;
        
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    bool vis[V],anc[V];
	    for(int i=0;i<V;i++){
	        vis[i]=false;
	        anc[i]=false;
	    }
	    int start=0;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(dfs(adj,V,vis,i,anc)){
	                return true;
	            }
	        }
	    }
	    return false;
	}
