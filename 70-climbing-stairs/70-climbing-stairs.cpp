class Solution {
public:
    
    int solve(int n)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        
        return solve(n-1) + solve(n-2);
        
    }
    
    int climbStairs(int n) {
        
        // return solve(n);
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1]= 1;
        dp[2]= 2;
        for(int i=3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
        
        
    }
};