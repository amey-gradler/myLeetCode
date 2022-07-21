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
        
        if(s1[i]==s2[j]) return 0+solve(s1,s2,i-1,j-1,dp);
        
        int ins = 1 + solve(s1,s2,i,j-1,dp);
        int del = 1 + solve(s1,s2,i-1,j,dp);
        int rep = 1 + solve(s1,s2,i-1,j-1,dp);
        
        return dp[i][j] = min(ins,min(del,rep));
        
    }
    
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        return solve(word1,word2,n-1,m-1,dp);
        
    }
};