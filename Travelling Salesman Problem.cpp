void tsp(int currPos,vector<vector<int>>&cost,vector<bool>&vis,int count,
            int &mincost,int currcost,int V){
                
    if (count == V && cost[currPos][0]) {
        mincost = min(mincost, currcost+cost[currPos][0]);
        return;
    }
    
    for (int i=0; i < V; i++) {
        if (!vis[i] && cost[currPos][i]) {
            vis[i] = true;
            tsp(i,cost,vis,count+1,mincost,currcost+cost[currPos][i],V);
            
            vis[i] = false;
        }
    }
         
}

int total_cost(vector<vector<int>>cost){
    
    int currPos=0;
    int V=cost.size();
    vector<bool>vis(V,false);

    
    int count=1;
    int mincost=INT_MAX;
    int currcost=0;
    vis[0]=true;
    tsp(currPos,cost,vis,count,mincost,currcost,V);
    if(mincost==INT_MAX){
        return 0;
    }
    return mincost;
}
