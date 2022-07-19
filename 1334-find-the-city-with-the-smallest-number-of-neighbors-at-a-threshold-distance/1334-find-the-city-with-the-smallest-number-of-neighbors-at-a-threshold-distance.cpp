class Solution {
public:
    
    unordered_map<int,vector<int>> mp;
    
    
    vector<int> dijkstra(int src,int n,int th,vector<pair<int,int>> adj[])
    {
        vector<int> distTo(n,INT_MAX);
        distTo[src] = 0;
        priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            
            for(auto it : adj[prev])
            {
                int next = it.first;
                int nextDist = it.second;
                if(distTo[next]>distTo[prev]+nextDist)
                {
                    distTo[next] = distTo[prev] + nextDist;
                    pq.push({distTo[next],next});
                }
            }
            
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(i==src) continue;
            if(distTo[i]<= th )
                ans.push_back(i);
        }
        return ans;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        for(int i=0;i<n;i++)
        {
            mp[i] = dijkstra(i,n,distanceThreshold,adj);
        }
        
        int ans=INT_MIN;
        int x = INT_MAX;
        for(auto it : mp)
        {
            if(it.second.size()<x)
            {
                x=it.second.size();
                ans = it.first;
            }
            else if(it.second.size()==x)
            {
                ans = max(ans,it.first);
            }
        }
        return ans;
        
    }
};