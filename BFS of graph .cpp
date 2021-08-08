vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    int i;
	    queue<int>q;
	    bool vis[V];
	    vector<int>ans;
	    
	    for(i=0;i<V;i++){
	        vis[i]=false;
	    }
	    q.push(0);
	    vis[0]=true;
	    
	    while(!q.empty()){
	        int temp=q.front();
	        q.pop();
	        ans.push_back(temp);
	        
	        for(int i:adj[temp]){
	            if(!vis[i]){
	                q.push(i);
	                vis[i]=true;
	            }
	        }
	    }
	    return ans;
	    
	}
