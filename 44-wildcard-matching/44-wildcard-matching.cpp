class Solution {
public:
    
    bool solve(string &p,string &s , int i,int j,vector<vector<int>> &dp)
    {
        //base case
        if(i<0)
        {
            if(j<0)
                return true;
            return false;
        }
        
        if(j<0)
        {
            if(i>=0)
            {
                for(int ii=0;ii<=i;ii++)
                {
                    if(p[ii]!='*') return false;
                }
                return true;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        
        //rec
        
        if(p[i]==s[j] || p[i]=='?')
            return dp[i][j] = solve(p,s,i-1,j-1,dp);
        
        if(p[i]=='*')
            return dp[i][j] = solve(p,s,i-1,j,dp) || solve(p,s,i,j-1,dp);
        
        return false;
        
    }
    
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return solve(p,s,n-1,m-1,dp);
        
    }
};