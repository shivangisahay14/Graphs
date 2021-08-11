void dfs(vector<int> adj[],int V,int start,bool vis[],stack<int>&s){
        
        vis[start]=true;
        
        for(auto x:adj[start]){
            if(!vis[x]){
                dfs(adj,V,x,vis,s);
            }
        }
        s.push(start);
        
    }
    
    void dfs_util(vector<int> adj[],int V,int start,bool vis1[],int &count){
        
        vis1[start]=true;
        count++;
        
        for(auto x:adj[start]){
            if(!vis1[x]){
                dfs_util(adj,V,x,vis1,count);
            }
        }
        
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    stack<int>s;
	    bool vis[V];
        fill(vis,vis+V,false);
        
        for(int i=0;i<V;i++){
	        if(vis[i]==false){
	            dfs(adj,V,i,vis,s);
	        }
	    }
	    
	    int temp=s.top();
	    bool vis1[V];
        fill(vis1,vis1+V,false);
        int count=0;
        
        dfs_util(adj,V,temp,vis1,count);
        
        if(count==V){
            return temp;
        }
        else{
            return -1;
        }	    
	    
	}
