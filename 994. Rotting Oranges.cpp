    bool issafe(vector<vector<int>>& grid,int i, int j)
{
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size())
        return true;
    return false;
}
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        if(fresh==0){
            return 0;
        }
        
        int level=0;
        while(!q.empty()){
            int n=q.size();
            
            while(n--){
                
                pair<int,int>p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                
                if(issafe(grid,i + 1, j) and grid[i+1][j]==1){
                q.push({i+1,j});
                grid[i+1][j] = 2;
                fresh--;
                }
            
                if(issafe(grid,i - 1, j) and grid[i-1][j]==1 ){
                    q.push({i-1,j});
                    grid[i-1][j] = 2;
                    fresh--;
                }
                
                if(issafe(grid,i, j+1) and grid[i][j+1]==1){
                    q.push({i,j+1});
                    grid[i][j+1] = 2;
                    fresh--;
                }
                
                if(issafe(grid,i, j-1) and grid[i][j-1]==1 ){
                    q.push({i,j-1});
                    grid[i][j-1] = 2;
                    fresh--;
                }
            }
            level++;
        }
        
        if(fresh==0){
            return level-1;
        }
        else{
            return -1;
        }
        
    }
