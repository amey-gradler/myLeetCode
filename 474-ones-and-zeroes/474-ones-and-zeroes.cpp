class Solution {
public:
    
    int solve(int i,int m,int n,vector<int> &zeroes,vector<int> &ones,        vector<vector<vector<int>>> &dp)
    {
        if(i<0)
            return 0;
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        int z = zeroes[i];
        int o = ones[i];
        
        int notTake = solve(i-1,m,n,zeroes,ones,dp);
        
        int take=0;
        if(z<=m && o<=n)
        {
            take = 1+ solve(i-1,m-z,n-o,zeroes,ones,dp);
        }
        
        return dp[i][m][n] =max(notTake,take);
        
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<int> zeroes,ones;
        int sz = strs.size();
        for(int i=0;i<sz;i++)
        {
            int z=0;
            int o=0;
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='0')
                    z++;
                else
                    o++;
            }
            
            zeroes.push_back(z);
            ones.push_back(o);
        }
        
        vector<vector<vector<int>>> dp(sz,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        
        return solve(sz-1,m,n,zeroes,ones,dp);
        
        
    }
};