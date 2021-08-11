void dfs(vector<int> adj[],int V,int start,bool vis[],stack<int>&s){
        
        vis[start]=true;
        
        for(auto x:adj[start]){
            if(!vis[x]){
                dfs(adj,V,x,vis,s);
            }
        }
        s.push(start);
        
    }
    void rev_dfs(vector<int> revadj[],int V,int start,bool vis1[]){
        
        vis1[start]=true;
        
        for(auto x:revadj[start]){
            if(!vis1[x]){
                rev_dfs(revadj,V,x,vis1);
            }
        }
        
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int>s;
        bool vis[V];
        fill(vis,vis+V,false);
        
        
        for(int i=0;i<V;i++){
	        if(vis[i]==false){
	            dfs(adj,V,i,vis,s);
	        }
	    }
	    
	    vector<int>revadj[V];
	    
	    for(int v=0;v<V;v++){
	        for(int u:adj[v]){
	            revadj[u].push_back(v);
	        }
	    }
	    
	    bool vis1[V];
        fill(vis1,vis1+V,false);
	    int count=0;
	    
	    while(!s.empty()){
	        
	        int curr=s.top();
	        s.pop();
	        
	        if(vis1[curr]==false){
	            count++;
	            rev_dfs(revadj,V,curr,vis1);
	            
	        }
	        
	    }
	    return count;	    
    }
