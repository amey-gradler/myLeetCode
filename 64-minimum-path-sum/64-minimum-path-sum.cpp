class Solution {
public:
    
    int solve(int i,int j , vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(i==0 && j==0)
            return dp[i][j]=grid[0][0];
        if(i<0 || j<0)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up = solve(i-1,j,grid,dp);
        int left = solve(i,j-1,grid,dp);
        
        dp[i][j] = grid[i][j] + min(up,left);
        return dp[i][j];
        
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n= grid[0].size();
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        solve(m-1,n-1,grid,dp);
        
        return dp[m-1][n-1];
        
        
    }
};