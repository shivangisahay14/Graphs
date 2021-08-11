void dfs(vector<vector<int>>& image, int i, int j, int newColor,int oldColor){
        
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() ||
                image[i][j]!=oldColor){
                    return;
                }
        image[i][j]=newColor;
        
        dfs(image,i+1,j,newColor,oldColor);
        dfs(image,i-1,j,newColor,oldColor);
        dfs(image,i,j+1,newColor,oldColor);
        dfs(image,i,j-1,newColor,oldColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc]==newColor){
            return image;
        }
        dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
        
    }
