class Solution {
public:
    
//     int solve(int i,int j , vector<vector<int>> &grid,vector<vector<int>> &dp)
//     {
//         if(i==0 && j==0)
//             return dp[i][j]=grid[0][0];
//         if(i<0 || j<0)
//             return INT_MAX;
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         int up = solve(i-1,j,grid,dp);
//         int left = solve(i,j-1,grid,dp);
        
//         dp[i][j] = grid[i][j] + min(up,left);
//         return dp[i][j];
        
//     }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n= grid[0].size();
        
        vector<vector<int>> dp(m,vector<int> (n,INT_MAX));
        
        // solve(m-1,n-1,grid,dp);
        
        dp[0][0]=grid[0][0];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    continue;
                int up = i-1>=0? dp[i-1][j]:INT_MAX;
                int left = j-1>=0? dp[i][j-1]:INT_MAX;
                
                dp[i][j] = grid[i][j] + min(up,left);
                
            }
        }
        
        
        return dp[m-1][n-1];
        
        
    }
};