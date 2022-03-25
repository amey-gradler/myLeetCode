class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>> &t, vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
            return INT_MAX;
        cout<<t[i][j]<<" ";
        if(i==0 && j==0)
            return t[i][j];
  
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        
        // i-1,j
        int ans1=INT_MAX;
        if(i>0 && j<t[i-1].size())
        {
            ans1 = solve(i-1,j,t,dp);   
        }
            
        int ans2 = INT_MAX;
        if(i>0 && j-1>=0 && j-1<t[i-1].size())
        {
            ans2 = solve(i-1,j-1,t,dp);
        }
        
        if(min(ans1,ans2)==INT_MAX)
            return dp[i][j]=INT_MAX;
        
        dp[i][j] = t[i][j] + min(ans1,ans2);
        return dp[i][j];
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[m-1].size();
        
        vector<vector<int>> dp (m,vector<int> (n,INT_MAX));
        
        int ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            ans = min(ans,solve(m-1,j,triangle,dp));
            cout<<endl;
        }
        
        return ans;
        
    }
};