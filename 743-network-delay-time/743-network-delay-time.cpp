class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int m= times.size();
        vector<pair<int,int> >g[n+1];
        
        for(int i=0;i<m;i++)
        {
            g[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        vector<int> distTo(n+1,INT_MAX);
        distTo[0]=0;
        distTo[k]=0;
        pq.push(make_pair(0,k));
        
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            
            // vector<pair<int,int>> :: iterator it;
            for(auto it : g[prev])
            {
                int next = it.first;
                int nextDist = it.second;
                if(distTo[next] > distTo[prev]+nextDist)
                {
                    distTo[next] = distTo[prev]+nextDist;
                    pq.push(make_pair(distTo[next],next));
                }
            }
            
        }
        
        int ans = *max_element(distTo.begin(),distTo.end()); 
        return ans<INT_MAX?ans:-1;
    }
};