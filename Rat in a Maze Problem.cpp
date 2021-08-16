void solve(int i,int j,vector<vector<int>> &m,int n,vector<string>&ans,
            string move,vector<vector<int>>&vis){
                
        if(i==n-1 and j==n-1){
            ans.push_back(move);
            return;
        }
        //D
        if(i+1<n and !vis[i+1][j] and m[i+1][j]==1){
            vis[i][j]=1;
            solve(i+1,j,m,n,ans,move+'D',vis);
            vis[i][j]=0;
        }
        //L
        if(j-1>=0 and !vis[i][j-1] and m[i][j-1]==1){
            vis[i][j]=1;
            solve(i,j-1,m,n,ans,move+'L',vis);
            vis[i][j]=0;
        }
        //R
        if(j+1<n and !vis[i][j+1] and m[i][j+1]==1){
            vis[i][j]=1;
            solve(i,j+1,m,n,ans,move+'R',vis);
            vis[i][j]=0;
        }
        //U
        if(i-1>=0 and !vis[i-1][j] and m[i-1][j]==1){
            vis[i][j]=1;
            solve(i-1,j,m,n,ans,move+'U',vis);
            vis[i][j]=0;
        }
                
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==1){
            solve(0,0,m,n,ans,"",vis);
        }
        return ans;
        
    }
