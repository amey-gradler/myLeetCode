class Solution {
public:
    
    int solve(int n,vector<int>& dp)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        
        if(dp[n]!=0)
            return dp[n];
        if(n&1)
        {
            dp[n] = 1+solve(n/2,dp);
            return dp[n];
        }
        else
        {
            dp[n]=solve(n/2,dp);
            return dp[n];
        }
        return 0;
        
    }
    
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        if(n==0)
            return ans;
        // ans[1]=1;
        // for(int i=0;i<=n;i++)
        // {
        //         ans[i]= (solve(i,ans));
        // }
        
        ans[0]=0;
        ans[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)
            {
                ans[i]=ans[i/2];
            }
            else{
                ans[i] = 1 + ans[i/2];
            }
        }
        
        return ans;
    }
};