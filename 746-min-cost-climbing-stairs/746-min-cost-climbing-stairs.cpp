class Solution {
public:
    
    int solve(int i,int n,vector<int>& cost,vector<int>&t)
    {
        if(i>=n)
        {
            return 0;
        }
        
        if(t[i]!=0)
            return t[i];
        t[i] = cost[i]+min(solve(i+1,n,cost,t) , solve(i+2,n,cost,t)  );
        
        return t[i];
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        vector<int> t(n,0);
        solve(0,n,cost,t);
        
        return min(t[0],t[1]);
        
    }
};