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
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        // int n = triangle[m-1].size();
        
        vector<vector<int>> dp (n,vector<int> (n,INT_MAX));
        
        return solve(0,0,triangle,dp);

        
    }
};