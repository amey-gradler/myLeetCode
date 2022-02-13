class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int start, int end) {
        vector<pair<int,double> > adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],pro[i]});
            adj[edges[i][1]].push_back({edges[i][0],pro[i]});
        }
        
        priority_queue<pair<double,int>> pq; //maxheap
        vector<double> mx(n,(double)0.0);
        
        mx[start]=1.0;
        pq.push({(double)1.0,start});
        
        while(!pq.empty())
        {
            
            auto top = pq.top();
            pq.pop();
            
            double prob = top.first;
            int node = top.second;
            
            for(auto to : adj[node])
            {
                if(mx[to.first]<prob*to.second)
                {
                    mx[to.first] = prob*to.second;
                    pq.push({mx[to.first] , to.first});
                }
            }
            
        }
        return mx[end];
        
    }
};