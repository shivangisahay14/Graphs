bool isSafe1(int row, int col, vector<string> board, int n) {
        
        for(int i = 0; i< col; i++)
        {
            if(board[row][i] == 'Q')
                return false;
        }
        for(int i = row,j = col; i>=0 and j>=0; i--,j-- )
        {
            if(board[i][j] == 'Q')
                return false;
        }
        for(int i = row, j = col; i<n and j>=0; i++,j-- )
        {
            if(board[i][j] == 'Q')
                return false;
        }
        
        return true;

    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(isSafe1(row, col, board, n)) {
                board[row][col] = 'Q'; 
                solve(col+1, board, ans, n); 
                board[row][col] = '.'; 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
         
        solve(0,board, ans, n); 
        return ans; 
        
    }
    
    
    
GFG:
    bool IsSafe(vector<vector<int>>&chess,int row,int col,int n){
        
         for(int i = 0; i< col; i++)
        {
            if(chess[row][i] == 1)
                return false;
        }
        for(int i = row,j = col; i>=0 and j>=0; i--,j-- )
        {
            if(chess[i][j] == 1)
                return false;
        }
        for(int i = row, j = col; i<n and j>=0; i++,j-- )
        {
            if(chess[i][j] == 1)
                return false;
        }
        
        return true;

    }
    void printNQueens(vector<vector<int>>&chess,vector<vector<int>>&ans,vector<int>v,
                            int col,int n){
        if(col==n){
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (chess[i][j] == 1)
                        v.push_back(j + 1);
                }
            }
            ans.push_back(v);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(IsSafe(chess,row,col,n)){
                chess[row][col]=1;
                printNQueens(chess,ans,v,col+1,n);
                chess[row][col]=0;
            }
            
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>>chess(n,vector<int>(n));
        vector<vector<int>>ans;
        vector<int>v;
        int col=0;
        printNQueens(chess,ans,v,col,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
