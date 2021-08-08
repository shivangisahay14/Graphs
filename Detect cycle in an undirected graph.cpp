bool dfs(vector<int>adj[],int V,int start,int parent,bool vis[]){
        
        vis[start]=true;
        
        //visiting neighbours of start node
        for(auto node:adj[start]){
            if(!vis[node]){
                //if sub-graph has cycle then whole graph will have cycle
                if(dfs(adj,V,node,start,vis)){
                    return true;
                }
            }
            
            else if(node != parent && vis[node] || node==start){
                return true;
            }
        }
        return false;
        
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    bool vis[V];
	    for(int i=0;i<V;i++){
	        vis[i]=false;
	    }
	    int start=0;
	    int parent=-1;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(dfs(adj,V,i,parent,vis)){
	                return true;
	            }
	        }
	    }
	    return false;
	}
