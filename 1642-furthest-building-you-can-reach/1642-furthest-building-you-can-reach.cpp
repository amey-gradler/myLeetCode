class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n =heights.size();
        int i=0;
        
        long long sumb=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        while(i<n-1 && sumb<=bricks)
        {
            int diff = heights[i+1]-heights[i];
            if(diff<=0)
            {
                i++;
                continue;
            }
            pq.push(diff);
            
            while(pq.size()>ladders)
            {
                sumb+=pq.top();
                pq.pop();
            }
            if(sumb>bricks) break;
            i++;
        }
        if(i>=n-1) return n-1;
        return i;
    }
};