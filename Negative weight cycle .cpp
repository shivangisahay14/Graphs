int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	   int dist[n];
	    for(int i=0;i<n;i++)
	    {
	        dist[i] = INT_MAX;
	    }
	    dist[0] = 0;
	    
	    for(int i=0;i<n-1;i++)
	    {
	        for(int j=0;j<edges.size();j++)
	        {
	            int a = edges[j][0];
	            int b = edges[j][1];
	            int w = edges[j][2];
	            
	            if(dist[a]!=INT_MAX&&dist[a]+w<dist[b])
	            {
	                dist[b] = dist[a] + w;
	            }
	        }
	    }
	    
	    for(int i=0;i<edges.size();i++)
	    {
	        int a = edges[i][0];
	        int b = edges[i][1];
	        int w = edges[i][2];
	        
	        if(dist[a]!=INT_MAX&&dist[a]+w<dist[b])
	        {
	            return 1; //it is a negative weight cycle
	        }
	    }
	    return 0;
	    
	}
