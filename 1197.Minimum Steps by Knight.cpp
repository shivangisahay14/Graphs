bool isValid(int i, int j,int N)
{
    if (i >= 1 && i <= N && j >= 1 && j <= N)
        return true;
    return false;
}
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int x1=KnightPos[0],y1=KnightPos[1];
	    int x2=TargetPos[0],y2=TargetPos[1];
	    
	    int x[]={-2,-1,1,2,-2,-1,1,2};
	    int y[]={-1,-2,-2,-1,1,2,2,1};
	    
	    bool vis[N+1][N+1];
	    for(int i=1;i<N+1;i++){
	        for(int j=1;j<N+1;j++){
	            vis[i][j]=false;
	        }
	    }
	    
	    queue<pair<int,int>>q;
	    
	    q.push({x1,y1});
	    vis[x1][y1]=true;
	    int count=0;
	    
	    while(!q.empty()){
	        int n=q.size();
	        
	        while(n--){
	            
	            pair<int,int>p=q.front();
	            q.pop();
	            int i=p.first;
	            int j=p.second;
	            
	            if(i==x2 and j==y2){
	                return count;
	            }
	            
	            for(int v=0;v<8;v++){
	                if(isValid(i+x[v],j+y[v],N) and vis[i+x[v]][j+y[v]]==false){
	                    q.push({i+x[v],j+y[v]});
	                    vis[i+x[v]][j+y[v]]=true;
	                    
	                }
	            }
	        }
	        count++;
	    }
	    return -1; //if destination is found
	}
