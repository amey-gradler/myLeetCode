class Solution {
public:
    
    bool solve(string s1,string s2,string s3,int i,int j,int n,vector<vector<int>>&dp)
    {
        if(i<0 && j<0 && n<0)
            return true;
        if(i>=0 && j>=0 && dp[i][j]!=-1) return dp[i][j];
        
        bool ans=false;
        if( (i>=0 && s1[i]==s3[n]) && (j>=0 && s2[j]==s3[n]) )
        {
            return dp[i][j]=solve(s1,s2,s3,i-1,j,n-1,dp) || solve(s1,s2,s3,i,j-1,n-1,dp);
        }
        else if(i>=0 && s1[i]==s3[n])
        {
            return solve(s1,s2,s3,i-1,j,n-1,dp);
        }
        else if(j>=0 && s2[j]==s3[n])
        {
            return solve(s1,s2,s3,i,j-1,n-1,dp);
        }
        
        return false;
        
    }
    
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s3.length()!=s1.length()+s2.length()) return false;
        
        int len1=s1.length();
        int len2=s2.length();
        
        vector<vector<int>> dp(len1,vector<int>(len2,-1));
        
        return solve(s1,s2,s3,s1.length()-1,s2.length()-1,s3.length()-1,dp);    
            
        
    }
};