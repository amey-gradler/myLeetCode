class Solution {
public:
    
    void dfs(int node,vector<vector<int>>& adjList,vector<int>& vis,long long &ns)
    {
        vis[node]=1;
        ns++;
        for(auto it:adjList[node])
        {
            if(!vis[it])
            {
                dfs(it,adjList,vis,ns);
            }
        }
        return ;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adjList(n,vector<int>());
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<long long> noNodes;
        int cnt=0;
        
        vector<int> vis(n,0);
        
        long long ns=0;
        long long ans=0;
        long long total=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adjList,vis,ns);
                cnt++;
                // noNodes.push_back(ns);
                ans += total*ns;
                total+=ns;
                ns=0;
            }
        }
        
        // long long int ans=0;
        // for(int i=0;i<cnt;i++)
        // {
        //     for(int j=i+1;j<cnt;j++)
        //     {
        //         ans+=noNodes[i]*noNodes[j];
        //     }
        // }
        return ans;
        
        
    }
};