bool dfs(int v, int count, vector<int> adj[], vector<bool> visited, int N){
        if(count == N){
            return true;
        }
        visited[v] = true;
        for(int i = 0; i < adj[v].size(); i++){
            if(!visited[adj[v][i]] && dfs(adj[v][i], count+1, adj, visited, N)){
                return true;
            }
        }
        return false;
    }
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int> adj[N+1];
        vector<bool> visited(N+1, false);
        for(int i = 0; i < M; i++){
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        for(int i = 2; i <= N; i++){
            if(dfs(i, 1, adj, visited, N)){
                return true;
            }
        }
        return false;        
    }
