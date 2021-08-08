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
    
    void dfs_util(vector<int> adj[],int V,bool vis[],int start,stack<int>&s){
	    
	    vis[start]=true;
	    
	    for(auto node:adj[start]){
	        if(!vis[node]){
	            dfs_util(adj,V,vis,node,s);
	        }
	    }
	    s.push(start);
	    
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    bool vis[V];
	    for(int i=0;i<V;i++){
	        vis[i]=false;
	    }
	    stack<int>s;
	    int start=0;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs_util(adj,V,vis,i,s);
	        }
	    }
	    
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>ans;
        
        unordered_set<int> vertices;
        
        for (int i=0; i<numCourses; i++) {
            vertices.insert(i);
        }
        int V=vertices.size();
        
        vector<int> adj[V];
        for (vector<int> v : prerequisites ) {
            adj[v[0]].push_back(v[1]);
        }
        
        
        if (isCyclic(V,adj))
            return ans;
        
        ans=topoSort(V,adj);
        reverse(ans.begin(),ans.end());
        return ans;
                
    }
