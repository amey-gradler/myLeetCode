class Solution {
public:
    
        
    int solve(int i,int j,vector<vector<int>> &m,vector<vector<int>> &dp)
    {
        if(i==m.size()-1)
            return m[i][j];
        
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        
        int ans=INT_MAX;
        
        for(int k=0;k<m.size();k++)
        {
            if(k==j)
                continue;
            ans = min(ans,solve(i+1,k,m,dp));
        }
        
        return dp[i][j]=m[i][j]+ans;
    
    }    
    
    
    int minFallingPathSum(vector<vector<int>>& m) {
         int n = m.size();
        
        int ans=INT_MAX;
        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        for(int j=0;j<n;j++)
        {
            ans = min(ans,solve(0,j,m,dp));
        }
        return ans;
    }
};