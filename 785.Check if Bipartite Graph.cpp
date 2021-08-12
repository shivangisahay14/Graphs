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
