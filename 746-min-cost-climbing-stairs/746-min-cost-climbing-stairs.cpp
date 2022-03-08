class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        vector<int> t(n+1,0);
        for(int i=2;i<=n;i++)
        {
            int jump1 = t[i-1]+cost[i-1];
            int jump2=t[i-2]+cost[i-2];
            t[i] = min(jump1,jump2);
        }
        
        return t[n];
        
        
        
    }
};