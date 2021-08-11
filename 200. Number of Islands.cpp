void countIsland(vector<vector<char>>&grid, int i, int j,vector<vector<bool>>&visited){
    
        // Boundary Conditions 1) For Checking if its inside the Matrix 2) If it is visited then we should return;

        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || 
            visited[i][j] == true || grid[i][j] == '0'){
                return;
        }

         visited[i][j] = true;

         countIsland(grid,i-1,j,visited); // North
         countIsland(grid,i,j+1,visited); // East
         countIsland(grid,i,j-1,visited); // West
         countIsland(grid,i+1,j,visited); // South
    //if four directions are connected, if 8 then take other parameters as well

         return;
   }
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));

        for (int i = 0; i < grid.size();i++){
            for (int j = 0; j < grid[0].size();j++){
                visited[i][j] = false;
            }
        }
        
        int count = 0;
    
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1' && visited[i][j] == false){ // If the cell is Land and not been visited before
                   
                   countIsland(grid,i,j,visited);
                   count++;
                    
                }
            }
        }
    
        return count;
    }
