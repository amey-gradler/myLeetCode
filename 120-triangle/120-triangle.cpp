class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>> &t, vector<vector<int>> &dp)
    {
       if(i==t.size()-1)
           return t[i][j];
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        
        int d = solve(i+1,j,t,dp);
        int dg = solve(i+1,j+1,t,dp);
        
        return dp[i][j] = t[i][j] + min(d,dg);
        
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        
        int n = t.size();
        // int n = triangle[m-1].size();
        
        vector<vector<int>> dp (n,vector<int> (n,INT_MAX));
        
        //tabulation
        for(int j=0;j<n;j++)
            dp[n-1][j] = t[n-1][j]; 
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int d = dp[i+1][j];
                int dg = dp[i+1][j+1];
                
                dp[i][j] = t[i][j] + min(d,dg);
            }
        }
        
        
        return dp[0][0];
        
    }
};