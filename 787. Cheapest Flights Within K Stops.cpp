void solve(vector<vector<int>>& adj,vector<vector<int>>& cost,int src,int dst,int k,int& fare,int                               totCost,vector<bool>& visited)
    {
        if(k<-1)
            return;
        if(src==dst)
        {
            fare = min(fare,totCost);
            return;
        }
    
        visited[src] = true;
        for(int i=0;i<adj[src].size();++i)
        {
            if(!visited[adj[src][i]] && (totCost+cost[src][adj[src][i]] <= fare))
                solve(adj,cost,adj[src][i],dst,k-1,fare,totCost+cost[src][adj[src][i]],visited);
        }
        
        visited[src] = false;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<int>> adj(n);
        vector<vector<int>> cost(n+1,vector<int>(n+1));
        
        for(int i=0;i<flights.size();++i)
        {    
            adj[flights[i][0]].push_back(flights[i][1]);
            cost[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        
        vector<bool> visited(n+1,false);    //To break cycles
        int fare = INT_MAX;
        solve(adj,cost,src,dst,k,fare,0,visited);
        
        if(fare==INT_MAX)
            return -1;
        return fare;       
        
        }




typedef vector<int> VE;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>>adj[n];  //Array of Vectors - Adjacency List Undirected Weighted Graph

        // adjacency list: (src node) -> (destination node, cost)
        for(auto it: flights)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }

        //priority queue holds (cumulative cost, node at we are standing, number of stops till now)
        priority_queue<VE, vector<VE>, greater<VE>> pq;
        pq.push({0,src,0});

        vector<int> dist(n+1, INT_MAX); //to avoid TLE

        while(!pq.empty())
        {
            auto cur = pq.top(); pq.pop();
            int cost = cur[0], node = cur[1], edge_steps = cur[2];
            // or
            // int cost = pq.top()[0], node=pq.top()[1], stops=pq.top()[2];
            // pq.pop();

            if(node==dst) return cost;  //if we reached the dst node within k stops, return cost.

            if(edge_steps>k) continue;  // if we exceed edge_steps limit i.e. k, do not search further

            //Optimization to avoid TLE
            if(dist[node]<edge_steps) continue;
            dist[node]=edge_steps;

            for(auto it: adj[node])     //Go to adjacent nodes  //or pair<int,int>it
            {
                int nextNode = it.first;       
                int nextNodeDist = it.second;
                pq.push({cost+nextNodeDist, nextNode, edge_steps+1});
                //Add nextnode's dist to cost, nextNode, add 1 to edge_steps
            }
        }     

        return -1;
        //if we reach here that means either there is no destination 
        //or it was taking more than k stops to reach destination
        
    }
