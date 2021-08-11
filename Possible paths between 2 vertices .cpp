void dfs(int V, vector<int> adj[], int s, int d,bool vis[],int &count){
        
        if(s==d){
            count++;
            return;
        }
        vis[s]=true;
        for(auto x:adj[s]){
            if(!vis[x]){
                dfs(V,adj,x,d,vis,count);
            }
        }
        vis[s]=false;        
        
    }
    //Function to count paths between two vertices in a directed graph.
	int countPaths(int V, vector<int> adj[], int source, int destination)
	{
	    int count=0;
	    bool vis[V];
	    fill(vis,vis+V,false);
	    
	    dfs(V,adj,source,destination,vis,count);
	    
	    return count;
	}
