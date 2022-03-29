class Solution {
public:
    
    int solve(int i,int n,vector<int> &sq, vector<vector<int>> &dp )
    {
        if(n==0)
            return 0;
        if(i==0)
        {
            return n;
        }
        
        if(dp[i][n]!=-1)
            return dp[i][n];
        
        int notTake = solve(i-1,n,sq,dp);
        int take = 1e9;
        if(sq[i]<=n)
        {
            take = 1+solve(i,n-sq[i],sq,dp);
        }
        
        return dp[i][n] = min(notTake,take);
        
    }
    
    
    int numSquares(int n) {
        
        vector<int> sq;
        int i=0;
        while(i*i<=n)
        {
            sq.push_back(i*i);
            i++;
        }
                
        int sz = sq.size();
        
        vector<vector<int>> dp(sz,vector<int> (n+1,-1) );
        
        return solve(sz-1,n,sq,dp);
        
        
    }
};