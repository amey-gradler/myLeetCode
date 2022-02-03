class Solution {
public:
    
    vector<vector<int>>dp;
    int m;
    int n;
    
    
    
    int solve(int i, int j , vector<vector<int>>& matrix,int prev)
    {
        if(i<0 || j<0 || i>=m ||j>=n || matrix[i][j]<=prev)
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        
        int a = solve(i-1,j,matrix, matrix[i][j]);
        int b= solve(i+1,j,matrix,matrix[i][j]);
        int c = solve(i,j+1,matrix,matrix[i][j]) ;
        int d = solve(i,j-1,matrix,matrix[i][j]);
        
        return dp[i][j] = 1+max(a,max(b,max(c,d)));
        
        // return dp[i][j];
        
    }
    
    
    
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        m = matrix.size();
        n=matrix[0].size();
        dp.resize(m, vector<int>(n,-1));
        int maxPath=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                maxPath = max(maxPath,solve(i,j,matrix,-1));
            }
        }
        
        return maxPath;
        
    }
};