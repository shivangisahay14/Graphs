 bool checkComponents(vector<vector<int>>& graph,int V,int &src,int vis[]){
        
        queue<pair<int,int>>q;
        q.push({src,0}); //source,level
        
        while(!q.empty()){
            pair<int,int>p=q.front();
            int i=p.first;
            int j=p.second;
            q.pop();
            
            if(vis[i]!=-1){
                if(j!=vis[i]){
                    return false;
                }
            }
            else{
                vis[i]=j;
            }
            
            for(int x:graph[i]){
                if(vis[x]==-1){
                    q.push({x,j+1});
                }
            }
            
        }
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V=graph.size();
        int vis[V];
	    fill(vis,vis+V,-1);
	    
	    for(int v=0;v<V;v++){
	        if(vis[v]==-1){
	            bool ans= checkComponents(graph,V,v,vis);
	            if(ans==false){
	                return false;
	            }
	        }
	    }
	    return true;
        
    }










bool checkComponentsForBipartite(vector<vector<int>> &graph, int &src, vector<int>  &isVisited){
        queue <pair<int, int> > q;
        q.push(make_pair(src, 0));
        while(!q.empty()){
            pair<int,int > node = q.front();
            q.pop();
            if(isVisited[node.first] != -1){
                if(isVisited[node.first] != node.second){
                    return false;
                }
            }
            isVisited[node.first] = node.second;
            
            for(int i=0; i<graph[node.first].size(); ++i){
                if(isVisited[graph[node.first][i]] == -1){
                    q.push(make_pair(graph[node.first][i], node.second + 1));
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> verticesVisited (graph.size(), -1);
        for(int i=0; i<graph.size(); ++i){
            if(verticesVisited[i] == -1){
                bool isBipartiteCheck = checkComponentsForBipartite(graph, i, verticesVisited);
                if(isBipartiteCheck == false){
                    return false;
                }
            }
        }
        return true;
    }
