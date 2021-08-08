vector<vector<int>>printGraph(int V, vector<int> adj[])
	{
	    vector<vector<int>> list(V);
	    for(int i=0;i<V;i++)
	    {   
	           list[i].push_back(i);
              for(int j=0;j<adj[i].size();j++)
              {
                  list[i].push_back(adj[i][j]);
              }
             
	    }
	    return list;
	}
