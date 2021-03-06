class Solution {
public:
    
    int f(int i,int j, string &s,string &t,vector<vector<int>> &dp)
    {
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(i<j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==t[j])
            return dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
        
        return dp[i][j] = f(i-1,j,s,t,dp);
        
    }
    
    
    
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        
        // return f(n-1,m-1,s,t,dp);
        
        // vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        
//         for(int i=0;i<n+1;i++)
//         {
//             for(int j=0;j<m+1;j++)
//             {
//                 if(i==0)
//                     dp[i][j] = 0;
//                 if(j==0)
//                     dp[i][j]=1;
//             }
//         }
        
        
//         for(int i=1;i<n+1;i++)
//         {
//             for(int j=1;j<m+1;j++)
//             {
//                 if(s[i-1]==t[j-1])
//                 {
//                     dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
//                 }
//                 else{
//                     dp[i][j] = dp[i-1][j];
//                 }    
            
//             }
//         }
        
//         return (int)dp[n][m];        
        
            vector<double> prev(m+1,0) , curr(m+1,0);
            prev[0]=curr[0] = 1;
        
            for(int i=1;i<n+1;i++)
            {
                for(int j=1;j<m+1;j++)
                {
                    if(s[i-1]==t[j-1])
                    {
                        curr[j] = prev[j-1]+prev[j];
                    }
                    else{
                        curr[j] = prev[j];
                    }    

                }
                prev=curr;
            }
        
            return (int)prev[m];    
        
    }
};