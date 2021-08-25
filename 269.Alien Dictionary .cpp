string findOrder(string dict[], int N, int K) {
        
        int i,j,k;
        vector<int> v[K];
        for(i=0;i<N-1;i++)
        {
            for(j=0;j<dict[i].length();j++)
            {
                if(dict[i][j] != dict[i+1][j])
                {
                    v[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        queue<int> q;//topological sorting using kahn's algorithm
        int in[K]={0};
        for(i=0;i<K;i++)
        {
            for(auto it:v[i])
            {
                in[it]++;
            }
        }
        for(i=0;i<K;i++)if(!in[i])q.push(i);
        string s;
        while(!q.empty())
        {
            int node = q.front();
            s.push_back((char)(node+'a'));
            q.pop();
            for(auto it:v[node])
            {
                in[it]--;
                if(!in[it])q.push(it);
            }
        }
        return s;        
}
