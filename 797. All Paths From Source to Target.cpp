vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>& graph, vector<int> &route, int node, int dest){
        route.push_back(node);
        if(node==dest){
            ans.push_back(route);
            route.pop_back();
            return;
        }
        for(auto vert:graph[node]){
            dfs(graph,route,vert,dest);
        }
        route.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> route;
        dfs(graph,route,0,graph.size()-1);
        return ans;
    }    
    
