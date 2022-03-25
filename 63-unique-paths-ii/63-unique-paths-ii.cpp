class Solution {
public:
    
//     int solve(int i,int j,vector<vector<int>> &g,vector<vector<int>> &dp)
//     {
//         if(g[i][j]==1)
//             return 0;
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         if(i==0 && j==0)
//             return 1;
//         if(i<0 || j<0)
//             return 0;
        
//         int up = i-1>=0 ? solve(i-1,j,g,dp):0;
//         int left = j-1>=0 ? solve(i,j-1,g,dp):0;
//         dp[i][j]= up+left;
//         return dp[i][j];
        
//     }
    
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        
        int m = g.size();
        int n = g[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        if(g[0][0]==1)
            return 0;
        else{
            dp[0][0]=1;
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    continue;
                if(g[i][j]==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                    
                int up = i-1>=0 ? dp[i-1][j]:0;
                int left = j-1>=0 ? dp[i][j-1]:0;
                dp[i][j] = up+left;               
                
            }
        }
        
        
        return dp[m-1][n-1];
    }
};