class Solution {
public:
    
    //memoization with right shift of index
    int solve(int i,int j,string &s1, string &s2,  vector<vector<int>> &dp)
    {
        if(i==0 || j==0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        //matching
        if(s1[i-1]==s2[j-1])
            return dp[i][j] = 1+solve(i-1,j-1,s1,s2,dp);
        
        return dp[i][j] = max(solve(i-1,j,s1,s2,dp) , solve(i,j-1,s1,s2,dp));
            
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = 0;
        }
        
        for(int j=0;j<m+1;j++)
        {
            dp[0][j]=0;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                
                //matching
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
                
            }
        }
        
        return dp[n][m];
        
        // return solve(n,m,text1,text2,dp);
                
        
    }
};