class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>> &m,vector<vector<int>> &dp)
    {
        if(i==m.size()-1)
            return m[i][j];
        
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        
        int down=INT_MAX,ld=INT_MAX,rd=INT_MAX;
        
        //down
        down = m[i][j] + solve(i+1,j,m,dp);
        
        //ld
        if(j>0)
        {
            ld = m[i][j]+solve(i+1,j-1,m,dp);
        }
        
        if(j<m.size()-1)
        {
            rd = m[i][j] + solve(i+1,j+1,m,dp);
        }
        
        return dp[i][j]=min(down,min(ld,rd));
    
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        int ans=INT_MAX;
        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        for(int j=0;j<n;j++)
        {
            ans = min(ans,solve(0,j,matrix,dp));
        }
        return ans;
        
    }
};