class Solution {
public:
    
    int solve(int i,int t,vector<int> coins,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(t % coins[0]==0)
                return t/coins[0];
            return 1e9;
        }
        
        if(dp[i][t]!=-1)
            return dp[i][t];
        
        
        int notTake = solve(i-1,t,coins,dp);
        int take = 1e9;
        if(coins[i]<=t)
            take = 1 + solve(i,t-coins[i],coins,dp);
        
        return dp[i][t] = min(take,notTake);
        
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
        
        for(int t = 0 ;t<amount+1;t++)
        {
            if(t%coins[0]==0) dp[0][t] = t/coins[0];
            else dp[0][t]=1e9;
        }
        
            for(int i=1;i<n;i++)
            {
                for(int t=0;t<amount+1;t++)
                {
                    int notTake = dp[i-1][t];
                    int take = 1e9;
                    if(coins[i]<=t)
                        take = 1 + dp[i][t-coins[i]];
        
                    dp[i][t] = min(take,notTake);
                }
            }
            
            return dp[n-1][amount]>=1e9 ? -1 :dp[n-1][amount]  ;
        
        
        
        // int ans = solve(n-1,amount,coins,dp);
        // return ans>=1e9?-1:ans;
        
    }
};