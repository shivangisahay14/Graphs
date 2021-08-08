void dfs(vector<int> adj[],int V,bool vis[],int start,stack<int>&s){
	    
	    vis[start]=true;
	    
	    for(auto node:adj[start]){
	        if(!vis[node]){
	            dfs(adj,V,vis,node,s);
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
	            dfs(adj,V,vis,i,s);
	        }
	    }
	    
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
