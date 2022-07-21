class Solution {
public:
    
    int solve(string &s1,string &s2, int i,int j,vector<vector<int>>& dp)
    {
        //base case
        //s1 is exhausted
        if(i<0)
            return j+1;
        
        //s2 exhausted
        if(j<0)
            return i+1;
            
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        //rec
        
        if(s1[i]==s2[j]) return dp[i][j] =  0+solve(s1,s2,i-1,j-1,dp);
        
        int ins = 1 + solve(s1,s2,i,j-1,dp);
        int del = 1 + solve(s1,s2,i-1,j,dp);
        int rep = 1 + solve(s1,s2,i-1,j-1,dp);
        
        return dp[i][j] = min(ins,min(del,rep));
        
    }
    
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        // vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        // return solve(word1,word2,n-1,m-1,dp);
        
        //tabulation
        //NOTE -> 1-based indexing
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
//         //base case
//         for(int i=0;i<=n;i++)
//             dp[i][0] = i;
//         for(int j=0;j<=m;j++)
//             dp[0][j] = j;
        
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=m;j++)
//             {
                
//                 if(word1[i-1]==word2[j-1]) dp[i][j] =  0+dp[i-1][j-1];
//                 else
//                 {
//                     int ins = 1+dp[i][j-1];
//                     int del = 1 + dp[i-1][j];
//                     int rep = 1 + dp[i-1][j-1];
        
//                     dp[i][j] = min(ins,min(del,rep));
//                 }
                 
//             }
//         }
//         return dp[n][m];
            
        
            vector<int> prev(m+1,0) , cur(m+1,0);
        
            for(int j=0;j<=m;j++)
                prev[j]=j;
        
            for(int i=1;i<=n;i++)
        {   
                cur[0]=i;
            for(int j=1;j<=m;j++)
            {
                
                if(word1[i-1]==word2[j-1]) cur[j] =  0+prev[j-1];
                else
                {
                    int ins = 1+ cur[j-1];
                    int del = 1 + prev[j];
                    int rep = 1 + prev[j-1];
        
                    cur[j] = min(ins,min(del,rep));
                }
                 
            }
                prev=cur;
        }
        return prev[m];
        
    }
};