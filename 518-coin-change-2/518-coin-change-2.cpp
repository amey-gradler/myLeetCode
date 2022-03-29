class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        
        //base case
        for(int t=0;t<amount+1;t++)
        {
            dp[0][t] = t%coins[0]==0;
        }
        
        //
        for(int i=1;i<n;i++)
        {
            for(int t=0;t<amount+1;t++)
            {
                int notTake  = dp[i-1][t];
                int take = 0;
                if(coins[i]<=t)
                    take = dp[i][t-coins[i]];
                
                dp[i][t] = take+notTake;
                
            }
        }
        
        return dp[n-1][amount];
        
        
    }
};